// from server: 100% by atomic.potato
extern "C" void __cdecl target(int, int, int);

struct S
{
};

void __cdecl f(int a, int b, int c)
{
    if (c != 4)
    {
        target(a, b, c);
        return;
    }

    unsigned char* p = (unsigned char*)b;
    *(unsigned long*)p = 0x00b8a198;
    p[4] = 0;
    p[5] = 0;
}
