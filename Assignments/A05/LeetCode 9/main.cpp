class Solution {
public:
    bool isPalindrome(int x) {
        // Check for negative numbers and numbers that end with 0 (but not 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversed_half = 0;
        while (x > reversed_half) {
            reversed_half = reversed_half * 10 + x % 10; // Build the reversed half
            x /= 10; // Remove the last digit from x
        }

        // Check if the number is equal to its reversed half
        return x == reversed_half || x == reversed_half / 10; // Handle odd-length numbers
    }
};
