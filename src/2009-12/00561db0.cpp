// from server: 92% by atomic.potato
extern "C" void __cdecl call_7f49a4(void *, int, int, const void *);
extern "C" void __cdecl call_7f385a(void *);

void f(void *p)
{
    if (p != 0)
    {
        call_7f49a4((char *)p + 8, 0x18, 0x28, (const void *)0x558db0);
        call_7f385a(p);
    }
}
