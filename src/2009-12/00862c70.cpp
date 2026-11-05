// from server: 100% by atomic.potato
extern "C" int __stdcall sub_00862310(int);

struct S
{
	int f(int, int);
};

int S::f(int a, int b)
{
	sub_00862310(b);
	return 0;
}
