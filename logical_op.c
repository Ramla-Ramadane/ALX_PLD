#include <stdio.h>
/*just explaining how logical op works for someone*/

int main(void)
{
	int m = 40, n = 20;
	int o = 20, p = 30;
	
	if (m > n && m != 0)
	{
		printf("&& operator : Both conditions are true\n");
	}
	if (o > p || p != 20)
	{
		printf("|| operator: Only one condition is true\n");
	}
	if (!(m > n && m != 0))
	{
		printf("! Operator: Both conditions are true\n");
	}
	else
	{
		printf("! Operator: Both conditions are true. But  status is inverted as false\n");
	}
	return (0);
}
