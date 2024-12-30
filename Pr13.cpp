//Implement C++ program for expression conversion as infix to postfix and its evaluation using stack based on given conditions:
//1. Operands and operator, both must be single character.
//2. Input Postfix expression must be in a desired format.
#include <iostream>
using namespace std;

// Custom stack implementation
class Stack {
    char arr[100];
    int top;

public:
    Stack() : top(-1) {}

    void push(char x) {
        if (top < 99) arr[++top] = x;
    }

    char pop() {
        if (top >= 0) return arr[top--];
        return '\0'; // Return null character for empty stack
    }

    char peek() {
        if (top >= 0) return arr[top];
        return '\0'; // Return null character for empty stack
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Custom numeric stack for integers
class IntStack {
    int arr[100];
    int top;

public:
    IntStack() : top(-1) {}

    void push(int x) {
        if (top < 99) arr[++top] = x;
    }

    int pop() {
        if (top >= 0) return arr[top--];
        return 0; // Return 0 for empty stack
    }

    bool isEmpty() {
        return top == -1;
    }
};

// Function to check if a character is alphanumeric
bool isAlnum(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

// Function to compute operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to perform operations
int operate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': {
            int result = 1;
            for (int i = 0; i < b; i++) {
                result *= a;
            }
            return result;
        }
    }
    return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (char ch : infix) {
        if (isAlnum(ch)) {
            postfix += ch; // Append operands directly
        } else if (ch == '(') {
            s.push(ch); // Push '(' to stack
        } else if (ch == ')') {
            // Pop until '('
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove '('
        } else {
            // Handle operators
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    IntStack s;

    for (char ch : postfix) {
        if (isAlnum(ch)) {
            cout << "Enter value of " << ch << ": ";
            int val;
            cin >> val;
            s.push(val); // Push operands to stack
        } else {
            // Pop two operands
            int b = s.pop();
            int a = s.pop();
            s.push(operate(a, b, ch)); // Perform operation and push result
        }
    }

    return s.pop(); // Final result
}

// Main function
int main() {
    string infix;
    cout << "Enter a valid infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}

