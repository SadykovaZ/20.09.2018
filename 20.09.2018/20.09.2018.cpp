// 20.09.2018.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
ifstream my_file;
int buf_size = 0, cur_size = 0;
struct flat
{
	int number : 7;
	int room_number : 3;

	double area;
	void enter()
	{
		int tvar;
		cout << "Введите номер квартиры, количество комнат и их площадь: ";
		cin >> tvar;
		number = tvar;
		cin >> tvar;
		room_number = tvar;
		cin >> area;
	}
	void print()
	{
		cout << "Номер квартиры: " << number << " Количество комнат: " << room_number << " Площадь: " << area;
	}
};

struct home
{
	int number;
	int flat_number = 0;
	int fn_buffer = 0;
	flat *flats;


	void add(flat f)
	{
		if (fn_buffer == 0)
		{
			fn_buffer = 2;
			flats = new flat[fn_buffer];
			flats[flat_number++] = f;
		}
		else
		{
			if (flat_number < fn_buffer)
			{
				flats[flat_number++] = f;
			}
			else
			{
				flat* tmp = new flat[fn_buffer * 2];
				for (int i = 0; i < fn_buffer; i++)
				{
					tmp[i] = flats[i];
				}

				delete[] flats;
				flats = tmp;
				fn_buffer *= 2;
				flats[flat_number++] = f;
			}
		}

	}
	void enter()
	{
		cout << "Номер дома: ";
		cin >> number;
	}

	void print()
	{

		cout << "Номер дома :" << number << endl;
		for (int i = 0; i < flat_number; i++)
		{
			flats[i].print();
			cout << endl;
		}
	}
	void empty()
	{
		delete[] flats;
	}
};

struct Student
{
	string name;
	int m1 : 2;
	int m2 : 2;
	int m3 : 2;
	int m4 : 2;
	int m5 : 2;
	int m6 : 2;
	int m7 : 2;
	int m8 : 2;
	int m9 : 2;
	int m10 : 2;

	void enter()
	{
		int tvar;

		my_file >> name;
		my_file >> tvar;
		m1 = tvar;
		my_file >> tvar;
		m2 = tvar;
		my_file >> tvar;
		m3 = tvar;
		my_file >> tvar;
		m4 = tvar;
		my_file >> tvar;
		m5 = tvar;


	}

	void print()
	{
		cout << "Имя студента: " << name << endl;
		cout << "Оценки " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
	}


	int find()
	{
		int total_sum = 0;
		double average = 0;
		total_sum = m1 + m2 + m3 + m4 + m5;
		average = ((double)total_sum / 5) * 100;
		return average;
		//cout << "Сумма = " << total_sum << " " << "Средний бал = " << average << "%" << endl;
	}


};
void print_d(Student* ss)
{
	for (int i = 0; i < cur_size; i++)
	{
		if (ss[i].find() < 50)
		{
			ss[i].print();

		}
	}
}
void add(Student* &ss, Student s)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		ss = new Student[buf_size];

	}
	else
	{
		if (cur_size >= buf_size)
		{
			Student* tmp = new Student[buf_size * 2];
			for (int i = 0; i < buf_size; i++)
			{
				tmp[i] = ss[i];
			}
			delete[] ss;
			ss = tmp;
			buf_size *= 2;
		}
	}
	ss[cur_size++] = s;
}
void print_by_name(Student*ss)
{
	string name1;
	cin >> name1;

	for (int i = 0; i < cur_size; i++)
	{
		if (ss[i].name == name1)
		{
			ss[i].print();
			break;
		}
	}

}

int main()
{
	setlocale(LC_ALL, "Rus");

	my_file.open("example1.txt", ios::in);
	Student s1;
	Student *ss = new Student;
	int t;
	my_file >> t;
	for (int i = 0; i < t; i++)
	{
		s1.enter();
		add(ss, s1);
	}
	cout << " 1 - для печати \n 2 - для вывода оценок определенного студента,\n 3 - для печати должников,\n 0 - выхода. " << endl;
	int choice = 0;
start:
	cin >> choice;
	switch (choice)
	{
	case 1:
	{		
		for (int i = 0; i < cur_size; i++)
		{
			ss[i].print();
		}
	}
	break;
	case 2:
	{
		cout << "Вывести оценки определенного студента" << endl;
		print_by_name(ss);
	}
	break;
	case 3:
	{
		cout << "Должники: " << endl;
		print_d(ss);
	}
	break;
	case 4:
	{
		for (int i = 0; i < cur_size; i++)
		{
			ss[i].print();
		}
	}
	break;

	}
	if (choice != 0)
		goto start;



	//s1.print();
	/*estudent.sum();*/


	//cout << sizeof(flat) << endl;
	/*home ehome;
	flat f;
	ehome.enter();
	int choice;
	bool flag = false;
	while (true)
	{
		cout << "Введите 1 для добавления новой квартиры, 0 - чтобы прервать ввод. " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			f.enter();
			ehome.add(f);
		}
		break;
		default:
			flag = true;
			break;
		}
		if (flag) break;

	}

	ehome.print();
	ehome.empty();*/

	delete[]ss;


	system("pause");
	return 0;
}

