// from server: 85% by atomic.potato
extern "C" unsigned int __cdecl G1_func_009823d2();
extern "C" int __stdcall PostMessageA(void *, unsigned int, unsigned int, long);

void __stdcall func_004263e0(int value)
{
    unsigned int eax = G1_func_009823d2();
    if (value == 0)
        PostMessageA(*(void **)(*(unsigned int *)(eax + 4) + 0x20), 0x111, 0x8124, 0);
}
