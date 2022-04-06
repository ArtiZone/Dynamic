#include <iostream>
using namespace std;
#include "Header.h"
#include <string>

int fillStackSequence(elem*& stack, string str)
{
	/*
	cout << int('(') << " " << int(')') << " " << int('[') << " " << int(']') << " " << int('{') << " " << int('}') << " " << int('<') << " " << int('>') << endl;
	int** brackets = new int* [8];
	for (int i = 0; i < 8; i++) {
		brackets[i] = new int[2];
	}
	for (int i = 0 ; i < 0; i++)
	*/
	int k = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '[' || str[i] == '(' || str[i] == '<' || str[i] == '{' || str[i] == ']' || str[i] == ')' || str[i] == '>' || str[i] == '}') {
			if (str[i] == ']' || str[i] == ')' || str[i] == '>' || str[i] == '}') {
				char val;
				if (int(*peek(stack)) + 2 == int(str[i]) || int(*peek(stack)) + 1 == int(str[i])) {
					pop(stack, str[k]);
				}
				else {
					cout << "Trouble!!! You have wrong closed bracket " << str[i] << " in " << i + 1 <<" place!" << endl;
					pop(stack, str[k]);
					k = 1;
				}
			}
			else {
				push(stack, str[i]);
				k = i;
			}
		}
		
	}
	return k;
}

void Exercise(elem*& stack)
{
	string str = "";
	cin >> str;
	// [((3+7}*20)>
	cout << str.size() << endl;
	int f = fillStackSequence(stack, str);
	if (!f) {
		cout << "You have the right position for brackets" << endl;
	}
}
//Функуия заполнения стека подряд идущими натуральными числами

//Функция вывода содержимого стека на экран
void showStack(elem*& stack)
{
	while (stack)
	{
		char val;
		if (pop(stack, val)) //Если элемент из стека получен, выводим на экран
		{
			cout << val << ((stack) ? " " : "\n");
		}
	}
}void main()
{

	elem* stack = nullptr;
	Exercise(stack);
	//showStack(stack);
	clear(stack); //В данном примере функцию можно не использовать, поскольку стек 
	//очищается после отображения на экране
	system("pause");
}
