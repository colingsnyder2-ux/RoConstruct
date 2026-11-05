// from server: 20% by atomic.potato
extern "C" void __cdecl sub_005d8cd0(float);

struct S
{
	void sub_005db8c0();
	int f(void *, int, float *);
};

void S::sub_005db8c0()
{
}

int S::f(void *p, int count, float *values)
{
	int i = 0;
	while (i < count)
	{
		sub_005d8cd0(values[i]);
		sub_005db8c0();
		values[i] = values[i];
		++i;
	}
	return 0;
}
