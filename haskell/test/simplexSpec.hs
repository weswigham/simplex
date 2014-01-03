module SimplexSpec where

import Test.Hspec
import Control.Exception (evaluate)
import Simplex

main :: IO ()
main = hspec $ do
    describe "dot" $ do
        it "operates over 1D vectors" $
            ([2] `dot` [3]) `shouldBe` 6
         
        it "operates over 2D vectors" $
            ([1,2] `dot` [1,1]) `shouldBe` 3
            
        it "operates over 3D vectors" $
            ([1,2,3] `dot` [1,1,1]) `shouldBe` 6
            
        it "operates over 4D vectors" $
            ([1,2,3,4] `dot` [1,1,1,1]) `shouldBe` 10
            
        it "fails on vectors of differing lengths" $
            evaluate ([1,2,3] `dot` [1,2,3,4]) `shouldThrow` anyErrorCall
            
    describe "noise2D" $ do
        it "works with integers" $
            (noise2D (-12) 27) `shouldSatisfy` (not . isNaN) 

        it "works with decimals" $
            (noise2D (-12.222) 27.0123) `shouldSatisfy` (not . isNaN) 

        it "works with irrational numbers" $
            (noise2D (exp 1) pi) `shouldSatisfy` (not . isNaN)        

    describe "noise3D" $ do
        it "works with integers" $
            (noise3D (-12) 27 0) `shouldSatisfy` (not . isNaN) 

        it "works with decimals" $
            (noise3D (-12.222) 27.0123 0.1234) `shouldSatisfy` (not . isNaN) 

        it "works with irrational numbers" $
            (noise3D (exp 1) pi pi) `shouldSatisfy` (not . isNaN)  

    describe "noise4D" $ do
        it "works with integers" $
            (noise4D (-12) 27 0 1) `shouldSatisfy` (not . isNaN) 

        it "works with decimals" $
            (noise4D (-12.222) 27.0123 0.1234 1.1234) `shouldSatisfy` (not . isNaN) 

        it "works with irrational numbers" $
            (noise4D (exp 1) pi pi pi) `shouldSatisfy` (not . isNaN)                 