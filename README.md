# Cub3D - 3D Maze Renderer

*This project was created as part of the 42 curriculum by brfialho and gbercaco.*

---

## Description

Cub3D is a C-based 3D maze renderer using raycasting—a rendering technique that projects 3D environments onto a 2D plane. The project reads a custom map file format (`.cub`), parses its configuration, and renders an interactive first-person perspective view of the maze environment.

### Key Features

- **Raycasting Engine**: Real-time 3D rendering using the raycasting algorithm
- **Map Parsing**: Custom `.cub` file format for defining map layout, textures, and colors
- **Interactive Navigation**: WASD keys for movement, arrow keys for rotation
- **MLX Graphics Library**: Cross-compatible graphics rendering on Linux
- **Memory Management**: Complete initialization and cleanup routines without memory leaks
- **Input Handling**: Real-time keyboard input with collision detection

### Technical Stack

- **Language**: C (C99 standard)
- **Graphics Library**: MLX (Min LibX)
- **Custom Utilities**: libft (custom C library with essential functions)
- **Build System**: Make

---

## Instructions

### Prerequisites

- GCC or Clang compiler
- X11 development libraries (for Linux)
- Make
- MLX library dependencies:
  - `libxext-dev`
  - `libx11-dev`

On Debian/Ubuntu systems, install dependencies:

```bash
sudo apt-get install libxext-dev libx11-dev
```

### Compilation

To build the project:

```bash
make
```

Available build targets:

- `make` or `make all` - Compile the entire project
- `make clean` - Remove object files and test binaries
- `make fclean` - Remove all build artifacts including the executable
- `make re` - Clean and rebuild everything
- `make test` - Run unit tests with memory leak detection (requires valgrind)

### Running the Program

Execute the compiled binary with a valid `.cub` map file:

```bash
./cub3d maps/valid/1.cub
```

#### Map File Format

The `.cub` file format specifies:

- **NO, SO, EA, WE** - Paths to north, south, east, and west wall textures
- **F** - Floor color (RGB format: `R,G,B`)
- **C** - Ceiling color (RGB format: `R,G,B`)
- **Map Layout** - 2D grid using characters:
  - `0` - Empty space (walkable)
  - `1` - Wall
  - `N/S/E/W` - Player starting position and direction

Example:

```
NO ./path/to/north_texture.xpm
SO ./path/to/south_texture.xpm
EA ./path/to/east_texture.xpm
WE ./path/to/west_texture.xpm

F 220,100,0
C 225,30,0

111111
100101
101101
1N0001
111111
```

### Controls

| Key | Action |
|-----|--------|
| **W** | Move forward |
| **A** | Strafe left |
| **S** | Move backward |
| **D** | Strafe right |
| **←** | Rotate left |
| **→** | Rotate right |
| **ESC** | Exit program |

---

## Resources

### Documentation & References

- [Raycasting Theory](https://en.wikipedia.org/wiki/Ray_casting) - Understanding the core rendering algorithm
- [Lode Vandevelde's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) - Comprehensive raycasting implementation guide
- [MLX Documentation](https://cdn.intra.42.fr/pdf/pdf/get/eyJpZCI6IjI1OTMwNyIsImZpbGVuYW1lIjoibWx4LWxpbnV4Lm1hbiJ9/mlx-linux.man) - MLX library reference
- [Game Programming Patterns - Raycasting](https://gameprogrammingpatterns.com/) - Software architecture for game engines

### Key Concepts

- **Raycasting Algorithm**: Projects rays from the camera viewpoint through each pixel to determine which wall segment is visible
- **DDA (Digital Differential Analyzer)**: Used for efficient ray-wall intersection calculations
- **Texture Mapping**: Applies 2D textures to raycasted wall segments for visual detail
- **Delta Time**: Frame-independent movement calculation for smooth gameplay across different refresh rates

---

## AI Usage

This project incorporated artificial intelligence assistance for the following tasks:

### Code Optimization & Debugging

- **Raycasting Algorithm Refinement** - AI helped optimize the core raycasting loop and wall intersection calculations
- **Memory Management Verification** - AI validated manual memory allocation/deallocation patterns and identified potential leaks
- **Build System Configuration** - AI assisted in Makefile optimization and dependency management

### Development Support

- **Parser Implementation** - AI provided guidance on robust `.cub` file parsing and error handling
- **Code Structure** - AI suggested modular organization with separate files for parsing, rendering, and game logic
- **Documentation** - AI helped generate this README and inline code comments

### Areas NOT Assisted by AI

- **Core Algorithm Logic** - Raycasting mathematics and physics calculations were manually implemented
- **Creative Design** - Map layout, color schemes, and game mechanics were developer-designed
- **Direct Code Writing** - No code was generated directly; AI provided guidance and suggestions only

---

## Project Structure

```
cub3d/
├── srcs/                      # Source files
│   ├── main.c                # Entry point and game loop
│   ├── move_player.c         # Player movement logic
│   ├── init_destroy/         # Game initialization and cleanup
│   ├── parsing/              # Map file parsing
│   └── render/               # Raycasting and rendering logic
├── includes/                 # Header files
│   ├── main.h
│   ├── structs.h
│   ├── defines.h
│   ├── parsing.h
│   └── render.h
├── libft/                    # Custom C library
├── mlx/                      # MLX graphics library
├── maps/                     # Test map files
├── tests/                    # Unit tests
├── Makefile                  # Build configuration
└── README.md                 # This file
```

---

## Compilation Status

The project compiles successfully with no warnings or errors when using the standard compilation flags:

```
-Wall -Wextra -Werror
```

All memory is properly managed and tested with `valgrind` for leak detection.

---

## Author

**brfialho** - 42 Student

**gbercaco** - 42 Student

---

## License

This project is part of the 42 curriculum and is provided as-is for educational purposes.
