// OOPZI_task5.cpp: определяет точку входа для приложения.
//

#include "OOPZI_task5.h"

using namespace std;


template < typename ALL_DATA >
struct dannie
{
	ALL_DATA * NECHTO;
	template <typename T1> friend  ostream& operator << (ostream &, const dannie<T1> &);
	operator int() const
	{
		return (int)NECHTO;
	}
};

template< typename ALL_DATA>
ostream & operator<<(ostream & os, 
	const dannie<ALL_DATA> & rhs)
{
	os << rhs.NECHTO;
	
	return os;
}




class Stack_na_osnove_massiva
{
public:
	Stack_na_osnove_massiva()
	{
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
	dannie<int> GetElement(int n)
	{
		if (n < length)
		{
			return arr[n];
		}
		else
		{
			return { new int(-1) };
		}
	}
	Stack_na_osnove_massiva operator=(const Stack_na_osnove_massiva drugoi_stack)
	{
		/*	Мы должны:
		1) Удалить предыдущий массив.
		2) Создать новый по размерам другого.
		3) Расширить свой размер на размер другого.
		4) Заполнить его данными.
		*/
		delete[] arr;
		dannie<int>arr[] = { new int(*drugoi_stack.arr) };
		length = drugoi_stack.length;

		for (int i = 0; i < length; i++)
		{
			arr[i] = drugoi_stack.arr[i];
		}
	}
	//Впихнуть новый элемент
	void Push(dannie<int> d)
	{
		//У нас есть пустой массив, размерами на 1 больше исходного
		int *p_darr = new int[length+1];
		dannie<int> a[] = { new int(*p_darr) };
		length++;
		//заполняем пустой массив данными, уже существующими
		for (int i = 0; i < length; i++)
		{
			a[i] = arr[i];
		}
		//Заполняем последнюю ячейку данными, которые были получены
		a[length] = d;
		//Здесь потребуется переопределение оператора присваивания
		//Присваиваем нашему постоянному массиву данные не очень постоянного.

		dannie<int>arr[] = { *a };

		//удаляем не очень постоянный
		//delete[] a;
	}
	//Вынуть последний элемент (в соответствии с понятием стака)
	dannie<int> Pop()
	{
		//У нас есть пустой массив, размерами на 1 меньше исходного
		int *p_darr = new int[length - 1];
		dannie<int> a[] = { new int(*p_darr) };

		//заполняем пустой массив данными, уже существующими, окромя последнего. 
		//Который умирает.
		for (int i = 0; i < length - 1; i++)
		{
			a[i] = arr[i];
		}
		//Присваиваем нашему постоянному массиву данные не очень постоянного.
		dannie<int>arr[] = { *a };
		//удаляем не очень постоянный
		delete[] a;

		if (length != 0)
		{
			return arr[length-1];
		}
		else
		{
			return { new int(-1) };
		}
	}
	dannie<int> Peek()
	{
		//Вернем головной элемент. То есть, arr[length-1]
		if (length != 0)
		{
			return arr[length-1];
		}
		else
		{
			return{ new int(-1) };
		}
	}

private:
	int length;
	dannie<int> arr[0];
};

ostream &operator<<(ostream &stream, Stack_na_osnove_massiva &instance)
{
	for (int i = 0; i < instance.GetSize(); i++)
	{
		stream << i << " " << instance.GetElement(i) << "\n";
	}
	stream <<" " << instance.Peek() << "\n";
	return stream;
}

int main()
{
	Stack_na_osnove_massiva sm;
	sm.Push({new int(11)});
	sm.Push({ new int(15) });
	cout << sm << endl;
	return 0;
}
