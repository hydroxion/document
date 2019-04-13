### Proto Buffer

Document share application written in C++

#### Setup

- Docker

Install the [Docker](https://docs.docker.com/install/) and [Docker Compose](https://docs.docker.com/compose/install/) tools, following the official documentation

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


Start a container (change the container name):

```sh
docker start name
```

Inspect a container (change the container name):

```sh
docker inspect name 
```

Get logs from a container (change the container name):

```sh
docker logs -f name
```

- Compiler

```sh
apt install build-essential gcc g++ # clang
```

- CMake

Intall the CMake:

```sh
apt install cmake
```

Open this repository and compile the code on [build](./build) folder:

```sh
cd Proto-buffer
```

```sh
cmake -B./build -H. # target folder / source code
```