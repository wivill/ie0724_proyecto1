
###########################################################################
#                                                                  BUILDER
###########################################################################

# Imagen base ubuntu 18.04
FROM ubuntu:20.04 as builder

# Mantainer
LABEL maintainer="José López Picado"
LABEL email="joselp1695@gmail.com"

ENV DEBIAN_FRONTEND=noninteractive

# Instalación de paquetes, se omiten la instalación de paquetes
# recomendados y se elimina la cache de apt
RUN apt update && apt install -y  --no-install-recommends  \
        build-essential \
        make \
        cmake \
        libgtest-dev \
    && rm -rf /var/lib/apt/lists/*

#Compilación de gtest y creación de enlaces simbolicos a las bibliotecas
RUN cd /usr/src/gtest \
    && cmake CMakeLists.txt \
    && make \
    && cd lib \
    && cp *.a /usr/lib \
    && mkdir /usr/local/lib/gtest \
    && ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a \
    && ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a 

WORKDIR /app

# Se copia el proyecto en /app
COPY . /app

# Se compila el proyecto usando cmake
RUN mkdir build \
    && cd build \
    && cmake .. \
    && make

###########################################################################
#                                                                    IMAGE
###########################################################################

FROM ubuntu:20.04
WORKDIR /usr/bin/

# Se copia el ejecutable de la imagen builder
COPY --from=builder /app/build/test/test  /usr/bin/run_unittest 

CMD [ "./run_unittest " ]