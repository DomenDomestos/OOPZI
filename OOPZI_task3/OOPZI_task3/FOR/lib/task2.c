#include <math.h>
double summ2(double eps)
{
	double end = 0;
	int u = 0;
	for (; fabs(u) <= eps;)
	{
		end += pow(-1, u) / ((u + 1)*(u + 2)*(u + 3));
		++u;
	}
	return end;
}
//double summ2(double eps)
//{
//	double end = 0;
//	int u = 0;
//	while (fabs(end) <= eps)
//	{
//		end += u;
//		++u;
//	}
//	return end;
//}
//double summ2(double eps)
//{
//	double end = 0;
//	int u = 0;
//	do
//	{
//		end += u;
//		++u;
//	} while (fabs(end) <= eps);
//	return end;
//}