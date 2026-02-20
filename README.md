# ccomplex
This is a very small and bare-bones header-only C library for complex number calculations. 
It isn't fast, it isn't clean-coded, it is just a small fun project I made because I wanted to do some light-heading coding without pressure.
Please feel free to submit a pull-request if you have any improvements to make. (I will ignore automated LLM-written pull requests.)

# Build
Add the ccomplex.h to your project, and in any implementation file you will compile in your build process, add the following.
```C
#define CCOMPLEX_IMPLEMENTATION
#include "ccomplex.h"
```
