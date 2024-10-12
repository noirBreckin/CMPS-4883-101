class Solution {
public:
    double myPow(double x, long long n) {
     // Handle the case when n is 0, any number raised to the power of 0 is 1
        if (n == 0) return 1.0;
        
        // Handle the case when n is negative by converting the problem to a positive exponent
        if (n < 0) {
            x = 1 / x;
            n = -n;  // Make n positive
        }
        
        return power(x, n);
    }
    
private:
    // Helper function to compute x^n using exponentiation by squaring
    double power(double x, long long n) {
        if (n == 0) return 1;  // Base case: x^0 = 1
        double half = power(x, n / 2);  // Recurse for x^(n/2)
        if (n % 2 == 0) {
            return half * half;  // If n is even
        } else {
            return half * half * x;  // If n is odd
        }
    }
};
