// from server: 100% by colin
struct SurfaceGetSet {
    int (__fastcall *get)(void*, int);
    void (__fastcall *set)(void*);
    void setValue(void* instance);
};

extern "C" void* __fastcall sub_00573890(void* p);

void SurfaceGetSet::setValue(void* instance)
{
    void* obj;
    if (instance != 0) {
        obj = sub_00573890((char*)instance - 4);
    } else {
        obj = sub_00573890(0);
    }
    void (__fastcall *fn)(void*) = this->set;
    fn((char*)obj + 0x28);
}
