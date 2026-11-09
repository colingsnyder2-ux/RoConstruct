// from server: 64% by atomic.potato
struct S
{
	void __cdecl f(float *a, float *b);
};

void S::f(float *a, float *b)
{
	float *p = a;
	float *q = b;

	if (p == q)
		return;

	while (p != q)
	{
		p -= 2;
		q -= 2;
		p[0] = q[0];
		p[1] = q[1];
	}
}
