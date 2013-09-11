simplex
=======

A lua module to create simplex noise. Originally published under the pseudonym Levybreak.

Functions
---------

######Noise2D
```lua
    local n = simplex.Noise2D(x, y)
```

######Noise3D
```lua
    local n = simplex.Noise3D(x, y, z)
```

######Noise4D
```lua
    local n = simplex.Noise4D(x, y, z, w)
```

######GBlur2D
```lua
    local n = simplex.GBlur2D(x, y, stdDev)
```

######GBlur1D
```lua
    local n = simplex.GBlur1D(x, stdDev)
```