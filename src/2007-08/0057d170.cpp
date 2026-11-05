// from server: 100% by colin
struct Workspace {
    char pad[0x374];
    void* field_374;
    void* field_378;
    Workspace* sub_57D170(int flag);
};

extern "C" void __cdecl sub_57C7D0();
extern "C" void __declspec(dllimport) __cdecl free(void*);

extern void* g_sym_7a4cac;
extern void* g_sym_7a4ca4;

Workspace* Workspace::sub_57D170(int flag)
{
    sub_57C7D0();
    void* p = field_378;
    field_374 = &g_sym_7a4cac;
    void* q = *(void**)((char*)p + 4);
    *(void**)((char*)q + (int)this + 0x378) = &g_sym_7a4ca4;
    if (flag & 1) {
        free(this);
    }
    return this;
}