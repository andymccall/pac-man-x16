# Pac-Man X16 Project Makefile
# Author: Andy McCall

# Project configuration
PROJECT_NAME := pac-man
DOCKER_IMAGE := $(PROJECT_NAME)-build
DOCKER_TAG := latest
DOCKER_REGISTRY := # Set this if you want to push to a registry

# Build configuration
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin
LST_DIR := $(BUILD_DIR)/lst
SRC_DIR := src
MAIN_SRC := $(SRC_DIR)/main.asm
OUTPUT_PRG := $(BIN_DIR)/$(shell echo '$(PROJECT_NAME)' | tr 'a-z' 'A-Z').PRG

# Build tools and flags
CL65 := cl65
CL65_FLAGS := -t cx16

# Version info
GIT_INFO := $(shell git describe --always --tags 2>/dev/null || echo "unknown")
BUILD_YEAR := $(shell date +'%Y')

# Docker configuration
DOCKER_DIR := docker
DOCKERFILE := $(DOCKER_DIR)/Dockerfile
DOCKER_BUILD_CONTEXT := .

# Get current user info for Docker
CURRENT_UID := $(shell id -u)
CURRENT_GID := $(shell id -g)
CURRENT_USER := $(shell whoami)

.PHONY: all build clean docker-build docker-push build-in-docker help

all: build

help:
	@echo "Usage: make [target]"
	@echo ""
	@echo "Targets:"
	@echo "  all                Build the project (default)"
	@echo "  build              Build the project locally"
	@echo "  clean              Clean build artifacts"
	@echo "  docker-build       Build the Docker image"
	@echo "  docker-push        Push the Docker image to a registry"
	@echo "  build-in-docker    Build the project inside a Docker container"
	@echo "  help               Show this help message"

# Build rules
build: $(OUTPUT_PRG)

$(OUTPUT_PRG): $(MAIN_SRC)
	@echo "Building $(PROJECT_NAME)..."
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(LST_DIR)
	$(CL65) $(CL65_FLAGS) -o $(OUTPUT_PRG) -l $(LST_DIR)/$(PROJECT_NAME).lst $(MAIN_SRC)
	@echo "Build complete: $(OUTPUT_PRG)"

# Docker rules
docker-build:
	@echo "Building Docker image..."
	docker build -t $(DOCKER_IMAGE):$(DOCKER_TAG) -f $(DOCKERFILE) $(DOCKER_BUILD_CONTEXT)

docker-push:
	@if [ -z "$(DOCKER_REGISTRY)" ]; then \
		echo "DOCKER_REGISTRY is not set. Cannot push."; \
		exit 1; \
	fi
	@echo "Pushing Docker image to $(DOCKER_REGISTRY)..."
	docker tag $(DOCKER_IMAGE):$(DOCKER_TAG) $(DOCKER_REGISTRY)/$(DOCKER_IMAGE):$(DOCKER_TAG)
	docker push $(DOCKER_REGISTRY)/$(DOCKER_IMAGE):$(DOCKER_TAG)

build-in-docker:
	@echo "Building project inside Docker container..."
	docker run --rm \
		-v $(CURDIR):/usr/src/app \
		-w /usr/src/app \
		-u $(CURRENT_UID):$(CURRENT_GID) \
		$(DOCKER_IMAGE):$(DOCKER_TAG) make build

# Clean rule
clean:
	@echo "Cleaning build artifacts..."
	@rm -rf $(BUILD_DIR)


