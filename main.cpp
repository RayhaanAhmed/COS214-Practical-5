#include <iostream>
#include <memory>
#include <string>
#include "AccessControlSystem.h"
#include "ActivateAlertCommand.h"
#include "BackupRequestDecorator.h"
#include "CancelActionCommand.h"
#include "DispatchUnitCommand.h"
#include "EmergencyResponseFacade.h"
#include "FacilitiesTeam.h"
#include "Incident.h"
#include "IncidentCoordinator.h"
#include "LockdownAreaCommand.h"
#include "MedicalTeam.h"
#include "OperatorConsole.h"
#include "SecurityTeam.h"
#include "SimpleAlert.h"
#include "SirenTower.h"
#include "SirenTowerAdapter.h"
#include "StandardDispatch.h"
#include "UrgentDispatchDecorator.h"

static void banner(const std::string& title) {
    std::cout << "\n" << title << "\n" << std::endl;
}

int main() {
    std::cout << "CampusGuard Emergency Response" << std::endl;

    // Campus infrastructure
    // Everything lives on the stack: destruction happens automatically in reverse order,
    // so no manual delete calls. The only heap objects are Commands (owned by the console)
    // and DispatchOrder chains (owned by the DispatchUnitCommand that receives them).
    SecurityTeam security("Campus Security Alpha");
    MedicalTeam medical("MedResponse Unit 1");
    FacilitiesTeam facilities("Facilities Crew 3");
    AccessControlSystem access("Campus Access Control");
    IncidentCoordinator mediator(&security, &medical, &facilities, &access); //Mediator: wires itself into every colleague

    SirenTower legacySiren;// Adaptee: legacy vendor system (zone code + seconds)
    SirenTowerAdapter sirenChannel(&legacySiren); // Adapter: AlertChannel::send(message) -> soundSiren(zone, secs)
    SimpleAlert simpleAlert;// a modern channel, no adapter needed

    OperatorConsole console;// Invoker
    EmergencyResponseFacade facade(&console, &access, &sirenChannel);

    // Scenario 1 - Fire in the library, driven by the Facade
    // Patterns in one flow: Facade, Command, Decorator, Mediator, Adapter, State

    std::cout << "--------------------------------------"<<std::endl;
    banner("SCENARIO 1: Fire in Main Library (Facade)");

    Incident fire("INC-001", "Fire", "Main Library", 8);

    // Decorator chain: Backup( Urgent( Standard(security) ) )
    std::unique_ptr<DispatchOrder> standard(new StandardDispatch(&security));
    std::unique_ptr<DispatchOrder> urgent(new UrgentDispatchDecorator(std::move(standard)));
    std::unique_ptr<DispatchOrder> fullOrder(new BackupRequestDecorator(std::move(urgent)));

    // Ownership of the chain passes to the DispatchUnitCommand the facade creates
    facade.reportEmergency(&fire, fullOrder.release(), "Fire evacuation : Main Library");

    std::cout << "\nSiren already sounded via the Adapter. Advancing INC-001 to the end of its lifecycle:" << std::endl;
    fire.advance();   // InProgress -> Escalated
    fire.advance();   // Escalated  -> Resolved
    fire.advance();   // Resolved: invalid operation, reported rather than ignored
    std::cout << "INC-001 final status: " << fire.getStatusName() << std::endl;

    // Scenario 2 - Medical emergency, driven manually through the OperatorConsole
    // Patterns in one flow: Command (4 concrete commands), Mediator, State, Decorator
    // Shows the subsystems remain usable without the Facade.

    std::cout << "--------------------------------------"<<std::endl;
    banner("SCENARIO 2: Medical Emergency in Residence (Operator Console)");

    Incident medEmergency("INC-002", "Medical", "Residence Block C", 6);
    std::cout << "Reported " << medEmergency.getId() << " at " << medEmergency.getLocation() << " - status: " << medEmergency.getStatusName() << std::endl;

    // 1. Dispatch with an urgent order -> security responds -> mediator -> medical + facilities -> access control
    std::cout << "\nOperator: dispatch unit" << std::endl;
    std::unique_ptr<DispatchOrder> base2(new StandardDispatch(&security));
    std::unique_ptr<DispatchOrder> urgent2(new UrgentDispatchDecorator(std::move(base2)));
    Command* dispatchCmd = console.submit(new DispatchUnitCommand(urgent2.release(), &medEmergency));
    medEmergency.advance(); // Reported -> Dispatched

    // 2. Lock down an additional area
    std::cout << "\nOperator: lock down the car park" << std::endl;
    Command* lockCmd = console.submit(new LockdownAreaCommand(&access, "Residence Block C Car Park"));

    // 3. Alert on a modern channel
    std::cout << "\nOperator: activate alert (simple channel)" << std::endl;
    console.submit(new ActivateAlertCommand(&simpleAlert, "Medical emergency - Residence Block C"));

    // 4. Cancel the car-park lockdown: allowed, incident is still Dispatched
    std::cout << "\nOperator: cancel car-park lockdown (incident is " << medEmergency.getStatusName() << ")" << std::endl;
    console.submit(new CancelActionCommand(&medEmergency, lockCmd));

    // 5. Once the response is in progress, cancelling is refused by the State
    medEmergency.advance(); // Dispatched -> InProgress
    std::cout << "\nOperator: cancel dispatch (incident is " << medEmergency.getStatusName() << ")" << std::endl;
    console.submit(new CancelActionCommand(&medEmergency, dispatchCmd));

    // 6. Invalid operation: locking an area that is already locked
    std::cout << "\nOperator: lock down an already-locked area" << std::endl;
    console.submit(new LockdownAreaCommand(&access, "Residence Block C"));

    // 7. Invalid operation at the mediator: a component with no backup route asks for backup
    std::cout << "\nMedical unit requests backup through the mediator" << std::endl;
    mediator.requestBackup(&medical, &medEmergency);

    std::cout << "\nFinal status: " << fire.getId() << " = " << fire.getStatusName() << ", "<< medEmergency.getId() << " = " << medEmergency.getStatusName() << std::endl;
    std::cout << "\nCampusGuard shutdown complete." << std::endl;
    return 0;
}
