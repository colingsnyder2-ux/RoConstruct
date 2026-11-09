// from server: 100% by atomic.potato
struct S
{
	void __stdcall f(void *);
};

extern "C" void __cdecl sub_471330(void *, void *);

void __stdcall S::f(void *p)
{
	sub_471330(p, (void *)0x9aaca8);
}
