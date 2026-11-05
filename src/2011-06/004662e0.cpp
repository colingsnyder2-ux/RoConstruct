// from server: 68% by atomic.potato
struct S
{
	double f();
};

double S::f()
{
	struct T
	{
		double (*p)(void*);
		void* q;
	};

	T* t = (T*)*(void**)0;
	return t->p(t->q);
}
