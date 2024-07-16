FROM ubuntu:latest

# non-interactive
ENV DEBIAN_FRONTEND=non-interactive

# Update package list and install essential packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    llvm-11 llvm-11-dev \
    clang \
    cmake \
    git \
    wget \
    unzip \
    pkg-config \
    nasm \
    libhiredis-dev \
    libasio-dev \
    curl \
    nginx

# Clean up to reduce image size
RUN   apt-get autoremove -y && \
      apt-get clean && \
      rm -rf /var/lib/apt/lists/*

# Install Crow
RUN wget -O CrowCpp.zip https://github.com/CrowCpp/Crow/archive/refs/heads/master.zip && \
    unzip CrowCpp.zip && \
    cd Crow-master && \
    mkdir build && \
    cd build && \
    cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF && \
    make && \
    make install && \
    cd ../../ && \
    rm -rf CrowCpp.zip Crow-master

# Install redis-plus-plus
RUN wget -O redis-plus-plus.zip https://github.com/sewenew/redis-plus-plus/archive/refs/heads/master.zip && \
    unzip redis-plus-plus.zip && \
    cd redis-plus-plus-master && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    cd ../../ && \
    rm -rf redis-plus-plus.zip redis-plus-plus-master

# Install csv2
RUN git clone https://github.com/p-ranav/csv2.git /usr/src/csv2 && \
    cd /usr/src/csv2 && \
    cmake -S . -B build -DCSV2_BUILD_TESTS=OFF && \
    cmake --install build && \
    rm -rf /usr/src/csv2

# Install nlohmann/json
RUN git clone https://github.com/nlohmann/json.git /usr/src/nlohmann_json && \
    cd /usr/src/nlohmann_json && \
    cmake -S . -B build -DBUILD_TESTING=OFF && \
    cmake --install build && \
    rm -rf /usr/src/nlohmann_json
    # cmake --build build --target install

# Install google-test
RUN wget -O google-test.zip https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip && \
    unzip google-test.zip && \
    cd googletest-* && \
    mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    make install && \
    cd ../../ && \
    rm -rf google-test.zip googletest-*

# Reset non-interactive
ENV DEBIAN_FRONTEND=

# Set the working directory
WORKDIR /workspace

# Set the default command
CMD ["bash"]

# Instructions to build and run the container without docker network
# docker build -t llvm_redispp_crow .
# docker run -it -v /home/h_server/rsync_async/Dockerfolder/host/share/:/workspace --name cont_llvm_redispp_crow llvm_redispp_crow