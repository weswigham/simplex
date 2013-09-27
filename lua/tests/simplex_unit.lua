local simplex = require("src.simplex")
local describe = require("include.least.least")

describe("simplex noise",function(_ENV) 
    describe("2D Noise", function()
        it("should operate over numbers",function()
            assert(simplex.Noise2D(0,0))
            assert(simplex.Noise2D(0,-10))
            assert(simplex.Noise2D(-10,0))
            assert(simplex.Noise2D(0.432,-0.2376))
        end)
    end)
    describe("3D Noise", function()
        it("should operate over numbers",function()
            assert(simplex.Noise3D(0,0,0))
            assert(simplex.Noise3D(0,-10,-2))
            assert(simplex.Noise3D(-10,0,20))
            assert(simplex.Noise3D(0.432,-0.2376,128.234))
        end)
    end)
    
    describe("4D Noise", function()
        it("should operate over numbers",function()
            assert(simplex.Noise4D(0,0,0,0))
            assert(simplex.Noise4D(0,-10, -2, 0))
            assert(simplex.Noise4D(-10,0, 20, 0))
            assert(simplex.Noise4D(0.432,-0.2376, 128.234, 578.098))
        end)
    end)
    
    describe("Turbulent Noise",function()
        it("functions with 2D Noise",function()
            assert(simplex.Turbulence(simplex.Noise2D, simplex.DIR_X, 10, 
                0, 0))
            assert(simplex.Turbulence(simplex.Noise2D, simplex.DIR_Y, 10, 
                0, 0))
        end)
        it("functions with 3D Noise",function()
            assert(simplex.Turbulence(simplex.Noise3D, simplex.DIR_X, 10, 
                0, 0, 0))
            assert(simplex.Turbulence(simplex.Noise3D, simplex.DIR_Y, 10, 
                0, 0, 0))
            assert(simplex.Turbulence(simplex.Noise3D, simplex.DIR_Z, 10, 
                0, 0, 0))
        end)
        it("functions with 4D Noise",function()
            assert(simplex.Turbulence(simplex.Noise4D, simplex.DIR_X, 10, 
                0, 0, 0, 0))
            assert(simplex.Turbulence(simplex.Noise4D, simplex.DIR_Y, 10, 
                0, 0, 0, 0))
            assert(simplex.Turbulence(simplex.Noise4D, simplex.DIR_Z, 10, 
                0, 0, 0, 0))
            assert(simplex.Turbulence(simplex.Noise4D, simplex.DIR_W, 10, 
                0, 0, 0, 0))
        end)
    end)
    
    describe("Fractal Sum Noise",function()
        it("functions with 2D Noise",function()
            assert(simplex.FractalSum(simplex.Noise2D, 10, 
                0, 0))
        end)
        it("functions with 3D Noise",function()
            assert(simplex.FractalSum(simplex.Noise3D, 10, 
                0, 0, 0))
        end)
        it("functions with 4D Noise",function()
            assert(simplex.FractalSum(simplex.Noise4D, 10, 
                0, 0, 0, 0))
        end)
    end)
    
describe("Fractal Sum Noise",function()
        it("functions with 2D Noise",function()
            assert(simplex.FractalSum(simplex.Noise2D, 10, 
                0, 0))
        end)
        it("functions with 3D Noise",function()
            assert(simplex.FractalSumAbs(simplex.Noise3D, 10, 
                0, 0, 0))
        end)
        it("functions with 4D Noise",function()
            assert(simplex.FractalSumAbs(simplex.Noise4D, 10, 
                0, 0, 0, 0))
        end)
    end)
end)