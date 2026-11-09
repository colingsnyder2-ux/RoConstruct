// from server: 77% by atomic.potato
struct S
{
	int f(int);
};

int S::f(int p)
{
	struct T
	{
		int a;
		int b;
	};

	T* q = (T*)p;
	int* x = *(int**)((char*)q + 0x10);
	if (x != 0)
	{
		int* y = *(int**)((char*)q + 0x14);
		if (y != 0 && x != y)
		{
			int* r = *(int**)((char*)this + 8);
			((void (__thiscall *)(int*, T*))(*(int**)((char*)r) + 0x0c))(r, q);
		}
	}
	return 0;
}
