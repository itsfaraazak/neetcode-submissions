class Solution { 
public:
    bool isPalindrome(string s) {
       int i = 0;
       int j = s.size() - 1;
       while (i < j && i < s.size() && j >= 0) {
        // if not alphanumeric, then return 0. else return non zero
        if (std::isalnum(s[i]) == 0) {
            i++;
            continue;
        }
        if (std::isalnum(s[j]) == 0) {
            j--;
            continue;
        }
        char currentForward = std::tolower(s[i]);
        char currentBackward = std::tolower(s[j]);

        std::cout << "Comparing: " << currentForward << ", " << currentBackward << '\n';

        if (currentForward == currentBackward) {
            i++;
            j--;
            continue;
        }
        return false;
       }
       return true;
    }
};
