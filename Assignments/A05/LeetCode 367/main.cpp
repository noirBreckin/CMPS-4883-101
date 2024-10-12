class Solution {
public:
    bool isPerfectSquare(int num) {
    if (num < 2) return true;  // 0 and 1 are perfect squares
        
        int left = 2, right = num / 2;  // start the search between 2 and num/2
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long midSquared = (long long)mid * mid;  // to avoid overflow
            
            if (midSquared == num) {
                return true;  // found the perfect square
            } else if (midSquared < num) {
                left = mid + 1;  // search in the right half
            } else {
                right = mid - 1;  // search in the left half
            }
        }
        
        return false;  // no perfect square found
    }
};
