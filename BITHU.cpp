#include <bits/stdc++.h>

using namespace std;

#define task "bithu"
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define zs(v) ((int)(v).size())
#define BIT(x, i) (((x) >> (i)) & 1)
#define CNTBIT __builtin_popcountll
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;

const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const int dxx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dyy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const ll mod = 1000000007; /// 998244353
const ll base = 331;

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

void gogo() {
    string s;
    cin >> s;
    s = '(' + s + ')';
    stack<int> st;
    for (int i = 0; i < (int) s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            while (!st.empty() && s[st.top()] != '(') {
                cout << s[st.top()] << ' ';
                st.pop();
            }
            assert(!st.empty());
            st.pop();
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i] << ' ';
        } else {
            assert(calc(s[i]) != -1);
            while (!st.empty() && calc(s[st.top()]) >= calc(s[i])) {
                cout << s[st.top()] << ' ';
                st.pop();
            }
            st.push(i);
        }
    }
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
