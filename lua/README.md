simplex
=======

A lua module to create simplex noise. Originally published under the pseudonym Levybreak.

Functions
---------

######Noise2D
```lua
    --Noise function taking two numeric inputs: x and y
    --Returns a number between -1 and 1 (inclusive)
    local n = simplex.Noise2D(x, y)
```



######Noise3D
```lua
    --Noise function taking three numeric inputs: x, y, and z
    --Returns a number between -1 and 1 (inclusive)
    local n = simplex.Noise3D(x, y, z)
```

######Noise4D
```lua
    --Noise function taking four numeric inputs: x, y, z, and w
    --Returns a number between -1 and 1 (inclusive)
    local n = simplex.Noise4D(x, y, z, w)
```

######GBlur2D
```lua
    --Gaussian Blur function on two dimensions
    --Returns a number
    --x and y: Numeric inputs for the two dimensions
    --stdDev: The standard deviation for the set of data 
    --  within which x and y are to be skewed.
    --  The radius of the blur would be equal to the radius
    --  of values you include in calculating your standard
    --  deviation
    local n = simplex.GBlur2D(x, y, stdDev)
```

######GBlur1D
```lua
    --Gaussian Blur function on one dimension
    --Returns a number
    --x: Numeric inputs
    --stdDev: The standard deviation for the set of data 
    --  within which x is to be skewed.
    --  The radius of the blur would be equal to the radius
    --  of values you include in calculating your standard
    --  deviation
    local n = simplex.GBlur1D(x, stdDev)
```
Note: The GBlur1D function can be considered as the generalization of the function into N-dimensions by running it once for each dimension and combining the parts.

######FractalSum
```lua
    --A fractal sum iterative modifier for noise values
    --Returns a number between -1 and 1 (inclusive)
    --func: One of either simplex.Noise2D, simplex.Noise3D,
    --  simplex.Noise4D, or an alternative noise function
    --iter: The number of iterations to have in the summation
    --additional arguments are multiplied by a scaling factor
    --  and are passed to the noise function
    local n = simplex.FractalSum(func, iter, ...)
```

######FractalSumAbs
```lua
    --A absolute value fractal sum iterative modifier for noise values
    --Returns a number between 0 and 1 (inclusive)
    --func: One of either simplex.Noise2D, simplex.Noise3D,
    --  simplex.Noise4D, or an alternative noise function
    --iter: The number of iterations to have in the summation
    --additional arguments are multiplied by a scaling factor
    --  and are passed to the noise function
    local n = simplex.FractalSumAbs(func, iter, ...)
```

######Turbulence
```lua
    --A turbulence iterative modifier for noise values
    --Returns a number between -1 and 1 (inclusive)
    --func: One of either simplex.Noise2D, simplex.Noise3D,
    --  simplex.Noise4D, or an alternative noise function
    --direction: One of the constants: simplex.DIR_X, 
    --  simplex.DIR_Y, simplex.DIR_Z, and simplex.DIR_W
    --  indicating the direction of the turbulence (it should
    --  error if you choose one not in your noise function)
    --iter: The number of iterations to have in the summation
    --additional arguments are multiplied by a scaling factor
    --  and are passed to the noise function
    local n = simplex.Turbulence(func, direction, iter, ...)
```



