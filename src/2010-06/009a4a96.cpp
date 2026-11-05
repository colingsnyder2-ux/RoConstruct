// from server: 65% by atomic.potato
extern "C" void __cdecl func_007a8ade(void *, int, int, const char *);

struct S_func_009a4a96
{
    char pad[0xdc];
    void f();
};

void S_func_009a4a96::f()
{
    func_007a8ade((char *)this + 0xdc, 0x1c, 2, "SUVW");
}
