// from server: 70% by atomic.potato
typedef unsigned char byte;

extern "C" void __cdecl Function852fd0(int, void *, int);

struct S
{
    void __cdecl f(void *, int);
};

void S::f(void *a, int b)
{
    if (b != 4)
    {
        Function852fd0(0, a, b);
        return;
    }

    *(unsigned long *)a = 0x00de2898;
    ((byte *)a)[4] = 0;
    ((byte *)a)[5] = 0;
}
