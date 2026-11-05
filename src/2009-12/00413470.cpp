// from server: 100% by atomic.potato
struct CClassImages
{
    void* GetImage();
};

extern "C" void* __cdecl G1_func_007f4016();

void* CClassImages::GetImage()
{
    void* p = G1_func_007f4016();
    if (p)
        return (*(void* (__thiscall **)(void*))(*(char**)p + 0x7c))(p);
    return 0;
}
