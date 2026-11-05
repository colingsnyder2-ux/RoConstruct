// from server: 100% by atomic.potato
extern "C" void __cdecl sub_00975830(void*, void*, int);

struct S_00975db0
{
    void __cdecl f(void*, int);
};

void __cdecl S_00975db0::f(void* a, int b)
{
    if (b != 4)
        sub_00975830(this, a, b);
    else
    {
        *(int*)a = 0x00e022f8;
        *((char*)a + 4) = 0;
        *((char*)a + 5) = 0;
    }
}
