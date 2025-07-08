
// 22.Generate parenthesis

//  time complexitiy of this code os O(2^2n*2*n) and space complexity is going to be O(2n)+O(n)

class Solution {
public:

    bool isValidParenthesis(string &s){
        int n=s.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')' && !st.empty()){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();

    }
    
    void solve(string &curr,int n){
        if(curr.size()==2*n){
            if(isValidParenthesis(curr)){
                result.push_back(curr);
                return;
            }
            return;
        }
        curr.push_back('(');
        solve(curr,n);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n);
        curr.pop_back();

    }
    vector<string>result;
    vector<string> generateParenthesis(int n) {
        string curr="";
        solve(curr,n);
        return result;
    }
};