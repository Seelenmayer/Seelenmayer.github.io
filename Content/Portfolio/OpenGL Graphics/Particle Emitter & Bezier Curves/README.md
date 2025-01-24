Program: emitter\
Author: Clayton Seelenmayer\
Date: December 1st 2018

Description:\
This program will display a particle emitter that moves along a quadratic bezier curve with linearly interpolated colour cycling particles.

Controls:
- Arrow keys will pan the screen.
- 'r' or 'R' will toggle between restarting the simulation or pause it.
- Any digit ('0'->'9') will adjust the particle emission speed.
- '+' ('=') or '-' will adjust the emitter's movement speed.
- 'D' or 'd' will display a curve debug menu.
- Mouse wheel will zoom into and out of the scene.
- End will close the glut display.

Compilation:\
Type "make" into the command line to compile and run the emitter animation in a Linux Debian environment. The required standard libraries are iostream, cmath, vector, GL/gl.h, GL/glu.h, GL/glut.h.

Contributors:\
Mike K

License:\
This software is licensed under GPL version 2.
