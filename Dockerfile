FROM ubuntu:24.04

RUN apt-get update && \
    apt-get install -y --no-install-recommends build-essential make valgrind gdb && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY . .

# Build with the project Makefile (-std=c++11)
RUN make clean && make

CMD ["./campusguard"]