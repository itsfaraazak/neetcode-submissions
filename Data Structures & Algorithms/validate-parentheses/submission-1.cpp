class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else if (stack.empty() && (c == ')' || c == '}' || c == ']')) {
                return false;
            } else if ((c == ')' && stack.top() == '(')
                        || (c == '}' && stack.top() == '{')
                        || (c == ']' && stack.top() == '[')) {
                stack.pop();
            } else {
                return false;
            }
        }
        return stack.empty();
    }
};
