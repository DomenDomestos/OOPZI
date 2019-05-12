#include "head.h"
int main()
{
	Stack_na_osnove_massiva sm;
	cout << "!!!!" << endl;
	sm.Push(11);
	sm.Push(12);
	sm.Push(11);
	sm.Push(5555);
	//sm.ret();
	sm.Pop();
	sm.Push(6666);
	//sm.ret();
	return 0;
}