
#include <stdio.h>
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

static char * test_generic() {
    genericNoise n2d = {
        p2: &Noise2D
    };
    double args[2] = {0, -10}; 
    printf("Noise(2D; %f, %f): %f\n", args[0], args[1], Noise(n2d, 2, args));
    printf("Noise(2D; %f, %f): %f\n", args[0], args[1], Noise(n2d, 2, args));
    return 0;
}
 
static char * all_tests() {
    mu_run_test(test_Noise2D);
    printf("\n");
    mu_run_test(test_Noise3D);
    printf("\n");
    mu_run_test(test_Noise4D);
    printf("\n");
    mu_run_test(test_generic);
    return 0;
}
 
int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    }
    else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}