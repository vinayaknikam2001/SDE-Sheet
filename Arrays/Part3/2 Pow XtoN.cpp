// LeetCode link = https://leetcode.com/problems/powx-n/description/
// Referenced 


double myPow(double x, int n) 
{
	double ans = 1.0; 
	long long nc =  n<0 ? ((long long)-1 * (long long)n) : (long long)n;
	while (nc > 0)
	{
		if (nc&1)
		{
			ans *= x;
			--nc;
		}
		else
		{
			x = x * x;
			nc /= 2;
		}
	}
	
	return n < 0 ? ((double)1.0 / (double)ans) : ans;
	
}