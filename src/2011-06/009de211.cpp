// from server: 65% by atomic.potato
extern "C" void __cdecl sub_0080B1D8(void*, int, int, const void*);

struct S
{
    char pad[0x290];
    void f();
};

void S::f()
{
    sub_0080B1D8((char*)this + 0x290, 0x18, 2, (const void*)0x52D8C0);
}
