// from server: 57% by atomic.potato
extern "C" int __stdcall CloseHandle(void *);

struct S
{
    int f();
};

int S::f()
{
    *(int *)this = 0xbd4d54;
    int *p = (int *)((char *)this + 0x30);
    int h = *p;
    *p = 0;
    if (h)
        CloseHandle((void *)h);
    return ((int (__thiscall *)(void *))0x864d90)((char *)this + 8);
}
