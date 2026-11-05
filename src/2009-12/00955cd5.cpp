// from server: 65% by atomic.potato
struct S_func_00955cd5
{
    char pad[0x1b8];

    void func();
};

extern "C" void __cdecl func_007f49a4(void *, int, int, void *);

void S_func_00955cd5::func()
{
    func_007f49a4((char *)this + 0x1b8, 0x0c, 2, (void *)0x4d62e0);
}
