// from server: 47% by atomic.potato
extern "C" int __cdecl Call_5e0c40(void*);

struct Local10
{
	int Call(int);
};

struct S
{
	int f(int);
	int* member0c;
	Local10 member10;
};

int S::f(int arg)
{
	int* value = member0c;
	Call_5e0c40(this);
	member10.Call(1);
	return member10.Call(1);
}
