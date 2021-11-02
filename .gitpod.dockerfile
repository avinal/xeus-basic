# SPDX-License-Identifier: Apache-2.0
# SPDX-FileCopyrightText: 2021 Avinal Kumar <avinal.xlvii@gmail.com>

FROM gitpod/workspace-full:latest

USER root
ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
 && apt-get install -y --no-install-recommends \
      git \
      wget \
      cmake \
      make \
      g++ \
      ninja-build \
&& rm -rf /var/lib/apt/lists/*

USER gitpod
RUN wget --no-check-certificate \
    https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh \
    && bash Miniconda3-latest-Linux-x86_64.sh -b \
    && rm -f Miniconda3-latest-Linux-x86_64.sh 

ENV PATH=$PATH:$HOME/miniconda3
ENV PATH=$PATH:$HOME/miniconda3/bin

RUN conda install -c conda-forge jupyter xeus xtl nlohmann_json cppzmq -y
RUN conda init

