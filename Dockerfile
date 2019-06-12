FROM debian

RUN mkdir -p /code

WORKDIR /code

VOLUME . /code

RUN apt install wget unzip build-essential gcc g++ pkg cmake 

RUN ./install.sh