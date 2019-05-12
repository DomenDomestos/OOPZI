// OOPZI_task5.cpp: определяет точку входа для приложения.
//
using namespace std;
#include <iostream>


class Stack_na_osnove_massiva
{
public:
	Stack_na_osnove_massiva()
	{
		arr = new int[0];
		length = 0;
	}
	~Stack_na_osnove_massiva()
	{
		delete[] arr;
	}
	//Вернуть длину
	int GetSize()
	{
		return length;
	}
	//Вернуть элемент
	int GetElement(int n)
	{
		if (n < length)
		{
			return arr[n];
		}
		else
		{
			return -1;
		}
	}
	Stack_na_osnove_massiva &operator=(const Stack_na_osnove_massiva &other);
	//Впихнуть новый элемент
	void Push(int d)
	{
		//У нас есть пустой массив, размерами на 1 больше исходного
		int *a = new int[length + 1];
		//заполняем пустой массив данными, уже существующими
		for (int i = 0; i < length; i++)
		{
			a[i] = arr[i];
		}
		//Заполняем последнюю ячейку данными, которые были получены
		a[length] = d;
		//Здесь потребуется переопределение оператора присваивания
		//Присваиваем нашему постоянному массиву данные не очень постоянного.
		length++;
		arr = new int[length];

		for (int i = 0; i < length; i++)
		{
			arr[i] = a[i];
		}
		//удаляем не очень постоянный
		delete[] a;
	}
	//Вынуть последний элемент (в соответствии с понятием стака)
	int Pop()
	{
		//У нас есть пустой массив, размерами на 1 меньше исходного
		int *a = new int[length - 1];

		//заполняем пустой массив данными, уже существующими, окромя последнего. 
		//Который умирает.
		for (int i = 0; i < length - 1; i++)
		{
			a[i] = arr[i];
		}
		//Присваиваем нашему постоянному массиву данные не очень постоянного.
		length--;
		arr = new int[length];

		for (int i = 0; i < length; i++)
		{
			arr[i] = a[i];
		}
		//удаляем не очень постоянный
		delete[] a;

		if (length != 0)
		{
			return arr[length-1];
		}
		else
		{
			return -1;
		}
	}
	int Peek()
	{
		//Вернем головной элемент. То есть, arr[length-1]
		if (length != 0)
		{
			return arr[length-1];
		}
		else
		{
			return -1;
		}
	}
	void ret()
	{
		for (int i = 0; i < GetSize(); i++)
		{
			cout <<i << " " << GetElement(i) <<endl;
		}
		cout << " " << Peek() << endl;
	}

private:
	int length;
	int *arr;
};
Stack_na_osnove_massiva &Stack_na_osnove_massiva::operator=
(const Stack_na_osnove_massiva &drugoi_stack)
{
	/*	Мы должны:
	1) Удалить предыдущий массив.
	2) Создать новый по размерам другого.
	3) Расширить свой размер на размер другого.
	4) Заполнить его данными.
	*/
	if (this == &drugoi_stack)
	{
		return *this;
	}
	delete[] arr;
	arr = new int[length + 1];
	length = drugoi_stack.length;

	for (int i = 0; i < length; i++)
	{
		arr[i] = drugoi_stack.arr[i];
	}
}
ostream &operator<<(ostream &stream, Stack_na_osnove_massiva &instance)
{
	for (int i = 0; i < instance.GetSize(); i++)
	{
		stream << i << " " << instance.GetElement(i) << "\n";
	}
	stream <<" " << instance.Peek() << "\n";
	return stream;
}

