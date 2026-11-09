// from server: 100% by tester
struct CXTPDockingPaneWindowSelect {
    char pad[0xf8];
    void* field_e4;
    void* get();
};

extern "C" void* __cdecl sub_738364(void*);
extern "C" void* __cdecl sub_630202(void*);

void* CXTPDockingPaneWindowSelect::get()
{
    void* p = *(void**)((char*)field_e4 + 0xcc);
    void* q = sub_630202(sub_738364(p));
    if (q != 0)
        return *(void**)((char*)q + 0xe8);
    return 0;
}
