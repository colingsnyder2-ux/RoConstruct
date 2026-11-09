// from server: 100% by atomic.potato
struct C
{
	void __thiscall call_6f1030(int, int, int, int, int);
};

extern "C" void __cdecl call_7f4929(int);

struct S
{
	void f();
};

void S::f()
{
	((C *)0xb941c8)->call_6f1030(0x9d2010, 0x9bb084, 0x98, 0xf, 0);
	call_7f4929(0x986c60);
}
