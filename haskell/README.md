Simplex
=======

A haskell module to make simplex noise, a continuous noise function designed by Ken Perlin.

Example
-------
```haskell
import Simplex

noise2D 0.1234423232 pi --evaluates to 0.33984928600460507
```

Functions
---------

#######dot
```haskell
--A dot product for any two vectors of equal length
dot :: (Num a) => [a] -> [a] -> a
dot xs ys 

--usually used as such:
[1,2,3,4] `dot` [5,6,7,8] 
```

#######noise2D
```haskell
noise2D :: Double -> Double -> Double
noise2D x y
```

#######noise3D
```haskell
noise3D :: Double -> Double -> Double -> Double
noise3D x y z
```

#######noise4D
```haskell
noise4D :: Double -> Double -> Double -> Double -> Double
noise4D x y z w
```