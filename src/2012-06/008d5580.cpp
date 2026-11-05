// from server: 38% by atomic.potato
extern "C" void* __cdecl func_004287b0(unsigned int);
extern "C" void __cdecl func_00428700(void*);
extern "C" void __cdecl func_008d4310();
extern "C" void __cdecl func_008d5010();

struct S {
    void func_008d5580(void** out, void* arg);
};

void S::func_008d5580(void** out, void* arg)
{
    void* p = func_004287b0(0x38);
    if (p) {
        func_008d5010();
        *(void**)p = (void*)0xbe9cb4;
        *(void**)((char*)p + 8) = (void*)0xbe9cac;
    } else {
        p = 0;
    }
    func_008d4310();
    *out = p;
    if (p) {
        func_00428700((char*)p + 5);
    }
}
