/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

Example 1:

Input: "3+2*2"
Output: 7
Example 2:

Input: " 3/2 "
Output: 1
Example 3:

Input: " 3+5 / 2 "
Output: 5
Note:

You may assume that the given expression is always valid.
Do not use the eval built-in library function.
*/




class Solution {
private:
    int prior(int ch) {
        switch(ch) {
            case '$': return 0;
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2;
        }
        return -1;
    }
    bool checkOperator(string op) {
        vector<string> operators = {"+", "-", "*", "/"};
        for (string o : operators)
            if (op == o) return true;
        return false;
    }
public:
    int calculate(string s) {
        string calc;
        vector<string> postorder;
        for (char ch : s) {
            if (ch != ' ')
                calc += ch;
        }
        stack<char> opers({'$'});
        string num;
        for (char ch : calc) {
            if (ch >= '0' and ch <= '9')
                num += ch;
            else {
                postorder.push_back(num);
                num = "";
                if (prior(ch) > prior(opers.top()))
                    opers.push(ch);
                else {
                    while (prior(ch) <= prior(opers.top())) {
                        string op;
                        op += opers.top();
                        opers.pop();
                        postorder.push_back(op);
                    }
                    opers.push(ch);
                }
            }
        }
        postorder.push_back(num);
        while (opers.size() > 1) {
            string op;
            op += opers.top();
            postorder.push_back(op);
            opers.pop();
        }
        stack<int> numStack;
        for (string expr : postorder) {
            if (!checkOperator(expr))
                numStack.push(stoi(expr));
            else {
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numStack.top();
                numStack.pop();
                if (expr == "+")
                    numStack.push(num2+num1);
                else if (expr == "-")
                    numStack.push(num2-num1);
                else if (expr == "*")
                    numStack.push(num2*num1);
                else if (expr == "/")
                    numStack.push(num2/num1);
            }
        }
        return numStack.top();
    }
};
