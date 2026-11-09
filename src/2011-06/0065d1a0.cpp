// from server: 25% by atomic.potato
extern "C" void* __stdcall make_desc_0065c6b0(const char*, int);
extern "C" void __stdcall sub_004580b0();

struct Descriptor_0065c6b0 { void attach(void*); };
extern Descriptor_0065c6b0 global_desc_0065c6b0;
extern void register_desc_0065c6b0(void(*)());
extern int name_0065c6b0;
extern int callback_impl;

struct Init_0065c6b0 {
    Init_0065c6b0() {
        void* p = make_desc_0065c6b0("ProfilingItem", 27);
        global_desc_0065c6b0.attach(p);
        register_desc_0065c6b0((void(*)())&callback_impl);
    }
};

Init_0065c6b0* func_0065c6b0();

extern int g_00ccd9a4;

struct TypedPercentItem {
    void* vfptr0;
    void* vfptr1;
    char pad_08[0x10];
    void* vfptr18;
    void* vfptr1c;
    void* field20;
    void* ctor();
};

void* TypedPercentItem::ctor()
{
    sub_004580b0();
    vfptr0 = (void*)0xa9af2c;
    vfptr1 = (void*)0xa9af20;
    vfptr18 = (void*)0xa9af14;
    vfptr1c = (void*)0xa9af08;
    field20 = func_0065c6b0();
    g_00ccd9a4++;
    return this;
}
