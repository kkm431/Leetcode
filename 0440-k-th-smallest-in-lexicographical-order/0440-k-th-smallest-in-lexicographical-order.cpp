class Solution {
public:
    long long getCount(long long prefix, long long n) {
        long long count = 0;
        long long curr = prefix;
        long long next = prefix + 1;

        while (curr <= n) {
            count += min(n + 1LL, next) - curr;
            curr *= 10;
            next *= 10;
        }

        return count;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k -= 1; // because we start from 1

        while (k > 0) {
            long long count = getCount(curr, n);
            if (count <= k) {
                curr += 1;
                k -= count;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return (int)curr;
    }
};
