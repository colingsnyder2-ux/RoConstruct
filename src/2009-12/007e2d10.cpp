// from server: 66% by atomic.potato
extern "C" void __cdecl func_00401630();
extern "C" void* __stdcall boost_get_tss_data(const void*);

struct S {
    void* f();
};

void* S::f()
{
    func_00401630();
    void* p = boost_get_tss_data((void*)0xb990d0);
    if (p) {
        if (*(unsigned int*)((char*)p + 0x18) >= 0x10)
            return *(void**)((char*)p + 4);
        return (char*)p + 4;
    }
    return *(void**)0xb64860;
}
