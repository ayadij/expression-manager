#pragma once
#include <string>
#include <stack>
#include <sstream>
#include <iostream>
#include "ExpressionManagerInterface.h"


class ExpressionManager : public ExpressionManagerInterface
{

private:
	string output;

public:

	ExpressionManager();
	~ExpressionManager();

	stack<string> operators;

	bool isBalanced(string expression);//passed
	string postfixToInfix(string postfixExpression);//passed
	string infixToPostfix(string infixExpression);
	string postfixEvaluate(string postfixExpression);//passed
	void signProcess(string operatorstring);



/*
HELP SESSION NOTES



Expression Manager:
virtual bool isBalanced(string expression) = 0;
	do this first
	checking if brackets are correct in infix string
	cheching for valitity with brackets
	taking in a srinf of inf
	making sure (){}[] are balanced
	no order of presidence for the idfferend brackets
	use a stack
	if left add to stack if number jsut continue
	at the end make sure there is nothing left in the stack
	return false if not balanced
	write another function that takes in one function and returns anotheradsfasdfadfasdfafd
	recommended you write your own functions on top ofit
	create a new class ExpressManager();


virtual string infixToPostfix(string infixExpression) = 0;
	do this last
	going to rely on some of the previous functions built
	most involved function

	consider presidence

	have infix string like 3+4*5-(7+2)
	number in string
	operator in stack. when adding operators in stack, consider presidence
	if presidence is less than or equal to the one already in the stakc, pop off existing operator and write it on string operator,
	if greater, push on

	write another function to check if it is valid or not
	by  running through all your operators and numbers . there should be one more number than operator (not inclduing brackets)

	TA: write a function that goes through and makes sure each pairs of symbols


	out put the string you have been buildling



virtual string postfixToInfix(string postfixExpression) = 0;
	do this third
	numbers go into stack
	get to operator, pop in two last strings, all in parenthesis




virtual string postfixEvaluate(string postfixExpression) = 0;
	do this second
	evaluates postfix
	checks if the post fix  string is valid
	also use a stack
	stack of numbers -- run into number put it on the stack
	run into operator, use it on the numbers in the stack to get a new number which youput back into the stack
		can use a swtich statement or function
	if size of the stack at the end is anything greater than one, or have operators left, then invalid
	return as a string the number or "invalid"






	another function to check if something is a bracket, number, or

	#include <stack>
	pretty much all stacks of strings
	stacks of numbers fo rthe evaluator
	do not create stacks as member variables. local variable functions
	localized stacks


	vistual studios makes UML


INFIX
(5+2)*3
POSTFIX
52+3*
invixExpression
	 *
	 *
	 *
	 *
	 *
	int stackanswer = numbersstack.top();//number to convert int a string
	string result;//string which will contain the result
	stringstream convert; // stringstream used for the conversion
	convert << stackanswer;//add the value of stackanswer to the characters in the stream
	result = convert.str();//set result to the content of the stream
	return result;
	 *
	 *
	 *
	 *
	 *			case '+':result = "( " + second + " + " + first + " )";
				cout << "result " << result << endl;
				stringstack.push(result);
				cout << "top of the stack: " << stringstack.top() << endl;
				break;
			case '-':result = "( " + second + " - " + first + " )";
				cout << "result " << result << endl;
				stringstack.push(result);
				cout << "top of the stack: " << stringstack.top() << endl;
				break;
			case '*':result = "( " + second + " * " + first + " )";
				cout << "result " << result << endl;
				stringstack.push(result);
				cout << "top of the stack: " << stringstack.top() << endl;
				break;
			case '/':
				if (first == 0){return "invalid";}
				result = "( " + second + " / " + first + " )";
				cout << "result " << result << endl;
				stringstack.push(result);
				cout << "top of the stack: " << stringstack.top() << endl;
				break;
			case '%':result = "( " + second + " % " + first + " )";
				cout << "result " << result << endl;
				stringstack.push(result);
				cout << "top of the stack: " << stringstack.top() << endl;
				break;
	 *
	 */


};
