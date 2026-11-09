// from server: 100% by atomic.potato
extern "C" void __stdcall sub_405560(void *, const void *, void *, void *);

struct CComObjectNoLock
{
	void f(void *, void *, void *);
};

void CComObjectNoLock::f(void *a, void *b, void *c)
{
	sub_405560(a, (const void *)0x9a117c, b, c);
}
