// from server: 39% by atomic.potato
extern "C" void __cdecl sub_00933c50(unsigned long, unsigned long, unsigned long);

void __stdcall sub_009351d0(unsigned short a, unsigned short b, unsigned long c, unsigned long d)
{
    sub_00933c50((unsigned long)a, (unsigned long)b, d);
}
