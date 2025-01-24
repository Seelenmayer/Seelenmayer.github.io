Program: cfg\
Author: Clayton Seelenmayer\
Date: Dec 1st 2018

Description:
This program uses a context free grammar (L-System) to render a tree from a human readable input file. It also loads in an OBJ file as background scenery, applies a texture, and allows the user to control the scenary with orbiting camera controls.

Controls:

Camera:\
Left-click + drag to orbit.

Camera Pan:
- '8': Pan the camera up.
- '4': Pan the camera left.
- '5': Pan the camera down.
- '6': Pan the camera right.

Render Scene:
- 'a': Toggle render the arena.
- 's': Toggle render the LSystem spine.
- 'g': Toggle render the LSystem girth.
- "<-" : Left arrow to decrease the LSystem's depth.
- "->" : Right arrow to increase the LSystem's depth.

Lighting:
- '0': Turn on 3 white lights.
- '1': Turn on the Red light.
- '2': Turn on the Yellow light.
- '3': Turn on the Green light.

Compilation:\
Type "make" into the command line to compile and run on a Linux Debian environment the context free grammar tree program. The required standard libraries are "fstream", "string", "cmath", "vector", "stack", "GL/gl.h", "GL/glu.h", "GL/glut.h".

Contributors:\
Mike K. for developing "mathvector.h", "LoadObj.h", "LoadObj.cpp", and "LoadImage". Benjamin Kalytta for developing "bitmap.h", sourced from "http://www.kalytta.com/bitmap.h".

License:\
This software is licensed under GPL version 2.
