// from server: 64% by atomic.potato
extern "C" void* __cdecl sub_6e32e0();
extern "C" void* __cdecl sub_6e49b0(void*);
extern "C" void __cdecl sub_53e5c0(void*);
extern "C" void __stdcall sub_636d80(void*, void*);

void __stdcall sub_6e55e0(void* a)
{
    void* p = sub_6e32e0();
    if (p)
    {
        void* q = sub_6e49b0(p);
        if (q)
            sub_53e5c0(q);
        sub_636d80(p, a);
    }
}
