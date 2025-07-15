# Pac-Man X16

![Pac-Man](https://github.com/andymccall/pac-man/blob/main/assets/header.jpg?raw=true)

## 🚦 Build Status

[![main branch build status](https://img.shields.io/github/actions/workflow/status/andymccall/pac-man-x16/ci.yml?branch=main&label=main)](https://github.com/andymccall/pac-man-x16/actions/workflows/ci.yml)
[![develop branch build status](https://img.shields.io/github/actions/workflow/status/andymccall/pac-man-x16/ci.yml?branch=develop&label=develop)](https://github.com/andymccall/pac-man-x16/actions/workflows/ci.yml)

## 🎮 About

This project is a clone of the classic arcade game Pac-Man, developed for the Commander X16 platform. It is written in 6502 assembly language and utilizes the cc65 toolchain for compilation.

Pac-Man, originally called Puck Man in Japan, is a 1980 maze video game developed and released by Namco for arcades. In North America, the game was released by Midway Manufacturing as part of its licensing agreement with Namco America. The player controls Pac-Man, who must eat all the dots inside an enclosed maze while avoiding four colored ghosts. Eating large flashing dots called "Power Pellets" causes the ghosts to temporarily turn blue, allowing Pac-Man to eat them for bonus points.

This project intents to hold the most perfect arcade port of the 1980's arcade game Pac-Mac to the Commander X16 possible, within the limitations of the platform.

## 🛠️ Prerequisites

### Local Development
- **Git**: For version control.
- **Make**: For build automation.
- **Docker**: (Recommended) For a consistent, containerized build environment.
- **cc65**: (Optional) Required only if you intend to build natively without Docker.

### Commander X16 Emulator
- **x16emu**: The official Commander X16 emulator, used for testing the game.

## 🚀 Quick Start

### Using Docker (Recommended)
The following commands will clone the repository, build the project inside a Docker container, and provide the command to run it in the emulator.

```bash
# 1. Clone the repository
git clone https://github.com/andymccall/pac-man-x16.git
cd pac-man-x16

# 2. Build the project using Docker
make build-in-docker

# 3. Run the game in the Commander X16 emulator
x16emu -prg build/bin/PAC-MAN-X16.PRG -run
```

### Native Build (Without Docker)
If you have `cc65` installed on your local machine, you can build the project natively.

```bash
# 1. Build the project
make build

# 2. Run the game
x16emu -prg build/bin/PAC-MAN-X16.PRG -run
```

## 📁 Project Structure

```
pac-man-x16/
├── src/                    # Source code
│   ├── main.asm            # Main program entry point
│   └── includes/           # Include files for API and application
├── build/                  # Build output (auto-generated)
│   ├── bin/                # Compiled binaries (e.g., PAC-MAN-X16.PRG)
│   └── lst/                # Assembly listings and debug files
├── docker/                 # Docker build environment
│   └── Dockerfile          # Defines the build container
├── Makefile                # Build automation script
└── README.md               # This file
```

## 🔨 Build System

The project uses a `Makefile` to automate builds. Here are the primary commands:

| Command           | Description                                                                  |
|-------------------|------------------------------------------------------------------------------|
| `make build`      | Builds the project natively (requires local `cc65`).                         |
| `make clean`      | Cleans all build artifacts from the `build/` directory.                      |
| `make docker-build` | Builds the Docker image used for containerized builds.                       |
| `make docker-push`| Pushes the Docker image to a container registry (requires `DOCKER_REGISTRY`).|
| `make build-in-docker` | Builds the project inside the Docker container.                              |
| `make help`       | Displays a help message with all available commands.                         |


## 🐳 Docker Development Environment

The project includes a `Dockerfile` to create a self-contained development environment with all necessary tools, including the `cc65` toolchain. This is the recommended way to build the project to ensure consistency.

You can build the Docker image with `make docker-build` and then compile the project with `make build-in-docker`.

## 🤝 Contributing

Contributions are welcome! Please feel free to fork the repository, make your changes, and submit a pull request.

## 📄 License

This project is open source. See the `LICENSE` file for more details.

## 👨‍💻 Author

**Andy McCall**
- **GitHub**: [@andymccall](https://github.com/andymccall)
- **Email**: mailme@andymccall.co.uk
