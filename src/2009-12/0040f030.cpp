// from server: 100% by atomic.potato
extern "C" void __cdecl sub_4717d0(void *, void *, void *, void *);

struct S
{
	void __stdcall f(void *, void *, void *);
};

void __stdcall S::f(void *a, void *b, void *c)
{
	sub_4717d0(a, b, c, (void *)0x9aaca8);
}
