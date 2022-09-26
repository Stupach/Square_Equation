#include "sqr_head.h"

int solve(Coefficient *coef, Answer *ans)
{
	// нет проверок на нулевые указатели (через ассерты)
	assert(isfinite(coef->a));
    assert(isfinite(coef->b));
    assert(isfinite(coef->c));
	
    if (is_zero(coef->a) == ABOUT_ZERO)
    {
        return solve_linear(coef, ans); 
    }
    else
    {
        double d = coef->b * coef->b - 4 * coef->a * coef->c;

        if (is_zero(d) == ABOUT_ZERO) 
        {
			ans->ad1 = ( (coef->b / (2 * coef->a)) == 0 ) ? 0 : - coef->b / (2 * coef->a);
            return 1;
        }
        else if (d < 0)
        {
            return 0;
        }
        else
        {
			double sqr_discr = sqrt(d);
            ans->ad1 = ( -coef->b - sqr_discr ) / (2 * coef->a); 
            ans->ad2 = ( -coef->b + sqr_discr ) / (2 * coef->a);
			
			return 2;
        }

    }
};

int solve_linear(Coefficient *coef, Answer *ans)
{
	assert(isfinite(coef->a));
    assert(isfinite(coef->b));
    assert(isfinite(coef->c));
	
	if (is_zero(coef->b) == ABOUT_ZERO)
	{
		return (is_zero(coef->c) == ABOUT_ZERO) ? INF_ROOTS : 0;

	}
	else
	{
		ans->ad1 = ( (coef->c / coef->b) == 0 ) ? 0 : - coef->c / coef->b;
		
		return 1;
	}
};

int is_zero(double e)
{	
	const double inaccuracy = 1e-5;
	return (fabs(e) < inaccuracy) ? ABOUT_ZERO : NOT_ABOUT_ZERO;
	
	//return cond ? value_if_true : value_if_false;
};

void reading(Coefficient* coef)
{
	coef->a = 0; coef->b = 0; coef->c = 0;
	printf("enter coefficients:\n");
	while (scanf("%lf %lf %lf", &(coef->a), &(coef->b), &(coef->c)) != 3)
	{	
		while(getchar() != '\n') {} // clearing input buffer after scanf
		
		printf("try to enter coefficients again\n");
		
	};
};

void print_results(int count_results, Answer ans)
{
	switch(count_results)
    {
        case ONE_ROOT:
            printf("1 root: %lf\n", ans.ad1);
            break;

        case TWO_ROOTS:
            printf("2 roots: %lf, %lf\n", ans.ad1, ans.ad2);
            break;
		case NO_ROOTS:
            printf("no roots\n");
            break;

        case INF_ROOTS:
            printf("infinite number of roots\n");
            break;

        default:
            printf("error: unknown number of roots %d\n", count_results);
    }
}