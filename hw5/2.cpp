#include <iostream>
#include <stack>
#include <string>

#include "container_cout.h"


using std::cout, std::endl, std::string, std::stack;


string solve(string s)
{
    stack<char> st;

    for (char x : s)
    {
        if ((x == '}') or (x == ']') or (x == ')'))
        {
            if (x == '}')
            {
                if (st.empty())
                    return "No";

                if (st.top() == '{') 
                    if (!st.empty()) st.pop();
                else
                    return "No";
            }

            if (x == ']')
            {
                if (st.empty())
                    return "No";

                if (st.top() == '[') 
                    if (!st.empty()) st.pop();
                else
                    return "No";
            }

            if (x == ')')
            {
                if (st.empty())
                    return "No";

                if (st.top() == '(') 
                    if (!st.empty()) st.pop();
                else
                    return "No";
            }
        }
        else
            st.push(x);
    }


    if (st.empty())
        return "Yes";
    else
        return "No";
}

int main()
{
    string s1 = "(()())";
    string s2 = ")(";
    string s3 = "([{}])";
    string s4 = ")}]";
    string s5 = "[}";
    string s6 = "([)]";
    string s7 = "({}[]([]))[]";
    string s8 = "[]";

    cout << s1 << " " << solve(s1) << endl;
    cout << s2 << " " << solve(s2) << endl;
    cout << s3 << " " << solve(s3) << endl;
    cout << s4 << " " << solve(s4) << endl;
    cout << s5 << " " << solve(s5) << endl;
    cout << s6 << " " << solve(s6) << endl;
    cout << s7 << " " << solve(s7) << endl;
    cout << s8 << " " << solve(s8) << endl;

    return 0;
}