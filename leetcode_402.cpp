class Solution {
public:
    string removeKdigits(string num, int k) {
        if (k >= num.size()) {
            return "0";
        }
        
        string stack;
        
        for (char c : num) {
            while (k && !stack.empty() && stack.back() > c) {
                stack.pop_back();
                k--;
            }
            stack.push_back(c);
        }
        
        while (k) {
            stack.pop_back();
            k--;
        }
        
        string ans = "";
        bool leadingZero = true;
        for (char c : stack) {
            if (c == '0' && leadingZero) {
                continue;
            }
            leadingZero = false;
            ans.push_back(c);
        }
        
        return ans.empty() ? "0" : ans;
    }
};
