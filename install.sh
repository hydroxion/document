#!/bin/bash
mkdir ~/.proto-buffer

# mongo c
cd ~/.proto-buffer

wget -c https://github.com/mongodb/mongo-c-driver/archive/1.13.0.zip

unzip 1.13.0.zip

mkdir ./mongo-c-driver-1.13.0/cmake-build

cd ./mongo-c-driver-1.13.0/cmake-build

apt install libssl-dev libsasl2-dev

cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..

make

make install

# mongo cxx
cd ~/.proto-buffer

wget -c https://github.com/mongodb/mongo-cxx-driver/archive/r3.3.0.zip

unzip r3.3.0.zip

cd mongo-cxx-driver-r3.3.0/build

cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..

make EP_mnmlstc_core

make

make install

# clean
rm -rf ~/.proto-buffer