# Pac-Man X16

![Pac-Man](https://github.com/andymccall/pac-man/blob/main/assets/header.jpg?raw=true)

## 🚦 Build Status

[![main branch build status](https://img.shields.io/github/actions/workflow/status/andymccall/pac-man-x16/ci.yml?branch=main&label=main)](https://github.com/andymccall/pac-man-x16/actions/workflows/ci.yml)
[![develop branch build status](https://img.shields.io/github/actions/workflow/status/andymccall/pac-man-x16/ci.yml?branch=develop&label=develop)](https://github.com/andymccall/pac-man-x16/actions/workflows/ci.yml)

## 🎮 About

This project is a clone of the classic arcade game Pac-Man, developed for the Commander X16 platform. It is written in 6502 assembly language and utilizes the cc65 toolchain for compilation.

Pac-Man, originally called Puck Man in Japan, is a 1980 maze video game developed and released by Namco for arcades. In North America, the game was released by Midway Manufacturing as part of its licensing agreement with Namco America. The player controls Pac-Man, who must eat all the dots inside an enclosed maze while avoiding four colored ghosts. Eating large flashing dots called "Power Pellets" causes the ghosts to temporarily turn blue, allowing Pac-Man to eat them for bonus points.

This project intends to hold the most perfect arcade port of the 1980's arcade game Pac-Man to the Commander X16 possible, within the limitations of the platform.

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

---
# Pac-Man X16 (吃豆人 X16)

![Pac-Man](https://github.com/andymccall/pac-man/blob/main/assets/header.jpg?raw=true)

## 🚦 构建状态

[![main branch build status](https://img.shields.io/github/actions/workflow/status/andymccall/pac-man-x16/ci.yml?branch=main&label=main)](https://github.com/andymccall/pac-man-x16/actions/workflows/ci.yml)
[![develop branch build status](https://img.shields.io/github/actions/workflow/status/andymccall/pac-man-x16/ci.yml?branch=develop&label=develop)](https://github.com/andymccall/pac-man-x16/actions/workflows/ci.yml)

## 🎮 关于

这个项目是经典街机游戏吃豆人 (Pac-Man) 的克隆版，为 Commander X16 平台开发。它使用 6502 汇编语言编写，并利用 cc65 工具链进行编译。

吃豆人，在日本最初被称为 Puck Man，是 Namco 于 1980 年为街机开发和发行的迷宫视频游戏。在北美，该游戏由 Midway Manufacturing 作为其与 Namco America 许可协议的一部分发行。玩家控制吃豆人，他必须吃掉封闭迷宫内的所有豆子，同时避开四个彩色的鬼魂。吃掉名为“能量豆”的大闪烁豆子会导致鬼魂暂时变蓝，让吃豆人可以吃掉它们以获得奖励积分。

该项目旨在在平台限制内，为 Commander X16 尽可能完美地移植 1980 年代的街机游戏吃豆人。

## 🛠️ 先决条件

### 本地开发
- **Git**：用于版本控制。
- **Make**：用于构建自动化。
- **Docker**：（推荐）用于一致的容器化构建环境。
- **cc65**：（可选）仅在您打算在没有 Docker 的情况下进行本地构建时才需要。

### Commander X16 模拟器
- **x16emu**：官方的 Commander X16 模拟器，用于测试游戏。

## 🚀 快速入门

### 使用 Docker (推荐)
以下命令将克隆存储库，在 Docker 容器内构建项目，并提供在模拟器中运行它的命令。

```bash
# 1. 克隆存储库
git clone https://github.com/andymccall/pac-man-x16.git
cd pac-man-x16

# 2. 使用 Docker 构建项目
make build-in-docker

# 3. 在 Commander X16 模拟器中运行游戏
x16emu -prg build/bin/PAC-MAN-X16.PRG -run
```

### 本地构建 (不使用 Docker)
如果您的本地计算机上安装了 `cc65`，则可以本地构建项目。

```bash
# 1. 构建项目
make build

# 2. 运行游戏
x16emu -prg build/bin/PAC-MAN-X16.PRG -run
```

## 📁 项目结构

```
pac-man-x16/
├── src/                    # 源代码
│   ├── main.asm            # 主程序入口点
│   └── includes/           # API 和应用程序的包含文件
├── build/                  # 构建输出 (自动生成)
│   ├── bin/                # 已编译的二进制文件 (例如 PAC-MAN-X16.PRG)
│   └── lst/                # 汇编列表和调试文件
├── docker/                 # Docker 构建环境
│   └── Dockerfile          # 定义构建容器
├── Makefile                # 构建自动化脚本
└── README.md               # 此文件
```

## 🔨 构建系统

该项目使用 `Makefile` 来自动化构建。以下是主要命令：

| 命令                | 描述                                                                  |
|-------------------|------------------------------------------------------------------------------|
| `make build`      | 本地构建项目 (需要本地 `cc65`)。                         |
| `make clean`      | 从 `build/` 目录中清除所有构建产物。                      |
| `make docker-build` | 构建用于容器化构建的 Docker 镜像。                       |
| `make docker-push`| 将 Docker 镜像推送到容器注册表 (需要 `DOCKER_REGISTRY`)。|
| `make build-in-docker` | 在 Docker 容器内构建项目。                              |
| `make help`       | 显示包含所有可用命令的帮助消息。                         |


## 🐳 Docker 开发环境

该项目包含一个 `Dockerfile`，用于创建一个包含所有必要工具 (包括 `cc65` 工具链) 的自包含开发环境。这是确保一致性的推荐构建方法。

您可以使用 `make docker-build` 构建 Docker 镜像，然后使用 `make build-in-docker` 编译项目。

## 🤝 贡献

欢迎贡献！请随时 fork 存储库，进行更改并提交拉取请求。

## 📄 许可证

该项目是开源的。有关更多详细信息，请参阅 `LICENSE` 文件。

## 👨‍💻 作者

**Andy McCall**
- **GitHub**: [@andymccall](https://github.com/andymccall)
- **Email**: mailme@andymccall.co.uk