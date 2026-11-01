// from server: 19% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct SharedPtr {
    char pad[0x104];
    int field104;
    char pad2[0x4];
};

struct Creator {
    char pad[0x20];
    void* field20;
    SharedPtr getShared();
};

extern "C" void* __cdecl sym_func();

SharedPtr Creator::getShared()
{
    void* p = field20;
    if (p == 0)
        return SharedPtr();
    void* r = sym_func();
    int* f = (int*)((char*)r + 0x104);
    return SharedPtr();
}
