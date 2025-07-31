# 🗺️ FdF (Fil de Fer) - 3D Wireframe Viewer

## 🎯 About The Project

FdF (Fil de Fer) is a 3D wireframe viewer developed as part of the 42 school curriculum. The program takes a map file as input and renders it as a 3D wireframe representation, allowing users to visualize terrain and geometric shapes in a three-dimensional space.

---
> 🚧 **Status:** Completed

## ✨ Features

- 🎨 3D wireframe rendering
- 📄 Various map file support
- 🌈 Color gradient support
- 🔄 Rotation and zoom controls
- 🎮 Interactive camera movement
- 📐 Isometric and parallel projection views

## 🚀 Installation

```bash
# Clone the repository
git clone git@github.com:Ertugrul-Pakdamar/42_ring2_fdf.git
cd 42_ring2_fdf

# Compile the project
make
```

## 🎮 Usage

```bash
# Basic usage
./fdf test_maps/42.fdf

# Using with other map files
./fdf test_maps/[map_file_name].fdf
```

### 🕹️ Controls

- **⬅️➡️⬆️⬇️ Arrow Keys**: Move the map
- **🖱️ Mouse Wheel**: Zoom in/out
- **🔄 R Key**: Reset view
- **❌ ESC**: Exit program

## 📝 Map File Format

The program reads map files with the following format:
```
0  0  0  0  0
0  1  2  3  0
0  2  4  6  0
0  3  6  9  0
0  0  0  0  0
```

Each number represents a point in 3D space:
- Position in the grid (x,y)
- Altitude (z)

## 📚 Dependencies

- 🖥️ MinilibX
- 🧮 Math Library
- 🎨 X11 Library

## 🛠️ Building

```bash
# Compile mandatory part
make

# Compile with bonus features
make bonus

# Clean object files
make clean

# Clean all generated files
make fclean

# Recompile everything
make re
```
