# ===============================================================================
# Dockerfile
#   Builds nycoin and the executable binary, "newyorkcd"
#
#
# It is based on Ubuntu 14.04 LTS
# ===============================================================================

# Set the base image to Ubuntu
FROM ubuntu:14.04

# File Author / Maintainer
MAINTAINER jmsds

# ===============================================================================
# Env. Setup
#

# Update repository
RUN apt-get update && apt-get -y upgrade

# ----------------------------------------------------------
# Dependencies
# ----------------------------------------------------------

# Basic Dependencies
#
RUN apt-get install -y git \
            ntp \
            unzip \
            build-essential \
            libssl-dev \
            libdb-dev \
            libdb++-dev \
            libboost-all-dev \
            libqrencode-dev \
            aptitude && aptitude install -y miniupnpc \
                                 libminiupnpc-dev

# ===============================================================================
# Set working directory
#
WORKDIR /work

# ===============================================================================
# Install configuration
#

RUN mkdir -p /root/.newyorkc/
COPY docker/config/newyorkc.conf /root/.newyorkc/
RUN chmod u+r-wx,g-rwx,o-rwx /root/.newyorkc/newyorkc.conf

# ===============================================================================
# System Initialization
#

## Copy folders
COPY share /work/share
COPY src /work/src

RUN cd src && \
    /usr/bin/make -f makefile.unix USE_UPNP=1 USE_IPV6=1 USE_QRCODE=1

# Set default CMD
CMD /work/src/newyorkcd && tail -f -n 10 /root/.newyorkc/debug.log

