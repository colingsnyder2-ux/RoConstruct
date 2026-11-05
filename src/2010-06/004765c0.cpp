// from server: 52% by atomic.potato
struct CSettingsPropGrid {
    bool sub_4765C0(int a, int b);
};

extern "C" void* __stdcall make_desc_0040a710(const char*, int);

struct Descriptor_0040a710 {
    void attach(void*);
};

extern Descriptor_0040a710 global_desc_0040a710;
extern void register_desc_0040a710(void(*)());
extern int name_0040a710;
extern int callback_impl;

struct Init_0040a710 {
    Init_0040a710() {
        void* p = make_desc_0040a710((const char*)&name_0040a710, 0);
        global_desc_0040a710.attach(p);
        register_desc_0040a710((void(*)())&callback_impl);
    }
};

Init_0040a710* func_0040a710();

struct ClassDescriptor_005C9AA0 {
    bool equals(const ClassDescriptor_005C9AA0& other) const;
};

bool CSettingsPropGrid::sub_4765C0(int a, int b) {
    Init_0040a710* d = func_0040a710();
    ClassDescriptor_005C9AA0* desc = (ClassDescriptor_005C9AA0*)((char*)d + 0xc);
    if (desc->equals(*(ClassDescriptor_005C9AA0*)&a)) {
        return ((bool (__thiscall*)(CSettingsPropGrid*, int, int))0x440b90)(this, a, b);
    }
    return false;
}
