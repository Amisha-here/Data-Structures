// Program to convert infix notation to postfix notation in c++ using stacks

#include<iostream>
#include<stack>
#include<string>
using namespace std;

// Function to check operand
bool IsOperand(char C) 
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

// Function to check operator
bool IsOperator(char C)
{
	if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
		return true;

	return false;
}

// Function to get operator precedence
int PrecedenceWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	case '$':
		weight = 3;
	}
	return weight;
}

// Function to perform an operation and return output
int PrecedenceCheck(char op1, char op2)
{
	int op1Weight = PrecedenceWeight(op1);
	int op2Weight = PrecedenceWeight(op2);

	if(op1Weight == op2Weight)
	{
		if(op1 != '$') return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

string InfixToPostfix(string input);

int main() 
{
	string input; 
	cout<<"Enter Infix Expression: ";
	getline(cin,input);
	string postfix = InfixToPostfix(input);
	cout<<"The postfix expression is: "<<postfix<<"\n";
}

string InfixToPostfix(string input)
{
	stack<char> S;
	string postfix = ""; 
	for(int i = 0; i< input.length(); i++) {

		if(input[i] == ' ' || input[i] == ',') continue; 

		else if(IsOperator(input[i])) 
		{
			while(!S.empty() && S.top() != '(' && PrecedenceCheck(S.top(),input[i]))
			{
				postfix+= S.top();
				S.pop();
			}
			S.push(input[i]);
		}

		else if(IsOperand(input[i]))
		{
			postfix +=input[i];
		}

		else if (input[i] == '(') 
		{
			S.push(input[i]);
		}

		else if(input[i] == ')') 
		{
			while(!S.empty() && S.top() !=  '(') {
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while(!S.empty()) {
		postfix += S.top();
		S.pop();
	}

	return postfix;
}
