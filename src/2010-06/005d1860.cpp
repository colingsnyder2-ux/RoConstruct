// from server: 100% by atomic.potato
typedef unsigned char BYTE;

extern "C" void __cdecl target_5d08e0(int, int, int);

void f(int a, int* p, int n)
{
    if (n != 4)
    {
        target_5d08e0(a, (int)p, n);
        return;
    }

    p[0] = 0xba8ff0;
    ((BYTE*)p)[4] = 0;
    ((BYTE*)p)[5] = 0;
}
