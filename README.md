### Proto Buffer

Proto Buffer is a C++ application that allows document sharing.

#### Setup

- Docker

Install the [Docker](https://docs.docker.com/install/) and [Docker Compose](https://docs.docker.com/compose/install/) tools, following the official documentation.

- Mongo

Clone and open this repository:

```sh
git clone https://github.com/Sphinxs/Proto-buffer
```

```sh
cd Proto-buffer
```

Create a container (*mongo-database*) based on [Mongo](https://hub.docker.com/_/mongo) image:

```sh
docker-compose up
```

Start the container:

```sh
docker start mongo-database
```

Inspect the container' configuration:

```sh
docker inspect mongo-database
```

Get the container' logs:

```sh
docker logs mongo-database
```

Execute a command inside the container:

```sh
docker exec -it mongo-database bash
```