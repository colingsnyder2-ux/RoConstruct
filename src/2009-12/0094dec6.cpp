// from server: 78% by atomic.potato
struct S_0094dec6
{
    int value;

    void func();
};

extern "C" void __stdcall func_007f49a4(void *, int, int, const void *);

void S_0094dec6::func()
{
    func_007f49a4((char *)this + 0xa4, 8, 2, (const void *)0x52e530);
}
