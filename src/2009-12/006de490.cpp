// from server: 34% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor {
    bool sub_6DE490(int);
};

extern "C" void* __fastcall sub_6DBDD0(void*);
extern "C" void __fastcall sub_6DE390(void*, void*);

bool VCRenderSettingsItem_EnumPropDescriptor::sub_6DE490(int a1) {
    void* p = sub_6DBDD0(this);
    if (p == 0) {
        return false;
    }
    void* v = (*(void* (__fastcall**)(void*, int, int))p)(p, a1, 0);
    sub_6DE390(this, v);
    return true;
}
