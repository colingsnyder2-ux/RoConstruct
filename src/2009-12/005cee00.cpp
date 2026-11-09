// from server: 100% by atomic.potato
extern "C" void __cdecl sub_005cc730(void* a, void* b, int c);

struct S
{
};

void __cdecl f(void* a, void* b, int c)
{
    if (c != 4)
    {
        sub_005cc730(a, b, c);
        return;
    }

    *(unsigned long*)b = 0x00b25b28;
    *((unsigned char*)b + 4) = 0;
    *((unsigned char*)b + 5) = 0;
}
