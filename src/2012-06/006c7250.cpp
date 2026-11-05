// from server: 24% by atomic.potato
struct RBX_Settings {
    char pad0[0x1c];
    int field_1c;
    char pad20[0x10];
    int field_30;
    int field_34;
};

extern "C" void __stdcall sub_006c7190();
extern "C" int __stdcall sub_007092a0();

void __stdcall RBX_Settings_ctor(RBX_Settings* self, int a, int b, int c, int d, int e, int f)
{
    sub_006c7190();
    self->field_1c = sub_007092a0();
    self->field_30 = c;
    self->field_34 = d;
}
