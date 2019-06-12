FROM debian:stretch

RUN mkdir -p /code

WORKDIR /code

VOLUME . /code

RUN ./install.sh