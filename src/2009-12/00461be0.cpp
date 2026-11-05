// from server: 89% by atomic.potato
extern "C" void* __cdecl sub_007f3b1e();
extern "C" int __stdcall PostMessageA(void*, unsigned int, unsigned int, unsigned long);

int sub_00461be0()
{
    void* p = sub_007f3b1e();
    p = *(void**)((char*)p + 4);
    p = *(void**)((char*)p + 0x20);
    if (*(unsigned char*)((char*)p + 0xfc) != 0)
        PostMessageA(*(void**)((char*)p + 0x20), 0x111, 0x80f4, 0);
    return 0;
}
