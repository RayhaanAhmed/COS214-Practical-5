# COS214-Practical-5

# 1. Build the image and run the app
docker compose up --build

# 2. Stop and remove the container when done
docker compose down

# 3. (optional) Run Valgrind inside the container
docker compose run --rm campusguard make valgrind

# 4. (optional) Run GDB inside the container
docker compose run --rm campusguard gdb ./campusguard
