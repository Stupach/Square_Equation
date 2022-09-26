#include <stdio.h>
#include <math.h>
#include <assert.h>

struct Coefficient{
	double a;
	double b;
	double c;
};	
struct Answer{
	double ad1;
	double ad2;
};

enum ROOTS_COUNT { // ROOTS_COUNT roots_const = NO_ROOTS 
	NO_ROOTS, // const int NO_ROOTS = 3, ...
	ONE_ROOT,
	TWO_ROOTS = 2,
	INF_ROOTS = -1
};

enum COMPARISON_ZERO {
	ABOUT_ZERO = -2,
	NOT_ABOUT_ZERO = -3
};

void reading(Coefficient *coef); //reads coefficients from the console

int solve(Coefficient *coef, Answer *ans); //solves the quadratic equation

int solve_linear(Coefficient *coef, Answer *ans); //solves a linear equation

int is_zero(double e); //compares with zero

void print_results(int count_results, Answer ans); //outputs the number of solutions and their values