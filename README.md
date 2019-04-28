### Proto Buffer

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8293993c1ae54528aadacc58352d6cb7)](https://app.codacy.com/app/Sphinxs/Proto-buffer?utm_source=github.com&utm_medium=referral&utm_content=Sphinxs/Proto-buffer&utm_campaign=Badge_Grade_Dashboard) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)  ![GitHub last commit (branch)](https://img.shields.io/github/last-commit/sphinxs/proto-buffer/dev.svg) [![Maintainability](https://api.codeclimate.com/v1/badges/810a45adf67f8137c712/maintainability)](https://codeclimate.com/github/Sphinxs/Proto-buffer/maintainability)

---

Document share application written in C++. See more details in the [presentation](documentation/presentation.pdf).

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

Install GCC, G++, cmake and PKG via package manager:

```sh
apt install build-essential pkg-config gcc g++ cmake
```

- Mongo driver

The Mongo CXX its the Mongo driver for C++. The Mongo CXX driver builds on top of the Mongo C driver, the Mongo driver for C language. See all available [drivers](https://docs.mongodb.com/ecosystem/drivers/) and its versions.

> If incompatible versions of Mongo C (and its dependencies) and Mongo CXX are installed, it can cause conflicts in the Mongo CXX compilation. The Mongo C version used here its the 1.13.0 and the Mongo CXX version used here its the 3.3.0

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

Install the dependencies (OpenSSL is required for authentication or for SSL connections to Mongo and Kerberos or LDAP support requires Cyrus SASL):

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

To configure `mongocxx` for installation into */usr/local* as well, use the following two CMake commands:

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

3. Mongo C and Mongo CXX

The code of both libraries can be found on */usr/local/include* and the shared libraries on */usr/local/lib*.

#### License

The Proto Buffer license was created based on [MIT](https://choosealicense.com/licenses/mit/) license and on [Creative Commons 4.0](https://tldrlegal.com/license/creative-commons-attribution-noderivatives-4.0-international-(cc-by-nd-4.0)).

#### To Do

|                               Title
|   -------------------------------------------------------------   |
|   Create a board on Asana                                         |
|   Create UML diagrams                                             |
|   Create the user class                                           |
|   Create the document class                                       |
|   Create the archive class                                        |
|   Create a Docker image to the C++ code                           |
|   Document the development guide line                             |
|   Document how to contribute                                      |
|   Create tests to the code                                        |
|   Integrate the Circle CI to the repository                       |
|   Create the metric class                                         |
|   Create the comment class                                        |
|   Create a interface to desktop in C++                            |
|   Create a scrapper in Python to get documents to the platform    |
|   Apply a file compress algorithm to the documents                |
|   Change the Mongo to a P2P system                                |
|   Create a interface in Python to expose a Graph API              |
|   Create a front-end interface to the Graph API                   |
|   Apply cryptography / VPN or Proxy to everything                 |
|   Apply natural language process to process the documents         |