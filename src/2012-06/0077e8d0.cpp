// from server: 84% by atomic.potato
struct S
{
    void f();
};

void S::f()
{
    ((unsigned int*)this)[0] = 0x00bb0ebc;
    ((unsigned int*)this)[1] = 0x00bb0eb0;
    ((unsigned int*)((char*)this + 0x18))[0] = 0x00bb0ea4;
    ((unsigned int*)((char*)this + 0x1c))[0] = 0x00bb0e98;
    ((void (__stdcall *)(void))0x685090)();
}
