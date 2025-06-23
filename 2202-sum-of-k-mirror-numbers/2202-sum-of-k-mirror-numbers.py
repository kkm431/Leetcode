class Solution:
    # Helper function to check if a number is palindrome in base-k
    def is_palindrome(self, num, base):
        digits = []
        while num > 0:
            digits.append(num % base)
            num //= base
        return digits == digits[::-1]

    # Helper to generate palindromic numbers in base-10
    def generate_palindromes(self, length):
        # Odd and even length palindromes
        if length == 1:
            for d in range(1, 10):
                yield d
            return
        half = (length + 1) // 2
        start = 10**(half - 1)
        end = 10**half
        for first_half in range(start, end):
            s = str(first_half)
            if length % 2 == 0:
                pal = int(s + s[::-1])
            else:
                pal = int(s + s[-2::-1])
            yield pal

    def kMirror(self, k: int, n: int) -> int:
        res = []
        length = 1
        while len(res) < n:
            for num in self.generate_palindromes(length):
                if self.is_palindrome(num, k):
                    res.append(num)
                    if len(res) == n:
                        return sum(res)
            length += 1
        return sum(res)
