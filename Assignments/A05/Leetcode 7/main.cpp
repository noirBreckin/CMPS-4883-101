#include <limits.h>

class Solution {
public:
    int reverse(int x) {
        int reversed_x = 0; // To store the reversed number

        while (x != 0) {
            int digit = x % 10; // Get the last digit
            x /= 10; // Remove the last digit
            
            // Check for overflow before updating reversed_x
            if (reversed_x > (INT_MAX / 10) || (reversed_x == INT_MAX / 10 && digit > 7)) {
                return 0; // Return 0 in case of overflow
            }
            if (reversed_x < (INT_MIN / 10) || (reversed_x == INT_MIN / 10 && digit < -8)) {
                return 0; // Return 0 in case of underflow
            }

            reversed_x = reversed_x * 10 + digit; // Build the reversed number
        }

        return reversed_x; // Return the reversed integer
    }
};
