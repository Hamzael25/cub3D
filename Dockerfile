# Dockerfile
FROM ubuntu:22.04

# Install packages
RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    libx11-dev \
    libxext-dev \
    libbsd-dev \
    make \
    git \
    vim \
	docker \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /cub3d

CMD ["/bin/bash"]
