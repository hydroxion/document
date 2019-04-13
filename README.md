### Proto Buffer

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

List all containers:

```sh
docker ps -a
```

Available containers:

| name    | description    |
| ------- | -------------- |
| mongo-c | mongo database |

Start a container (change the name):

```sh
docker start name
```

Inspect a container (change the name):

```sh
docker inspect name 
```

Get container' logs (change the name):

```sh
docker logs -f name
```

- Compiler

```sh
apt install build-essential gcc g++
```

- CMake

Intall the [CMake](https://cmake.org/download/):

```sh
apt install cmake
```

Open this repository and compile the code on [build](./build) folder:

```sh
cd Proto-buffer
```

```sh
cmake -B./build -H. # cd build & cmake ../. # target / source code
```

CMake [tutorial](https://www.jetbrains.com/help/clion/quick-cmake-tutorial.html). CMake [wiki](https://gitlab.kitware.com/cmake/community/wikis/FAQ).

- Mongo CXX

The Mongo CXX is the Mongo driver for the C++ language. The steps to install all dependencies and the actual driver are described below.

> If incompatible versions of Mongo C (and its dependencies) and Mongo CXX are installed, it can cause problems on the compilation of CXX. Look out

1. Install the [Mongo C](https://github.com/mongodb/mongo-c-driver) driver

The Mongo CXX driver builds on top of the Mongo C driver.

---

Install via package manager, along with BSON:

```sh
apt-get install libmongoc-1.0-0 libbson-1.0
```

To remove:

```sh
apt remove --purge libmongoc-1.0-0 libbson-1.0
```

---

Install manually, get the latest version on [Github](https://github.com/mongodb/mongo-c-driver/releases):

```sh
wget -c https://github.com/mongodb/mongo-c-driver/archive/1.13.0.zip
```

Unzip the driver, create the required subfolder and open the the subfolder:

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

2. Polyfill

If you need to build the Mongo CXX driver for C++ < 17 standard, then you need to configure a polyfill, read the [polyfill](http://mongocxx.org/mongocxx-v3/installation/#step-2-choose-a-c-17-polyfill) documentation section. If you use polyfill the build step needs additional intructions.

3. Get the Mongo CXX driver

Get the latest version of Mongo CXX on [Github](https://github.com/mongodb/mongo-cxx-driver/releases) and open the repository:

```sh
git clone https://github.com/mongodb/mongo-cxx-driver.git \
    --branch releases/stable --depth 1
```

```sh
cd mongo-cxx-driver/build
```

4. Configure the driver

On Unix systems, `libmongoc` installs into /usr/local by default. To configure `mongocxx` for installation into /usr/local as well, use the following CMake command:

```sh
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
```

5. Compile and install Mongo CXX

```sh
sudo make && sudo make install
```