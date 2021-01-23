#include <iostream>
#include <string>
#include <stack>
#include <list>

#include "LinkedList.h"

using namespace std;


bool SymbolMatch(string str) 
{ 
	stack<char> stack;

	for (int i = 0; i < str.size(); ++i)
	{
		if (str[i] == ('{'))
			stack.push('{');

		if (str[i] == ('('))
			stack.push('(');

		if (str[i] == ('['))
			stack.push('[');

		if (str[i] == '}' && stack.top() != '{')
		{
			return false;
		}
		else if (str[i] == '}' && stack.top() == '{')
		{
			stack.pop();
		}

		if (str[i] == ')' && stack.top() != '(')
		{
			return false;
		}
		else if (str[i] == ')' && stack.top() == '(')
		{
			stack.pop();
		}

		if (str[i] == ']' && stack.top() != '[')
		{
			return false;
		}
		else if (str[i] == ']' && stack.top() == '[')
		{
			stack.pop();
		}

	}
	if (!stack.empty())
		return false;
	return true;
	
}

int main()
{

	cout << SymbolMatch("(2 + 2) * 8 {2 + 2]") << endl; // Should return false (missing
	cout << SymbolMatch("(2 + 2 * 8 {2 + 2}") << endl; // Should return false (missing ')')
	cout << SymbolMatch("(2 + 2)") << endl; // Should return true
	cout << SymbolMatch("2 + 2")<< endl; // Should return true


	LinkedList<int> list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PushBack(5);

	list.Insert(30, 20);

	list.Remove(6);
	list.Remove(2);

	list.Display();
	
	
	return 0;
}