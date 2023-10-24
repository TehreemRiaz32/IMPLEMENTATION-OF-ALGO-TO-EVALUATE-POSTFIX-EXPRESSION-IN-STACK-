#include <iostream>
#include <stack>
#include <string>
using namespace std; 

class Postfix {
public:
    Postfix(const string& expression) : postfixExpression(expression) {}

    int evaluate() {
        stack<int> stack;

        for (char ch : postfixExpression) {
            if (isdigit(ch)) {
                stack.push(ch - '0');
            }
            else if (isOperator(ch)) {
                int operand2 = stack.top();
                stack.pop();
                int operand1 = stack.top();
                stack.pop();

                int result = performOperation(operand1, operand2, ch);
                stack.push(result);
            }
        }

        if (!stack.empty()) {
            return stack.top();
        }
    }

private:
    string postfixExpression;

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/';
    }

    int performOperation(int operand1, int operand2, char op) {
        switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 == 0) {
                throw runtime_error("Division by zero");
            }
            return operand1 / operand2;
        default:
            throw runtime_error("Invalid operator");
        }
    }
};

int main() {
    string postfixExpression = "23+5*6+";
    Postfix evaluator(postfixExpression);

        int result = evaluator.evaluate();
        cout << "Result: " << result << endl;
 

    return 0;
}
