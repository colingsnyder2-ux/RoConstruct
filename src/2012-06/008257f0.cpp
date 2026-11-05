// from server: 46% by atomic.potato
struct S_func_00750a60
{
	char pad0[436];
	int m_x;
	int* f();
};

int* S_func_00750a60::f()
{
	return &m_x;
}

extern "C" int* __stdcall call_00750a60(int*);
extern "C" int __stdcall call_00822df0(int*, int, int);

struct S
{
	int f(int*, int, int);
};

int S::f(int* p, int a, int b)
{
	S_func_00750a60* q = 0;
	if (p)
		q = (S_func_00750a60*)((char*)p - 28);
	int* r = call_00750a60((int*)q);
	return call_00822df0(r, a, b);
}
