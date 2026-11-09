// from server: 100% by atomic.potato
struct S
{
};

extern "C" void __cdecl sub_005cc9d0(void*, int, int);

void __cdecl f(void* a, int b, int c)
{
    if (c != 4)
    {
        sub_005cc9d0(a, b, c);
        return;
    }

    *(unsigned long*)b = 0x00b25ed0;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
