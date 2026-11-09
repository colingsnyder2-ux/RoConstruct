// from server: 31% by atomic.potato
extern "C" void* __cdecl sub_7F3860(unsigned int);
extern "C" void __fastcall sub_6E5320(void*);

struct VPartInstance_FilteredSelection {
    void construct(void* a, void* b);
};

extern "C" void __fastcall sub_6E4880(void* self, void* unused, void* a);

void VPartInstance_FilteredSelection::construct(void* a, void* b) {
    void* mem = sub_7F3860(0xbc);
    void* obj = 0;
    if (mem) {
        sub_6E5320(mem);
        obj = mem;
    }
    sub_6E4880(this, obj, a);
}
