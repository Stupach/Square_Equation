#include "sqr_head.h"

int main()
{
    Coefficient coef; Answer ans;
	ans.ad1 = 0; ans.ad2 = 0;
	
	reading(&coef);

	int count_results = solve(&coef, &ans);
    print_results(count_results, ans);
	
    return 0;
};