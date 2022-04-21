
#include<iostream> 
#include<string> 
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

struct man
{
	string name;
	string sex;
	int age;
	string work;
	int income;
	string aim;
};

struct elem
{
	man m;
	elem* next = nullptr;
};

struct queue
{
	elem* head = nullptr;
	elem* tail = nullptr;
	size_t size = 0;
};

man create_elem(string name, string sex, int age, string work, int income, string aim) {
	man human;
	human.name = name;
	human.sex = sex;
	human.age = age;
	human.work = work;
	human.income = income;
	human.aim = aim;
	return human;
}

void enqueue(queue*& q, string n, string s, int a, string w, int i, string ai) {
	man human = create_elem(n, s, a, w, i, ai);
	elem* newelem = new elem;
	newelem->m = human;
	if (q->size == 0) {
		q->head = q->tail = newelem;
	}

	else {
		q->tail->next = newelem;
		q->tail = newelem;
	}
	q->size++;
}

bool dequeue(queue*& q, man& human) {
	if (q->size == 0) {
		return false;
	}
	elem* rem = q->head;
	human = rem->m;
	q->head = q->head->next;
	delete rem;
	q->size--;
	return true;
}

void To_file(queue*& q, string name_of_file) {
	man human;
	ofstream fout(name_of_file);
	while (dequeue(q, human)) {
		//cout << human.name << " " << human.sex << " " << human.age << " " << human.work << " " << human.income << " " << human.aim << endl;
		fout << human.name << " " << human.sex << " " << human.age << " " << human.work << " " << human.income << " " << human.aim << endl;
		//return &(human.name, human.sex, human.age, human.work, human.work, human.income, human.aim);
	}
	fout.close();
}

void clear(queue*& q) {
	while (q->size > 0) {
		elem* rem = q->head;
		q->head = q->head->next;
		q->size--;
		delete rem;
	}
}

int main() {
	queue* deposit = new queue;
	queue* credite = new queue;
	ifstream f("input.txt");
	ofstream fout("output.txt");
	while (!f.eof()) {
		char* data;
		string str = "";
		string name = "";
		string sex = "";
		string age = "";
		string work = "";
		string income = "";
		string aim = "";
		int age_i = 0;
		int income_i = 0;
		getline(f, str);
		int flag = 0;
		for (int i = 0; i < size(str); i++) {
			if (str[i] == ' ') {
				flag++;
			}
			if (flag < 3) {
				name += str[i];
			}
			else if (flag == 3 && str[i] != ' ') {
				sex += str[i];
			}
			else if (flag == 4 && str[i] != ' ') {
				age += str[i];
			}
			else if (flag == 5 && str[i] != ' ') {
				age_i = atoi(age.c_str());
				work += str[i];
			}
			else if (flag == 6 && str[i] != ' ') {
				income += str[i];
			}
			else if (flag == 7 && str[i] != ' ') {
				income_i = atoi(income.c_str());
				aim += str[i];
			}
		}
		if (aim == "deposite") {
			enqueue(deposit, name, sex, age_i, work, income_i, aim);
		}
		else {
			enqueue(credite, name, sex, age_i, work, income_i, aim);
		}
		//cout << str << endl;
		//cout << name << sex << age_i << work << income << aim << endl;

	}
	To_file(deposit, "deposite.txt");
	To_file(credite, "credit.txt");
	//Show(credite);
}

