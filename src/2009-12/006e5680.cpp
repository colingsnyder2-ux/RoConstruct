// from server: 69% by atomic.potato
extern "C" void* __stdcall sub_7f4aaa(void*, int, void*, void*, int);
extern "C" void* __cdecl sub_6e5270(void*);

struct RBX_Instance;

struct RBX_VPartInstance_FilteredSelection {
};

void* __cdecl method0(void* arg)
{
    RBX_Instance* p = (RBX_Instance*)arg;
    if (p == 0)
        return 0;
    void* q = *(void**)((char*)p + 0x4c);
    if (q == 0)
        return 0;
    void* r = sub_7f4aaa(q, 0, (void*)0xaffe40, (void*)0xb0ab40, 0);
    if (r == 0)
        return 0;
    return sub_6e5270(r);
}
