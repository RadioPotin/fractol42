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

# Usage


```
USAGE: ./[fractol || Fractol_linux] [Fractal_Name] [--help || --h] [--list || --l]

        [fractol || Fractol_linux]:
                Binary for Fract'ol.
                To ensure that the project is compilable on MacOS as well as Linux, the Makefile outputs two different executables.
                By default, it will link the project for it to work on MacOS.
                Else, if the command "make linux" is entered, the project will be linked for it work on linux, given X11 library is installed.
                Argument hierarchy goes from top to low: [Fractal_Name] > [--h] > [--l]

        [Fractal_Name]:
                The project supports a given set of fractal ensembles.
                You can find a list of their names by using the [--list] option.

OPTIONS: Options may be placed in whichever order. The program is not case sensitive regarding fractal names. Unknown options will be ignored. Lack of known options will display usage.

        [--help] or [--h]:
                Displays usage.

        [--list] or [--l]:
                Displays the list of supported fractals.
```
