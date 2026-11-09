// from server: 65% by atomic.potato
extern "C" void __cdecl func_007f49a4(void *, int, int, const void *);

struct S_func_00955ff8
{
    void *value;

    void func();
};

void S_func_00955ff8::func()
{
    func_007f49a4((char *)value + 0x34, 0x18, 4, (const void *)0x522c10);
}
