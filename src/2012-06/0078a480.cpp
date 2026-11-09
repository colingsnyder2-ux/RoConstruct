// from server: 80% by atomic.potato
extern "C" void __cdecl target(int);

struct S
{
};

void __cdecl f(int value, int* p)
{
    if (value != 4)
    {
        target(value);
    }
    else
    {
        *(int*)p = 0xdc0ca0;
        ((char*)p)[4] = 0;
        ((char*)p)[5] = 0;
    }
}
