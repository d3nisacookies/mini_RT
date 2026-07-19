*This project has been created as part of the 42 curriculum by akaung and tswe-zin.*

# miniRT

## Description

**miniRT** is a minimal ray tracer written in C as part of the 42 curriculum. The goal of the project is to introduce the fundamentals of computer graphics by implementing a simple rendering engine capable of generating a 3D scene from a mathematical description.

The program reads a scene description from a `.rt` file, computes the interaction of light rays with objects in the scene, and renders the resulting image in a graphical window. The implementation covers essential ray tracing concepts such as ray-object intersections, lighting calculations, shadows, and camera projection.

### Features

- Render scenes described in `.rt` files.
- Support for the mandatory objects:
  - Sphere
  - Plane
  - Cylinder
- Ambient and point lighting.
- Camera positioning and orientation.
- Diffuse lighting using the Lambert reflection model.
- Hard shadows.
- Scene validation with error handling.
- Real-time display using MiniLibX.

## Instructions

### Prerequisites

- GCC or Clang
- Make
- MiniLibX
- X11 libraries (Linux) or the macOS frameworks required by MiniLibX

### Compilation

```bash
make
```

### Execution

```bash
./miniRT scenes/example.rt
```

Replace `example.rt` with the path to any valid scene description file.

### Cleaning

```bash
make clean
make fclean
make re
```

## Scene Format

A valid scene must contain:

- One ambient light
- One camera
- One light source

Supported objects:

- Sphere (`sp`)
- Plane (`pl`)
- Cylinder (`cy`)

Each element must follow the format specified in the project subject. Invalid files should produce an appropriate error message.

Example:

```text
A 0.2 255,255,255
C 0,0,-10 0,0,1 70
L 0,10,-10 0.8 255,255,255

sp 0,0,0 4 255,0,0
pl 0,-2,0 0,1,0 255,255,255
cy 3,0,0 0,1,0 2 6 0,255,0
```

### Element Breakdown

#### Ambient Light

```text
A 0.2 255,255,255
```

| Value | Meaning |
|-------|---------|
| `A` | Ambient light identifier |
| `0.2` | Brightness ratio (0.0–1.0) |
| `255,255,255` | RGB color of the ambient light |

---

#### Camera

```text
C 0,0,-10 0,0,1 70
```

| Value | Meaning |
|-------|---------|
| `C` | Camera identifier |
| `0,0,-10` | Camera position `(x, y, z)` |
| `0,0,1` | Camera orientation vector (normalized) |
| `70` | Field of View (FOV) in degrees |

---

#### Light Source

```text
L 0,10,-10 0.8 255,255,255
```

| Value | Meaning |
|-------|---------|
| `L` | Point light identifier |
| `0,10,-10` | Light position `(x, y, z)` |
| `0.8` | Brightness ratio (0.0–1.0) |
| `255,255,255` | RGB color of the light |

---

#### Sphere

```text
sp 0,0,0 4 255,0,0
```

| Value | Meaning |
|-------|---------|
| `sp` | Sphere identifier |
| `0,0,0` | Center position `(x, y, z)` |
| `4` | Diameter of the sphere |
| `255,0,0` | RGB color (red) |

---

#### Plane

```text
pl 0,-2,0 0,1,0 255,255,255
```

| Value | Meaning |
|-------|---------|
| `pl` | Plane identifier |
| `0,-2,0` | A point on the plane |
| `0,1,0` | Plane normal vector (normalized) |
| `255,255,255` | RGB color |

---

#### Cylinder

```text
cy 3,0,0 0,1,0 2 6 0,255,0
```

| Value | Meaning |
|-------|---------|
| `cy` | Cylinder identifier |
| `3,0,0` | Center position |
| `0,1,0` | Cylinder axis direction (normalized) |
| `2` | Diameter |
| `6` | Height |
| `0,255,0` | RGB color (green) |

## Project Structure

```
.
├── includes/       # Header files
├── src/            # Source files
├── scenes/         # Example .rt scene files
├── libft/          # Custom C library
├── minilibx/       # MiniLibX library
├── gnl/            # GetNextLine library
├── mlx.supp        # Ignore reachable leaks from libX11
├── Makefile
└── README.md
```

## Technical Overview

The renderer is based on the ray tracing algorithm:

1. A ray is generated for each pixel from the camera.
2. The closest object intersected by the ray is determined.
3. The surface normal is computed at the intersection point.
4. Lighting is calculated using ambient and diffuse illumination.
5. Shadow rays determine whether the point is illuminated or occluded.
6. The final color is displayed in the rendering window.

## Resources

### Documentation

- 42 miniRT subject
- MiniLibX documentation
- The Ray Tracer Challenge — Jamis Buck
- Scratchapixel — Introduction to Ray Tracing
- Ray Tracing in One Weekend — Peter Shirley
- OpenGL Mathematics (GLM) documentation (for mathematical reference)

### Tutorials & References

- https://raytracing.github.io/
- https://www.scratchapixel.com/
- https://harm-smits.github.io/42docs/libs/minilibx
- https://en.cppreference.com/
- https://man7.org/linux/man-pages/
- https://youtu.be/H5TB2l7zq6s?si=N66r63aTw2FF42-J

### AI Usage

- Explaining mathematical concepts related to vectors, ray-object intersections, and lighting.
- Clarifying ray tracing algorithms and rendering techniques.
- Reviewing parser logic and suggesting improvements for code readability.
- Assisting in debugging by explaining compiler errors and runtime behavior.
- Generating test cases and sample `.rt` scene files to validate parser behavior, object intersections, and edge cases.
- Drafting and improving project documentation, including this README.

All project design decisions, implementation, testing, debugging, and final validation were completed manually to ensure compliance with the 42 miniRT subject and evaluation requirements.

## Future Improvements

Possible extensions include:

- Reflection and refraction.
- Specular highlights (Phong shading).
- Multiple light sources.
- Texture mapping.
- Anti-aliasing.
- Bounding volume hierarchies (BVH) for faster rendering.
- Soft shadows.
- Transparency.
