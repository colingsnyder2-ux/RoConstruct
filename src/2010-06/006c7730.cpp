// from server: 100% by atomic.potato
extern "C" void __cdecl sub_6c7170(void*, void*, int);

struct S
{
    void __cdecl f(void*, int);
};

void __cdecl S::f(void* a, int b)
{
    if (b != 4)
    {
        sub_6c7170(this, a, b);
        return;
    }

    *(unsigned long*)a = 0x00bd1310;
    *((unsigned char*)a + 4) = 0;
    *((unsigned char*)a + 5) = 0;
}
