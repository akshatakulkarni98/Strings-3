// Time Complexity : O(N) where N=Length of string
// Space Complexity : O(N) 
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this : No
//This problem uses stack for the signs and calculated the output.

class Solution {
public:
    int calculate(string s) {
        if(s.length()==0){
            return 0;
        }
        stack<double> st;
        double num = 0;
        char last_sign = '+';
        
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                num = num * 10 + s[i]-'0';
            }
            if((!isdigit(s[i]) && s[i]!=' ')|| i==s.length()-1){
                if(last_sign=='+'){
                    st.push(num);
                }
                else if(last_sign=='-'){
                    st.push(-num);
                }
                else if(last_sign=='*'){
                    int temp = st.top() * num;
                    st.pop();
                    st.push(temp);
                }
                else if(last_sign == '/'){
                    int temp = st.top() / num;
                    st.pop();
                    st.push(temp);
                }
                num = 0;
                last_sign = s[i];
            }
        }
        int res = 0;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
        
        
        
    }
};
