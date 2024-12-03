class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        //Process potential whitespace
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        //Process +- Signs
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            i++;
        }
///////////////////////////////////////////////////////////////////////////
        //Handle decimals/dots
        bool isNumberBeforeDot = false;
        while (i < s.size() && isdigit(s[i])) {
            i++;
            isNumberBeforeDot = true;
        }
        bool isNumberAfterDot = false;
        if (i < s.size() && s[i] == '.') {
            i++;
            while (i < s.size() && isdigit(s[i])) {
                i++;
                isNumberAfterDot = true;
            }
        }
        if (!isNumberBeforeDot && !isNumberAfterDot) {
            return false;
        }
///////////////////////////////////////////////////////////////////////////
        //Handles scientific notation 'e'
        if (i < s.size() && (s[i] == 'e' || s[i] == 'E')) {
            i++;
            bool isNumberAfterE = false;

            if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
                i++;
            }

            while (i < s.size() && isdigit(s[i])) {
                i++;
                isNumberAfterE = true;
            }

            if (!isNumberAfterE) {
                return false;
            }
        }

        return i == s.size();
    }
};
