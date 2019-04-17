### Proto Buffer

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8293993c1ae54528aadacc58352d6cb7)](https://app.codacy.com/app/Sphinxs/Proto-buffer?utm_source=github.com&utm_medium=referral&utm_content=Sphinxs/Proto-buffer&utm_campaign=Badge_Grade_Dashboard)

Document share application written in C++.

#### Setup

- Docker

Install the [Docker](https://docs.docker.com/install/) and [Docker Compose](https://docs.docker.com/compose/install/).

Clone and open this repository:

```sh
git clone https://github.com/Sphinxs/Proto-buffer
```

```sh
cd Proto-buffer
```

Create all containers:

```sh
docker-compose up
```

Available containers:

| name    | description    |
| ------- | -------------- |
| mongo-c | mongo database |

- Compiler

GCC and G++ are used to compile this application and CMake its used to compile the libraries. Pkg it's a dependency to generate the includes and libraries on [Makefile](./Makefile).

```sh
apt install build-essential pkg-config gcc g++ cmake
```

- Mongo driver

The Mongo CXX its the Mongo driver for C++. The Mongo CXX driver builds on top of the Mongo C driver.

> If incompatible versions of Mongo C (and its dependencies) and Mongo CXX are installed, it can cause conflicts on the compilation of Mongo CXX. Find the compatible versions [here](http://mongocxx.org/mongocxx-v3/installation/)

1. Install the Mongo C driver

Get the driver from [Github](https://github.com/mongodb/mongo-c-driver/releases):

```sh
wget -c https://github.com/mongodb/mongo-c-driver/archive/1.13.0.zip
```

Unzip the driver, create the *cmake-build* required subfolder and open the the subfolder *cmake-build*:

```sh
unzip 1.13.0.zip
```

```sh
mkdir ./mongo-c-driver-1.13.0/cmake-build
```

```sh
cd ./mongo-c-driver-1.13.0/cmake-build
```

Install the dependencies (OpenSSL is required for authentication or for SSL connections to MongoDB and Kerberos or LDAP support requires Cyrus SASL):

```sh
apt install libssl-dev libsasl2-dev
```

Compile the driver:

```sh
cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
```

Install the compiled driver:

```sh
make
```

```sh
sudo make install
```

To remove:

```sh
sudo /usr/local/share/mongo-c-driver/uninstall.sh
```

2. Instal the Mongo CXX driver

Get the driver from [Github](https://github.com/mongodb/mongo-cxx-driver/releases):

```sh
wget -c https://github.com/mongodb/mongo-cxx-driver/archive/r3.3.0.zip
```

Unzip the driver and open the build folder:

```sh
unzip r3.3.0.zip
```

```sh
cd mongo-cxx-driver-r3.3.0/build
```

Configure the driver:

On Unix systems, `libmongoc` installs into */usr/local* by default. The source code its on */usr/local/include* and the libraries are on */usr/local/lib*. To configure `mongocxx` for installation into */usr/local* as well, use the following CMake command:

```sh
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
```

```sh
sudo make EP_mnmlstc_core
```

Compile and install the driver:

```sh
sudo make && sudo make install
```