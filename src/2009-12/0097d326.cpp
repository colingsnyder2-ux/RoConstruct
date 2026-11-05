// from server: 83% by atomic.potato
extern "C" void *__stdcall GetProcessHeap();

extern "C" void __cdecl func_007f4929(const void *);

void func_0097d326()
{
    void *eax = GetProcessHeap();
    *(void **)0xb9bff8 = (void *)0xa0fcd8;
    *(void **)0xb9bffc = eax;
    *(unsigned char *)0xb9c000 = 0;
    func_007f4929((const void *)0x98a7ca);
}
