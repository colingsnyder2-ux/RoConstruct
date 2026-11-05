// from server: 33% by Intel
struct VController_EventDesc {
    void* vfptr_0;
    void* vfptr_4;
    char pad_8[20];
    void* vfptr_18;
    void* vfptr_1c;
    char pad_20[12];
    int field_28;
    char pad_2c[84];
    void* vfptr_80;
    VController_EventDesc* base_ctor();
    int init_func();
    VController_EventDesc* ctor();
};

extern "C" int __stdcall init_func_7818b0();
extern int g_controller_count;

VController_EventDesc* VController_EventDesc::ctor() {
    base_ctor();
    vfptr_0 = (void*)0xbb53cc;
    vfptr_4 = (void*)0xbb53c0;
    vfptr_18 = (void*)0xbb53b4;
    vfptr_1c = (void*)0xbb53a8;
    vfptr_80 = (void*)0xbb539c;
    field_28 = init_func_7818b0();
    ++g_controller_count;
    return this;
}
