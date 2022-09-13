#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <assert.h>

#define INF_ROOTS -1
#define ABOUT_ZERO -2
#define NOT_ABOUT_ZERO -3
#define inaccuracy 1E-6

struct Coefficient{
	double a;
	double b;
	double c;
};	
struct Answer{
	double ad1;
	double ad2;
};
int solve(Coefficient coef, Answer *ans);
int line_f(Coefficient coef, Answer *ans);
int is_zero(double e);

int solve(Coefficient coef, Answer *ans)
{
    if (is_zero(coef.a) == ABOUT_ZERO)
    {
        return line_f(coef, ans);
    }

    else
    {
        assert(isfinite(coef.a));
        assert(isfinite(coef.b));
        assert(isfinite(coef.c));

        double d = coef.b * coef.b - 4 * coef.a * coef.c;

        if (is_zero(d) == ABOUT_ZERO) 
        {
            ans->ad1 = (-1) * coef.b / (2 * coef.a);
            return 1;
        }

        else if (d < 0)
        {
            return 0;
        }
        else
        {
            ans->ad1 = ( (-1) * coef.b - sqrt(d) ) / (2 * coef.a);
            ans->ad2 = ( (-1) * coef.b + sqrt(d) ) / (2 * coef.a);
			
			if (ans->ad1 == ans->ad2) 
			{
				return 1;
			}	
			else
			{	
				return 2;
			}
        }

    }
};

int line_f(Coefficient coef, Answer * ans)
    {
        if (is_zero(coef.b) == ABOUT_ZERO)
        {
            if (is_zero(coef.c) == ABOUT_ZERO)
            {
                return INF_ROOTS;
            }
            else
            {
                return 0;
            }

        }
        else
        {
            ans->ad1 = (-1) * coef.c / coef.b;
            return 1;
        }
    }
int is_zero(double e)
{
    if ( fabs(e) < inaccuracy )
    {
        return ABOUT_ZERO;
    }
    else
    {
        return NOT_ABOUT_ZERO;
    }
};

Coefficient reading()
{
	//найти здесь подводные камни
	scanf("%lf %lf %lf", &coef.a, &coef.b, &coef.c);
	return coef;
};

int main()
{
    setlocale(LC_ALL, "");

    Coefficient coef; Answer ans;
	coef.a = 0; coef.b = 0; coef.c = 0; ans.ad1 = 0; ans.ad2 = 0;
	
	reading();
	
    assert(isfinite(coef.a));
    assert(isfinite(coef.b));
    assert(isfinite(coef.c));

    int count_results = solve(coef, &ans);
	switch(count_results)
    {
        case 0:
            printf("нет корней");
            break;

        case 1:
            printf("1 корень: %lf", ans.ad1);
            break;

        case 2:
            printf("2 корня: %lf, %lf", ans.ad1, ans.ad2);
            break;

        case INF_ROOTS:
            printf("бесконечное число корней");
            break;

        default:
            printf("ошибка, неизвестное число корней %d\n", count_results);
    }

    return 0;
 }






