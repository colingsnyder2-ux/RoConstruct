// from server: 40% by atomic.potato
struct VKeyframe {
    void* vtbl0;
    void* vtbl1;
    char pad[0x10];
    void* vtbl2;
    void* vtbl3;
    char pad2[0x70];
    float f90;
};

extern "C" {
    void __stdcall sub_688D70();
    void __stdcall sub_598250();
    void __stdcall sub_A404C4();
    void __stdcall sub_A404D0();
    void __stdcall string_ctor(void*, const char*);
    void __stdcall string_dtor(void*);
}

VKeyframe* __fastcall VKeyframe_ctor(VKeyframe* self, void*)
{
    char buf[0x20];
    sub_688D70();
    self->f90 = 0.0f;
    string_ctor(buf, (const char*)0xA9F264);
    self->vtbl0 = (void*)0xA9F3AC;
    self->vtbl1 = (void*)0xA9F3A4;
    self->vtbl2 = (void*)0xA9F398;
    self->vtbl3 = (void*)0xA9F38C;
    sub_A404C4();
    sub_598250();
    string_dtor(buf);
    return self;
}
