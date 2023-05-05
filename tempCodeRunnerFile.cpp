i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            while (!st.empty() && s[st.top()] != '(') {
                cout << s[st.top()] << ' ';
                st.pop();
            }
            st.pop();
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            cout << s[i] << ' ';
        } else {
            while (!st.empty() && calc(s[st.top()]) <= calc(s[i])) {
                cout << s[st.top()] << ' ';
                st.pop();
            }
            st.push(i);
        }
    }