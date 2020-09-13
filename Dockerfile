
###########################################################################
#                                                                  BUILDER
###########################################################################

# Imagen base ubuntu 18.04
FROM ubuntu:20.04 as builder

# Mantainer
LABEL maintainer="José López Picado"
LABEL email="joselp1695@gmail.com"

ENV DEBIAN_FRONTEND=noninteractive

# Instalación de paquetes
RUN apt update && apt install -y  --no-install-recommends  \
        build-essential \
        make \
        cmake \
        libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

#Configuracion de gtest
RUN cd /usr/src/gtest \
    && cmake CMakeLists.txt \
    && make \
    && cd lib \
    && cp *.a /usr/lib \
    && mkdir /usr/local/lib/gtest \
    && ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a \
    && ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a 

WORKDIR /app

COPY . /app

RUN mkdir build \
    && cd build \
    && cmake .. \
    && make

###########################################################################
#                                                                    IMAGE
###########################################################################

FROM ubuntu:20.04

WORKDIR /app

COPY --from=builder /app/build/test/test /app 

CMD [ "./test" ]