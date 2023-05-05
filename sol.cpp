#include <bits/stdc++.h>

using namespace std;

#define task "sol"

int calc(char v) {
    if (v == '+' || v == '-') {
        return 1;
    }
    if (v == '*' || v == '/') {
        return 2;
    }
    if (v == '^') {
        return 3;
    }
    return -1;
    assert(false);
}

string Infix2Postfix(string infix) {
    string s = infix, ans = "";
    s = '(' + s + ')';
    stack<int> st;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            while (!st.empty() && s[st.top()] != '(') {
                ans += s[st.top()];
                ans += ' ';
                st.pop();
            }
            assert(!st.empty());
            st.pop();
        } else if (s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
            if (i + 1 < (int) s.size() && s[i + 1] >= '0' && s[i + 1] <= '9') {

            } else {
                ans += ' ';
            }
        } else {
            assert(calc(s[i]) != -1);
            while (!st.empty() && calc(s[st.top()]) >= calc(s[i])) {
                ans += s[st.top()];
                ans += ' ';
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}

string Infix2Prefix(string infix) {
    string s = '(' + infix + ')', ans = "";
    stack<int> st;

    for (int i = (int) s.size() - 1; i >= 0; --i) {
        if (s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
            if (!(i && s[i - 1] >= '0' && s[i - 1] <= '9')) {
                ans += ' ';
            }
        } else if (s[i] == ')') {
            st.push(i);
        } else if (s[i] == '(') {
            while ((int) st.size() && s[st.top()] != ')') {
                ans += s[st.top()];
                ans += ' ';
                st.pop();
            }
            st.pop();
        } else {
            while ((int) st.size() && s[st.top()] != ')' && calc(s[st.top()]) > calc(s[i])) {
                ans += s[st.top()];
                ans += ' ';
                st.pop();
            }
            st.push(i);
        }
    }
    ans.pop_back();
    reverse(ans.begin(), ans.end());
    return ans;
}

double cal(double a, double b, char op) {
    if (op == '-') {
        return a - b;
    }
    if (op == '*') {
        return a * b;
    }
    if (op == '+') {
        return a + b;
    }
    if (op == '/') {
        return a / b;
    }
    return pow(a, b);
}

string PostfixPrefixCalculator(string input) {
    bool pre = (calc(input.back()) != -1);
    if (pre) {
        string &s = input;
        stack<double> numbers;

        for (int i = 0; i < (int) s.size(); ++i) {
            if (calc(s[i]) != -1) {
                double val2 = numbers.top();
                numbers.pop();
                double val1 = numbers.top();
                numbers.pop();
                numbers.push(cal(val1, val2, s[i]));
            } else if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                string temp;
                while (j < (int) s.size() && s[j] >= '0' && s[j] <= '9') {
                    temp += s[j];
                    j++;
                }
                i = j - 1;
                int val = 0;
                for (char c: temp) {
                    val = val * 10 + c - '0';
                }
                numbers.push(val);
            }
        }
        double value = numbers.top();
        value = round(value * 10000.0) / 10000.0;
        string ans = to_string(value);

        while (ans.back() == '0') {
            ans.pop_back();
        }
        if (ans.back() == '.') {
            ans.pop_back();
        }
        while (!numbers.empty()) {
            numbers.pop();
        }
        return ans;
    } else {
        stack<double> numbers;
        string s = input;
        for (int i = (int) s.size() - 1; i >= 0; --i) {
            if (calc(s[i]) != -1) {
                double u = numbers.top();
                numbers.pop();
                double v = numbers.top();
                numbers.pop();
                numbers.push(cal(u, v, s[i]));
            } else if (s[i] != ' ') {
                int j = i;
                string t;
                while (j >= 0 && s[j] >= '0' && s[j] <= '9') {
                    t += s[j];
                    j--;
                }
                i = j + 1;
                reverse(t.begin(), t.end());
                int val = 0;
                for (char c: t) {
                    val = val * 10 + c - '0';
                }
                numbers.push(val);
            }
        }
        double value = numbers.top();
        value = round(value * 10000.0) / 10000.0;
        string ans = to_string(value);

        while (ans.back() == '0') {
            ans.pop_back();
        }
        if (ans.back() == '.') {
            ans.pop_back();
        }
        while (!numbers.empty()) {
            numbers.pop();
        }
        return ans;
    }
}

void gogo() {
    string s;
    getline(cin, s);
    cout << PostfixPrefixCalculator(s) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(task ".inp", "r")) {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    gogo();
}
