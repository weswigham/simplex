//externs made available by simplex.c

#ifndef SIMPLEX_H_INCLUDED
#define SIMPLEX_H_INCLUDED

typedef double (*noise2Dptr)(double, double);
typedef double (*noise3Dptr)(double, double, double);
typedef double (*noise4Dptr)(double, double, double, double);

typedef double (*noiseNDptr)(int, double[]);

typedef union NoiseUnion {
    noise2Dptr p2;
    noise3Dptr p3;
    noise4Dptr p4;
    noiseNDptr pn;
} genericNoise;

extern double Noise2D(double x, double y);
extern double Noise3D(double x, double y, double z);
extern double Noise4D(double x, double y, double z, double w);

extern double GBlur1D(double stdDev, double x);
extern double GBlur2D(double stdDev, double x, double y);

extern double Noise(genericNoise func, int len, double args[]);

#endif