// from server: 91% by atomic.potato
extern "C" void __cdecl sub_0052E170(void *, unsigned long);

struct S
{
};

void __cdecl f(void *a, unsigned long n)
{
    if (n != 4)
        sub_0052E170(a, n);
    else
    {
        *(unsigned long *)a = 0x00D7E2C8;
        *((unsigned char *)a + 4) = 0;
        *((unsigned char *)a + 5) = 0;
    }
}
