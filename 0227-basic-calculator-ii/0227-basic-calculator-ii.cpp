class Solution {
public:
    int precedence(char c) {
        if(c=='-' || c=='+') {
            return 1;
        }
        if(c=='*' || c=='/') {
            return 3;
        }
        return 5;
    }
    int solve(int a, int b, char op) {
        if(op=='/') {
            return a/b;
        }
        else if(op=='*') {
            return a*b;
        }
        else if(op=='+') {
            return a+b;
        }
        else if(op=='-') {
            return a-b;
        }
        else {
            return 1;
        }
    }
    int calculate(string s) {
        vector<int> post;
        stack<char> st;
        int i=0;
        while(i<s.length()) {
            if(s[i]==' ') {
                i++;
            }
            else if(s[i]>='0' && s[i]<='9') {
                string k = "";
                while(i<s.length() && s[i]>='0' && s[i]<='9') {
                    k+=s[i];
                    i++;
                }
                post.push_back(stoi(k));
            }
            else {
                while(!st.empty() && precedence(st.top())>=precedence(s[i])) {
                    char c = st.top();
                    st.pop();
                    int val = solve(post[post.size()-2], post[post.size()-1], c);
                    post.pop_back();
                    post.pop_back();
                    post.push_back(val);
                }
                st.push(s[i]);
                i++;
            }
        }
        while(!st.empty()) {
            char c = st.top();
            st.pop();
            int val = solve(post[post.size()-2], post[post.size()-1], c);
            post.pop_back();
            post.pop_back();
            post.push_back(val);
        }
        return post[0];
    }
};