// from server: 35% by atomic.potato
struct S_func_00917610
{
};

extern "C" void __cdecl sub_00917610(void *, void *, void *);

struct S_func_00917946
{
	void f(void *, void *, void *);
};

void S_func_00917946::f(void *a, void *b, void *c)
{
	sub_00917610(a, b, c);
}
