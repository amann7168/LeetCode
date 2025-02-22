class Solution {
public:
    bool isNumber(const string& str) {
        if (str.empty()) return false;
        if (str == "+" || str == "D" || str == "C") return false;
        if (str.size() > 1 && (str[0] == '+' || str[0] == '-')) {
            return all_of(str.begin() + 1, str.end(), ::isdigit);
        }
        return all_of(str.begin(), str.end(), ::isdigit);
    }

    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for(int i = 0; i < ops.size(); i++) {
            if (isNumber(ops[i]))  ans.push_back(stoi(ops[i]));
            else if (ops[i] == "+") {
                if (ans.size() >= 2) {
                    int s2 = ans[ans.size() - 1] + ans[ans.size() - 2];
                    ans.push_back(s2);
                }
            }
            else if (ops[i] == "D") {
                if (!ans.empty()) {
                    int m = ans.back() * 2;
                    ans.push_back(m);
                }
            }
            else if (ops[i] == "C") {
                if (!ans.empty()) {
                    ans.pop_back();
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < ans.size(); i++) {
            sum += ans[i];
        }
        return sum;
    }
};

