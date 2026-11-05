// from server: 67% by atomic.potato
struct S
{
    unsigned char pad0[0x20];
    void* p20;
    unsigned char pad1[0x0c];
    unsigned char flag30;
    unsigned char pad2[0x23];
    void* pffffff54;
    void f(void*, void*);
};

void S::f(void* a, void* b)
{
    if (flag30 != 0)
    {
        typedef void (__thiscall *M)(S*, void*, void*);
        M m = (M)*(void**)((char*)pffffff54 + 0x5c);
        m((S*)((char*)this - 0xac), (char*)this + 0x20, 0);
        flag30 = 0;
    }
}
