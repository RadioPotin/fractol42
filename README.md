# Fract-ol_42
Graphics Branch.

Fract'ol is a rendering project in C from the 42Paris Coding School.

The project aims at introducing the student to several key concepts:

1. Managing complexity and calculation of a given set of Fractal sets computation.
2. Rendering each fractal set in a window on the screen using the `mlx` library developped internally the school.
3. Multithreading with `pthread.h`.
4. Design with an arbitrary level of precision and gradiency for rendering colours/fractals and any imaginable detail.

The project is centered around static arrays and function pointers that make it very easy to modify and improved upon.

Each fractal set is given a number that is used throughout the program as an index to the different static arrays responsible for variable initialisations, fractal algorithms, computation functions that correspond to that fractal set.

Colour palettes are hard coded hex values in `int` arrays of size 16.

The choice of colour for each pixel is simple: `pixel = colour_palette[pixel_iterations % 16];`

There could be improvement to be done here, for example managing RGB encoding for more gradient colour changes and a more precise and polished look.

# Video showcase of the Julia Set.
[![Julia set showcase: Movement, colour, zoom.](https://img.youtube.com/vi/iZWgw2BeXzY/0.jpg)](https://youtu.be/iZWgw2BeXzY "Fract'ol")

