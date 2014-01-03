simplex
=======

A collection of Simplex Noise implementations.

Wait, what is simplex noise?
----------------------------
I'm glad you asked! Simplex noise is [Ken Perlin's successor to classical Perlin noise.](http://www.csee.umbc.edu/~olano/s2002c36/ch02.pdf) Perlin noise uses a gradient-selection and weightings system based on a 'cube' in the desired number of dimensions. This means it calculates the weights from 4 points in 2D (the corners of a square), 8 points in 3D (a cube), and a whopping 16 points in 4D. Simplex noise, on the other hand, uses coordinates based on the simplex for the given dimensionality. So in 2D, 3 points (a triangle), in 3D - 4 points (a triangular pyramid), and in 4D - 5 points. As you can see, the number of points you calculate with dimensionality grows linearly with simplex noise, instead of doubling as with classic perlin noise. (Ken Perlin says the math is O(2^n) for perlin noise, but O(n^2) for simplex noise.) Long story short, you end up doing quite a lot fewwer calculations to get similar noise results. 

Simplex noise has been around for about a decade now, but a large number of projects still default to perlin noise simply by not knowing that simplex noise exists. A huge number of projects still use the almost decade old [libnoise](http://libnoise.sourceforge.net/index.html), which lacks a simplex noise implementation.

Right now, I have implementations in

* [c](https://github.com/weswigham/simplex/tree/master/c)
* [lua](https://github.com/weswigham/simplex/tree/master/lua)
* [haskell](https://github.com/weswigham/simplex/tree/master/haskell)

And accompanying documentation and tests. I plan on continuing to add languages to this repository as time goes on and more langauges catch my eye.
