// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, void *);

struct S
{
	void f();
};

void S::f()
{
	func_007f49a4((void *)((char *)this + 0x1b8), 0x0c, 2, (void *)0x4d62e0);
}
