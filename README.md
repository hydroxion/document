### 💀 Proto Buffer

---

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/8293993c1ae54528aadacc58352d6cb7)](https://app.codacy.com/app/Sphinxs/Proto-buffer?utm_source=github.com&utm_medium=referral&utm_content=Sphinxs/Proto-buffer&utm_campaign=Badge_Grade_Dashboard) [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com)  ![GitHub last commit (branch)](https://img.shields.io/github/last-commit/sphinxs/proto-buffer/dev.svg) [![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-v1.4%20adopted-ff69b4.svg)]([code-of-conduct.md](https://www.contributor-covenant.org/version/1/4/code-of-conduct))

---

Document share application written in C++. More details in the [presentation](documentation/presentation.pdf).

#### Setup

<details> <summary><strong>Docker</strong></summary>

Install the [Docker](https://docs.docker.com/install/) and [Docker Compose](https://docs.docker.com/compose/install/).

```sh
# Clone the repository
$ git clone https://github.com/Sphinxs/Proto-buffer --depth=1
```

```sh
# Open the repository
$ cd Proto-buffer
```

```sh
# Create all containers listed in the Docker Compose file
$ sudo docker-compose up
```

<details> <summary><strong>Available containers</strong></summary>

| name            | description    |
| --------------- | -------------- |
| mongo-container | mongo database |
| code-container  | code source    |

</details> <!-- Available containers -->

</details> <!-- Docker -->

<details> <summary><strong>Compiler</strong></summary>

```sh
# Install the Build Essential, GCC, G++, CMake and PKG
$ apt install build-essential pkg-config gcc g++ cmake
```

</details> <!-- Compiler -->

<details> <summary><strong>Mongo driver</strong></summary>

The Mongo CXX is the Mongo driver for the C++ language. The Mongo CXX driver builds on top of the Mongo C driver, the Mongo driver for the C language.

If incompatible versions of Mongo C / Mongo CXX are installed, conflicts can happen. The Mongo C version compiled here is the 1.13.0 and the Mongo CXX version is the 3.3.0

The code of both libraries can be found in */usr/local/include* and the shared libraries in */usr/local/lib*.

You can also install throught the available shell script [here](./install.sh), run as `sudo`.

<details> <summary><strong>Mongo C</strong></summary>

<details> <summary><strong>Install</strong></summary>

```sh
# Get the driver from Github
$ wget -c https://github.com/mongodb/mongo-c-driver/archive/1.13.0.zip
```

```sh
# Unzip the driver
$ unzip 1.13.0.zip
```

```sh
# Create the cmake-build required subfolder
$ mkdir ./mongo-c-driver-1.13.0/cmake-build
```

```sh
# Open the subfolder cmake-build
$ cd ./mongo-c-driver-1.13.0/cmake-build
```

```sh
# Install the dependencies
$ apt install libssl-dev libsasl2-dev
```

```sh
# Configure driver installation
$ cmake -DENABLE_AUTOMATIC_INIT_AND_CLEANUP=OFF ..
```

```sh
# Compile the driver
$ make
```

```sh
# Install the compiled driver
$ sudo make install
```

</details> <!-- Install-->

<details> <summary><strong>Remove</strong></summary>

```sh
# Remove the Mongo C driver
$ sudo /usr/local/share/mongo-c-driver/uninstall.sh
```

</details> <!-- Remove -->

</details> <!-- Mongo C -->

<details> <summary><strong>Mongo CXX</strong></summary>

<details> <summary><strong>Install</strong></summary>

```sh
# Get the driver from Github
$ wget -c https://github.com/mongodb/mongo-cxx-driver/archive/r3.3.0.zip
```

```sh
# Unzip the driver
$ unzip r3.3.0.zip
```

```sh
# Open the build subfolder
$ cd mongo-cxx-driver-r3.3.0/build
```

```sh
# Configure the driver for installation into /usr/local
$ cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=/usr/local ..
```

```sh
# Apply the configuration
$ sudo make EP_mnmlstc_core
```

```sh
# Compile the driver
$ sudo make
```

```sh
# Install the driver
$ sudo make install
```

</details> <!-- Install -->

</details> <!-- Mongo CXX -->

</details> <!-- Mongo driver -->

#### License

The license can be find [here](LICENSE).

#### Contribute

Project [board](https://github.com/Sphinxs/Proto-buffer/projects/1).