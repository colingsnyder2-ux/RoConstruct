// from server: 60% by atomic.potato
extern "C" void* __stdcall G1_func_0085a9a0(void*);

struct CXTPStatusBar
{
    void* GetValue();
};

void* CXTPStatusBar::GetValue()
{
    void* p = G1_func_0085a9a0(this);
    if (!p)
        return 0;
    return *(void**)((char*)p + 0x68);
}
