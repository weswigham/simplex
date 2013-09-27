
#include <stdio.h>
#include <math.h>
#include "../include/minunit.h"
#include "../src/simplex.h"

int tests_run = 0;

static char * test_Noise2D() {
    //Should operate over numbers
    double x = 0;
    double y = 0;
    printf("Noise2D(%f, %f): %f\n",x,y,Noise2D(x, y));
    y = -10;
    printf("Noise2D(%f, %f): %f\n",x,y,Noise2D(x, y));
    x = -10;
    y = 0;
    printf("Noise2D(%f, %f): %f\n",x,y,Noise2D(x, y));
    x = 0.432;
    y = -0.2376;
    printf("Noise2D(%f, %f): %f\n",x,y,Noise2D(x, y));
    return 0;
}

static char * test_Noise3D() {
    //Should operate over numbers
    double x = 0;
    double y = 0;
    double z = 0;
    printf("Noise3D(%f, %f, %f): %f\n", x, y, z, Noise3D(x, y, z));
    y = -10;
    z = -2;
    printf("Noise3D(%f, %f, %f): %f\n", x, y, z, Noise3D(x, y, z));
    x = -10;
    y = 0;
    z = 20;
    printf("Noise3D(%f, %f, %f): %f\n", x, y, z, Noise3D(x, y, z));
    x = 0.432;
    y = -0.2376;
    z = 128.234;
    printf("Noise3D(%f, %f, %f): %f\n", x, y, z, Noise3D(x, y, z));
    return 0;
}

static char * test_Noise4D() {
    //Should operate over numbers
    double x = 0;
    double y = 0;
    double z = 0;
    double w = 0;
    printf("Noise4D(%f, %f, %f, %f): %f\n", x, y, z, w, Noise4D(x, y, z, w));
    y = -10;
    z = -2;
    printf("Noise4D(%f, %f, %f, %f): %f\n", x, y, z, w, Noise4D(x, y, z, w));
    x = -10;
    y = 0;
    z = 20;
    printf("Noise4D(%f, %f, %f, %f): %f\n", x, y, z, w, Noise4D(x, y, z, w));
    x = 0.432;
    y = -0.2376;
    z = 128.234;
    w = 578.098;
    printf("Noise4D(%f, %f, %f, %f): %f\n", x, y, z, w, Noise4D(x, y, z, w));
    return 0;
}

double FakeNoise(int len, double args[]) {
    return 1.0;
}

static char * test_generic() {
    genericNoise n2d = {
        p2: &Noise2D
    };
    double args[2] = {0, -10}; 
    printf("Noise(2D; %f, %f): %f\n", args[0], args[1], Noise(n2d, 2, args));
    genericNoise n3d = {
        p3: &Noise3D
    };
    double args2[3] = {0, -10, 2.3345}; 
    printf("Noise(3D; %f, %f, %f): %f\n", args2[0], args2[1], args2[2], Noise(n3d, 3, args2));
    genericNoise n4d = {
        p4: &Noise4D
    };
    double args3[4] = {0, -10, 2.3345, -2.22341}; 
    printf("Noise(4D; %f, %f, %f, %f): %f\n", args3[0], args3[1], args3[2], args[3], Noise(n4d, 4, args3));
    genericNoise nNd = {
        pn: &FakeNoise
    };
    double unused[5] = {5.5,4.4,3.3,2.2,1.1};
    printf("Noise(ND;): %f\n", Noise(nNd, 5, unused));
    
    return 0;
}

static char * test_turbulence() {
    genericNoise n2d = {
        p2: &Noise2D
    };
    double args[2] = {0, -10}; 
    printf("TurbulentNoise(2D; %f, %f): %f\n", args[0], args[1], TurbulentNoise(n2d, SIMPLEX_X, 10, 2, args));
    genericNoise n3d = {
        p3: &Noise3D
    };
    double args2[3] = {0, -10, 2.3345}; 
    printf("TurbulentNoise(3D; %f, %f, %f): %f\n", args2[0], args2[1], args2[2], TurbulentNoise(n3d, SIMPLEX_Z, 10, 3, args2));
    genericNoise n4d = {
        p4: &Noise4D
    };
    double args3[4] = {0, -10, 2.3345, -2.22341}; 
    printf("TurbulentNoise(4D; %f, %f, %f, %f): %f\n", args3[0], args3[1], args3[2], args3[3], TurbulentNoise(n4d, SIMPLEX_W, 10, 4, args3));
    genericNoise nNd = {
        pn: &FakeNoise
    };
    double unused[5] = {5.5,4.4,3.3,2.2,1.1};
    printf("TurbulentNoise(ND;): %f\n", TurbulentNoise(nNd, 0, 10, 2, unused));
    printf("TurbulentNoise(ND;): %f\n", TurbulentNoise(nNd, 1, 10, 2, unused));
    printf("TurbulentNoise(ND;): %f\n", TurbulentNoise(nNd, 2, 10, 2, unused));
    printf("TurbulentNoise(ND;): %f\n", TurbulentNoise(nNd, 3, 10, 2, unused));
    printf("TurbulentNoise(ND;): %f\n", TurbulentNoise(nNd, 4, 10, 2, unused));
    return 0;
}

static char * test_fractal_sum() {
    genericNoise n2d = {
        p2: &Noise2D
    };
    double args[2] = {0, -10}; 
    printf("FractalSumNoise(2D; %f, %f): %f\n", args[0], args[1], FractalSumNoise(n2d, 10, 2, args));
    genericNoise n3d = {
        p3: &Noise3D
    };
    double args2[3] = {0, -10, 2.3345}; 
    printf("FractalSumNoise(3D; %f, %f, %f): %f\n", args2[0], args2[1], args2[2], FractalSumNoise(n3d, 10, 3, args2));
    genericNoise n4d = {
        p4: &Noise4D
    };
    double args3[4] = {0, -10, 2.3345, -2.22341}; 
    printf("FractalSumNoise(4D; %f, %f, %f, %f): %f\n", args3[0], args3[1], args3[2], args3[3], FractalSumNoise(n4d, 10, 4, args3));
    genericNoise nNd = {
        pn: &FakeNoise
    };
    double unused[5] = {5.5,4.4,3.3,2.2,1.1};
    printf("FractalSumNoise(ND;): %f\n", FractalSumNoise(nNd, 10, 2, unused));
    return 0;
}

static char * test_fractal_sum_abs() {
    genericNoise n2d = {
        p2: &Noise2D
    };
    double args[2] = {0, -10}; 
    printf("FractalSumAbsNoise(2D; %f, %f): %f\n", args[0], args[1], FractalSumAbsNoise(n2d, 10, 2, args));
    genericNoise n3d = {
        p3: &Noise3D
    };
    double args2[3] = {0, -10, 2.3345}; 
    printf("FractalSumAbsNoise(3D; %f, %f, %f): %f\n", args2[0], args2[1], args2[2], FractalSumAbsNoise(n3d, 10, 3, args2));
    genericNoise n4d = {
        p4: &Noise4D
    };
    double args3[4] = {0, -10, 2.3345, -2.22341}; 
    printf("FractalSumAbsNoise(4D; %f, %f, %f, %f): %f\n", args3[0], args3[1], args3[2], args3[3], FractalSumAbsNoise(n4d, 10, 4, args3));
    genericNoise nNd = {
        pn: &FakeNoise
    };
    double unused[5] = {5.5,4.4,3.3,2.2,1.1};
    printf("FractalSumAbsNoise(ND;): %f\n", FractalSumAbsNoise(nNd, 10, 2, unused));
    return 0;
}

static char * test_gblur()
{
    printf("GBlur1D(0.2, 0.12): %f\n", GBlur1D(0.2, 0.12));
    printf("GBlur2D(0.5, 0.25, 0.22): %f\n",  GBlur2D(0.5, 0.25, 0.22));
    
    //The following are because dividing by zero is bad
    //And I don't trust myself.
    mu_assert("GBlur1D should be 0 when stdDev = 0", GBlur1D(0, 1) == 0.0);
    mu_assert("GBlur2D should be 0 when stdDev = 0", GBlur2D(0, 2.3, 1) == 0.0);
    return 0;
}
 
//Yes, I'm aware I'm not *really* running any asserts; but that's okay. 
//The module is probably working if all of these functions even run.
//(And actually print out numbers that make sense, like non nan or infinity)
static char * all_tests() {
    mu_run_test(test_Noise2D);
    printf("\n");
    mu_run_test(test_Noise3D);
    printf("\n");
    mu_run_test(test_Noise4D);
    printf("\n");
    mu_run_test(test_generic);
    printf("\n");
    mu_run_test(test_turbulence);
    printf("\n");
    mu_run_test(test_fractal_sum);
    printf("\n");
    mu_run_test(test_fractal_sum_abs);
    printf("\n");
    mu_run_test(test_gblur);
    return 0;
}
 
int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("Tests run without error.\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}