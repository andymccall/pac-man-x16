FROM ubuntu:24.04
LABEL maintainer="Andy McCall <mailme@andymccall.co.uk>"
LABEL description="Pac-Man X16 Build Environment"
LABEL version="1.0"
LABEL org.opencontainers.image.authors="Andy McCall <mailme@andymccall.co.uk>"
LABEL org.opencontainers.image.description="Pac-Man X16 Build Environment"
LABEL org.opencontainers.image.source="https://github.com/andymccall/pac-man-x16"

RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    git \
    wget \
    sudo \
    gosu \
    make \
    && rm -rf /var/lib/apt/lists/*

# Install cc65 from source
RUN mkdir -p /opt/development && \
    cd /opt/development && \
    git clone https://github.com/cc65/cc65.git && \
    cd cc65 && \
    make && \
    make install PREFIX=/opt/tools/cc65 && \
    cd / && \
    rm -rf /opt/development

# Set up cc65 environment variables for all users
ENV PATH="/opt/tools/cc65/bin:${PATH}"
ENV CC65_HOME="/opt/tools/cc65/share/cc65"

CMD ["/bin/bash"]