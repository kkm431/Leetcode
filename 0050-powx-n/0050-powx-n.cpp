class Solution {
public:
    double myPow(double x, int n) {
        long long N = n; // To handle INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;

        while (N > 0) {
            if (N % 2 == 1) {  // If the current bit is 1
                result *= x;
            }
            x *= x;
            N /= 2;
        }

        return result;
    }
};