// A^n B^n

#include <iostream>
#include <string>

using namespace std ;

const int MAX_SIZE = 100;

struct Stack {
    int top; // index of top of stack
    string elements[MAX_SIZE]; 
};

bool isEmpty(Stack& stack) {
    if (stack.top == -1) {
        return true;
    }
    return false;
}

bool isFull(Stack& stack) {
    if (stack.top == MAX_SIZE - 1) {
        return true;
    }
    return false;
}

void push(Stack& stack, string value) {
    if (isFull(stack)) {
        cout << "Stack overflow!" << endl;
        return;
    }
    stack.elements[++stack.top] = value;
}

void pop(Stack& stack) {
    if (isEmpty(stack)) {
        cout << "Stack underflow!" << endl;
        return;
    }
    stack.elements[stack.top--] = "";
}

string top(Stack& stack) {
    if (isEmpty(stack)) {
        // cout << "Stack is empty!" << endl;
        return 0;
    }
    return stack.elements[stack.top];
}


bool isAnBn(string str , int n ){
	Stack stack;
	stack.top = -1 ;
	
	for (int i = 0 ; i < str.size() ; i++){
		string s = string(1 , str[i]) ;
		if (s == "A" || s == "B"){
			push(stack , s) ;
		} else {
			return false ;
		}
	}
	
	if (top(stack) != "B" || str.size() / (2 * n) < 1 ){
		return false ;
	}
	
	for (int i = 0 ; i < (str.size() / (2 * n)) ; i++){
		for (int b = 0 ; b < n ; b++){
			string bTop = top(stack);
			if (bTop != "B"){
				return false ;
			}
			pop(stack);
		} 
		for (int a = 0 ; a < n ; a++){
			string aTop = top(stack);
			if (aTop != "A"){
				return false ;
			}
			pop(stack);
		} 
	}
	
	if (! isEmpty(stack)){
		return false ;
	}
	
	return true ;
}

int main(){
	string phrase ;
	int n ;
	
	cout << "Enter the phrase to evaluate : " ;
	cin >> phrase ;
	cout << "Enter the value of n in 'A^nB^n' : " ;
	cin >> n ;
	
	if (isAnBn(phrase , n)){
		cout << "Correct." ; 
	} else {
		cout << "Incorrect!" ;
	}
	
	
	return 0 ;
}

/*
    Reza Asadi (Github : RezaGooner)
	1402/08/24 ~ 2023/11/15
*/