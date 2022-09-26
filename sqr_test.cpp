#include "sqr_head.h"

int main()
{
    Coefficient coef; Answer ans;
	int count_results;
	ans.ad1 = 0; ans.ad2 = 0;
	
	double t[9][6] = {{1, 2, 1, 1, -1, 0}, 
		{0, 0, 0, -1, 0, 0}, 
		{0, 0, 1, 0, 0, 0}, 
		{0, 1, -2, 1, 2, 0}, 
		{1, -5, 6, 2, 2, 3}, 
		{1, -5, 10, 0, 0, 0}, 
		{1, -10, 5, 2, 5 - 2 * sqrt(5), 5 + 2 * sqrt(5)}, 
		{0, 1, 0, 1, 0, 0}, 
		{1, 0, 0, 1, 0, 0}};

	for(int y = 0; y < 9; y ++)
	{
		coef.a = t[y][0]; coef.b = t[y][1];  coef.c = t[y][2];
		count_results = solve(&coef, &ans);
		
		if ((count_results == t[y][3])&&(is_zero(ans.ad1 - t[y][4]) == ABOUT_ZERO)&&(is_zero(ans.ad2 - t[y][5]) == ABOUT_ZERO))
		{
			printf("test %d completed\n", y + 1);
		}
		else
		{
			printf("test %d uncompleted. Expected data look like:\n", y + 1);
			
			for (int x = 0; x < 3; x++)
				printf("%0.1lf ", t[y][x]);
			printf("\n");
			for (int x = 3; x < 6; x++)
				printf("%0.1lf ", t[y][x]);
			printf("\n");
			
			printf("Received data look like:\n");
			print_results(count_results, ans);
			printf(" ");
			printf("%0.1lf %0.1lf\n", ans.ad1, ans.ad2);
			
		}
		ans.ad1 = 0; ans.ad2 = 0;
	}
	
    return 0;
};