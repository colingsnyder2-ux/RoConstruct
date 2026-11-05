// from server: 27% by atomic.potato
extern "C" void* __cdecl func_007a79a0(unsigned int);
extern "C" void __cdecl func_005934c0(void*);

struct S {
    void func_00401b30(void*, void*);
    void __cdecl func_00401be0(void*);
};

void S::func_00401be0(void* arg)
{
    void* p = func_007a79a0(0xb0);
    if (p)
        func_005934c0(p);
    else
        p = 0;
    func_00401b30(p, arg);
}
