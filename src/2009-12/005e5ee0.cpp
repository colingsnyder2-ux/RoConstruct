// from server: 100% by atomic.potato
extern "C" void __stdcall sub_007f49a4(void*, int, int, const void*);

struct S
{
    void f();
};

void S::f()
{
    sub_007f49a4((char*)this + 24, 4, 16, (const void*)0x4e4d20);
}
