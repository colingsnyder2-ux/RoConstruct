// from server: 100% by why2
// roc 2009-06 00447740  unit: CRobloxModule  size: 14 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00447740

extern "C" void* __cdecl sub_7196C2();
extern "C" void* __cdecl sub_718CF6();

struct CRobloxModule {
    char pad[0x34];
    void* field_34;
    void* get();
};

void* CRobloxModule::get() {
    sub_7196C2();
    void* p = sub_718CF6();
    return *(void**)((char*)p + 0x34);
}
