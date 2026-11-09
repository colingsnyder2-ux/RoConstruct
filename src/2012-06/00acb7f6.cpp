// from server: 65% by atomic.potato
extern "C" void __cdecl func_00983270(void *, int, int, const char *);

struct S
{
    char pad[0x18];
    void f();
};

void S::f()
{
    func_00983270((char *)this + 0x98, 8, 2, "L$ Q");
}
