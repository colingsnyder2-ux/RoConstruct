// from server: 38% by atomic.potato
struct S
{
    int f();
};

extern "C" void __cdecl call_006c7390(int);

int S::f()
{
    int ebx = 0;
    if (*(unsigned char *)((char *)this + 0x14) != (unsigned char)ebx)
    {
        call_006c7390(*(int *)((char *)this - 0x24));
        *(int *)((char *)this - 4) = ebx;
        return 0x5048f5;
    }
    return 0;
}
