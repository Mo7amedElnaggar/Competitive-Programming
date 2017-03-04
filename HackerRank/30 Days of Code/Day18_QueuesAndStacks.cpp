#include <bits/stdc++.h>

using namespace std ;
typedef long long ll ;

class Solution {
public :
    stack<char> st ;
    queue <char> que ;
    void pushCharacter(char ch){
        st.push(ch);
    }
    void enqueueCharacter(char ch){
        que.push(ch) ;
    }
    char popCharacter(){
        char ch = st.top() ;
        st.pop() ; // remove top
        return ch ;
    }
    char dequeueCharacter(){
        char ch = que.front() ;
        que.pop() ;
        return ch ;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt" , "rt" , stdin) ;
    //freopen("output.txt" , "wt" , stdout) ;
#endif
    // read the string s.
    string s;
    getline(cin, s);

    // create the Solution class object p.
    Solution obj;

    // push/enqueue all the characters of string s to stack.
    for (int i = 0; i < s.length(); i++) {
        obj.pushCharacter(s[i]);
        obj.enqueueCharacter(s[i]);
    }

    bool isPalindrome = true;

    // pop the top character from stack.
    // dequeue the first character from queue.
    // compare both the characters.
    for (int i = 0; i < s.length() / 2; i++) {
        if (obj.popCharacter() != obj.dequeueCharacter()) {
            isPalindrome = false;

            break;
        }
    }

    // finally print whether string s is palindrome or not.
    if (isPalindrome) {
        cout << "The word, " << s << ", is a palindrome.";
    } else {
        cout << "The word, " << s << ", is not a palindrome.";
    }

    return 0 ;
}
