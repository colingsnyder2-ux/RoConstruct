// from server: 38% by colin
struct CXTPStatusBarPane {
    char pad0[0x5c];
    int field_5c;
    int field_60;
    int field_64;
    int field_68;
    char pad1[0x28];
    int field_94;
    char pad2[0x10];
    int field_a8;
    int field_ac;
    int field_b0;
    int field_b4;
    int field_b8;
    int field_bc;
    int field_c0;
};

extern "C" void __stdcall sub_738b6e();
extern "C" void __stdcall sub_692a80();
extern "C" int __stdcall sub_6a8ba0();
extern "C" void* __stdcall sub_62fef6(unsigned int);
extern "C" void __stdcall sub_694ae0();
extern "C" void __stdcall sub_63cd00();
extern "C" void __stdcall sub_630238();
extern "C" void __stdcall sub_630a1e();
extern "C" void* __stdcall sub_77d14c();

CXTPStatusBarPane* __fastcall sub_692b00(CXTPStatusBarPane* self);

CXTPStatusBarPane* __fastcall sub_692b00(CXTPStatusBarPane* self)
{
    sub_738b6e();
    self->field_94 = 0;
    *(int*)self = 0x7d09c4;
    sub_692a80();
    self->field_ac = 0x794a08;
    self->field_b0 = 0;
    self->field_64 = 2;
    if (sub_6a8ba0()) {
        self->field_5c = 0;
        self->field_60 = 0;
        self->field_68 = 0;
    } else {
        self->field_5c = 2;
        self->field_60 = 2;
        self->field_68 = 1;
    }
    self->field_a8 = 0;
    self->field_b8 = 0;
    self->field_bc = 1;
    self->field_b4 = 1;
    void* p = sub_62fef6(0xa4);
    if (p != 0) {
        sub_694ae0();
    } else {
        p = 0;
    }
    self->field_c0 = (int)p;
    sub_63cd00();
    void* h = sub_77d14c();
    sub_630238();
    return self;
}
