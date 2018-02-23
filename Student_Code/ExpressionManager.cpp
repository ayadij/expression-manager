#include "ExpressionManager.h"

ExpressionManager::ExpressionManager()
{

}

ExpressionManager::~ExpressionManager(){}

bool isbracket(string bracket)
{
	if(bracket == "(" || bracket == "[" || bracket == "{" || bracket == ")" || bracket == "]" || bracket == "}"){
		return true;
	}
	else return false;
}


bool isleft(string bracket)
{
	if(bracket == "(" || bracket == "[" || bracket == "{"){
			return true;
		}
		else return false;
}


bool isright(string bracket)
{
	if(bracket == ")" || bracket == "]" || bracket == "}"){
			return true;
		}
		else return false;
}


bool issign(string sign)
{
	if(sign == "+" || sign == "-" || sign == "*" || sign == "/" || sign == "%"){
		return true;
	}
	else return false;
}


bool isnumber(string numberstring)
{
	stringstream numbercheck(numberstring);

	int intnumber;
	double doublenumber;

	numbercheck >> doublenumber;
	intnumber = doublenumber;

	if((doublenumber - intnumber) > 0){
		return false;
	}
	else if(numbercheck.fail()){
		return false;
	}
	else return true;
}


bool postfixvalidity(string infix)
{
	stringstream validitycheck(infix);
	cout << infix << endl;

	string characters;
	int number = 0;
	int sign = 0;

	while (validitycheck >> characters){
		if(isnumber(characters)){
			number++;
		}
		else if(issign(characters)){
			sign++;
		}
	}
	cout << "number of numbers: " << number << " number of operators: " << sign << endl;
	if(sign == (number - 1)){
		return true;
	}
	else return false;
}


int precedence(string signstring){
	int value = 0;
	if(signstring == "*"){ value = 2; }
	if(signstring == "/"){ value = 2; }
	if(signstring == "%"){ value = 2; }
	if(signstring == "+"){ value = 1; }
	if(signstring == "-"){ value = 1; }
	return value;
}


void ExpressionManager::signProcess(string operatorstring)
{

	if(operators.empty() || isleft(operators.top())){ //If the stack is empty or if a left bracket is on the top
		operators.push(operatorstring);//automatically add the operator to the stack
	}

	else if(isright(operatorstring)){//if the operator is a right bracket,
		while(!isleft(operators.top())){   //it pops all operators on the stack until a left bracket is found and pops the left bracket
			output = output + operators.top() + " ";
			operators.pop();
		}
		operators.pop();
	}

	else {
  		if(isbracket(operatorstring) || (precedence(operatorstring) > precedence(operators.top()))){
			operators.push(operatorstring);
		}
 		else{
			while(!operators.empty() && (precedence(operatorstring) <= precedence(operators.top()))){
				output += operators.top();
				output += " ";
				operators.pop();
			}
			operators.push(operatorstring);
		}
	}
}



// PART 1 //
bool ExpressionManager::isBalanced(string expression)
{
	stringstream brackets(expression);
	string left;
	stack<string> bracketstack;
	while (brackets >> left){

			if(left == "(" || left == "[" || left == "{"){
				bracketstack.push(left);
			}
			else if(isnumber(left)||issign(left)){
				continue;
			}
			if(!bracketstack.empty()){
			if (left == ")"){
				if (bracketstack.top() == "("){
					bracketstack.pop();
				}
				else return false;
			}
			else if (left == "]"){
						if (bracketstack.top() == "["){
							bracketstack.pop();
						}
						else return false;
					}
			else if (left == "}"){
						if (bracketstack.top() == "{"){
							bracketstack.pop();
						}
						else return false;
					}
		}
			else return false;
	}
	if (!bracketstack.empty()){
		return false;
	}
	return true;
}

// PART 3 //
string ExpressionManager::postfixToInfix(string postfixExpression)
{
	if(!postfixvalidity(postfixExpression)){//if brackets are not balanced
	cout << "The postfix Expression: " << postfixExpression << " is invalid" << endl;
	return "invalid";
	}
	cout << "valid" << endl;
	stringstream read(postfixExpression);
	string incharacter; //string containing the expression
	stack<string> stringstack; //string stack to store the expressions

	while (read >> incharacter){
		if (stringstack.empty() && !isnumber(incharacter)){
			cout << "invalid" << endl;
			return "invalid";
		}
		else if(isnumber(incharacter)){
			stringstack.push(incharacter);
			cout << stringstack.top() << " was added to the top of the stack." << endl;
		}
		else if(issign(incharacter) && (stringstack.size() < 2)){
			return "invalid";
		}
		else if(issign(incharacter)){
			string result;
			string first = stringstack.top();
				stringstack.pop();
				//cout << "First: " << first << endl;
			string second = stringstack.top();
				stringstack.pop();
				//cout << "Second: " << second << endl;

			switch(incharacter[0]){
			case '+': result = "( " + second + " " + "+" + " " + first + " " + ")"; break;
			case '-': result = "( " + second + " " + "-" + " " + first + " " + ")"; break;
			case '*': result = "( " + second + " " + "*" + " " + first + " " + ")"; break;
			case '/': result = "( " + second + " " + "/" + " " + first + " " + ")"; break;
			case '%': result = "( " + second + " " + "%" + " " + first + " " + ")"; break;
			}
			stringstack.push(result);
			cout << "top of the stack" << stringstack.top() << endl;
			}
		}
		return stringstack.top();
}

// PART 2 //
string ExpressionManager::infixToPostfix(string infixExpression)
{
	//	do i need to clear my stack here or what?
	while(!operators.empty()){
		operators.pop();
 	}
	output.clear();

	if(!postfixvalidity(infixExpression) || !ExpressionManager::isBalanced(infixExpression)){
		cout << "The infix Expression: " << infixExpression << " is invalid" << endl;
		return "invalid";
	}
	cout << "valid: " << endl;
	stringstream read(infixExpression);
	string infixstring; //string containing the infix expression read in from the test driver

	while(read >> infixstring){
		if(isnumber(infixstring)){//if reads in a number
			output = output + infixstring + " "; // adds to output string
			cout << "output: " << output << endl;
		}
		else if (issign(infixstring) || isbracket(infixstring)){///////////////////////////////
			signProcess(infixstring);////////////////////////////////////////////////////
			cout << "output: " << output << endl;
		}
	}
	while(!operators.empty()){
		string operatorsstring = operators.top();
		operators.pop();
		output = output + operatorsstring + " "; // adds to output string
	}
	return output.substr(0, (output.length() - 1));
}

// PART 4 //
string ExpressionManager::postfixEvaluate(string postfixExpression)
{
	if(!postfixvalidity(postfixExpression)){//if brackets are not balanced
		return "invalid";
	}
	cout << "valid" << endl;
	stringstream read(postfixExpression);
	string incharacter;//string containing the expression
	stack<int> numbersstack;//stack to store the numbers

	while(read >> incharacter){
		if(!isnumber(incharacter) && numbersstack.empty()){
			return "invalid";
		}
		//reads in the string expression
		if(isnumber(incharacter)){//if reads a number
			int number;//stores number
			stringstream convert(incharacter);//converter
			convert >> number;//converts i number into an int
			numbersstack.push(number);//pushes int number into the stack
		}
		if(issign(incharacter)){

			int answer;
			int first = numbersstack.top();
				numbersstack.pop();
			//cout << "First: " << first << endl;
			int second = numbersstack.top();
				numbersstack.pop();
			//cout << "Second: " << second << endl;

			switch(incharacter[0]){
			case '+': answer = second + first; break;
			case '-': answer = second - first; break;
			case '*': answer = second * first; break;
			case '%': answer = second % first; break;
			case '/': if(first == 0){ return "invalid"; }
					  answer = second / first; break;
			}
			numbersstack.push(answer);
		}
	}
	int stackanswer = numbersstack.top();//number to convert int a string
	string result;//string which will contain the result
	stringstream convert; // stringstream used for the conversion
	convert << stackanswer;//add the value of stackanswer to the characters in the stream
	result = convert.str();//set result to the content of the stream
	return result;
}



