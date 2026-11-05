// from server: 46% by atomic.potato
extern "C" void __cdecl f0080b15d();

void f005eeaa0()
{
    volatile unsigned char *p = (volatile unsigned char *)0xccb5c8;
    *p = 0x8c;
    f0080b15d();
}
