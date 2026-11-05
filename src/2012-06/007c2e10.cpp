// from server: 80% by atomic.potato
extern "C" int __cdecl GlobalDispatch(void*);

struct S
{
    int f();
};

volatile unsigned char g_flag;

int S::f()
{
    if (g_flag)
        return 0x100;

    int* p = *(int**)((char*)this + 0x84);
    return GlobalDispatch((char*)this + 0x84 + *p);
}
