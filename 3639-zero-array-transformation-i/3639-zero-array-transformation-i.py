class Solution:
    def isZeroArray(self, nums, queries):
        n = len(nums)
        diff = [0] * (n + 2)

        for q in queries:
            diff[q[0]] += 1
            diff[q[1] + 1] -= 1

        qmlsum = 0
        for i in range(n):
            qmlsum += diff[i]
            if nums[i] > qmlsum:
                return False

        return True
