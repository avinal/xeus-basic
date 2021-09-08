FROM ubuntu:latest

USER root
WORKDIR /xbasic
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
      git \
      wget \
      cmake \
      make \
      g++ \
&& rm -rf /var/lib/apt/lists/*

ENV PATH="/xbasic/miniconda3/bin:${PATH}"
ARG PATH="/xbasic/miniconda3/bin:${PATH}"
RUN wget --no-check-certificate \
    https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh \
    && mkdir /xbasic/.conda \
    && bash Miniconda3-latest-Linux-x86_64.sh -b -p /xbasic/miniconda3 \
    && rm -f Miniconda3-latest-Linux-x86_64.sh 

RUN conda install -c conda-forge jupyter xeus xtl nlohmann_json cppzmq -y && conda init
