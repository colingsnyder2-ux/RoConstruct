// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, const char *);

struct S_func_00933014
{
    void f();
};

void S_func_00933014::f()
{
    char *p = (char *)this + 0x3a8;
    func_007f49a4(p, 0x5c, 8, "h MN");
}
