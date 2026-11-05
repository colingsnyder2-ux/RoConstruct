// from server: 91% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl CallA(void *, unsigned int, unsigned int, const void *);
extern "C" void __cdecl CallB(void *);

struct S
{
    int pad0;
    int pad1;
    int pad2;
    void *value;
    void f();
};

void S::f()
{
    void *p = value;
    if (p)
    {
        CallA((char *)p + 8, 0x18, 0x28, (const void *)0x558db0);
        CallB(p);
    }
}
