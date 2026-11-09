// from server: 43% by colin
struct CXTPRibbonTheme {
    char pad[0x20];
    int field_20;
    char pad2[0x2ec - 0x24];
    int field_2ec;
    char pad3[0x334 - 0x2f0];
    int field_334;
    char pad4[0x34c - 0x338];
    int field_34c;
    char pad5[0x358 - 0x350];
    int field_358;
    char pad6[0x364 - 0x35c];
    int field_364;
    char pad7[0x49c - 0x368];
    char field_49c[4];
    char pad8[0x65c - 0x4a0];
    int field_65c;
    int field_660;
};

extern "C" void* __stdcall sub_77DDB8(void*);
extern "C" void* __cdecl sub_6BA7A0(void*);
extern "C" void* __cdecl sub_710820(void*);
extern "C" void __cdecl sub_6684F0(void*, int, int, float);
extern "C" void __cdecl sub_6C0AC0(void*);

extern float g_float_797E9C;

void __stdcall sub_6AD2C0(CXTPRibbonTheme* self)
{
    void* p;

    sub_77DDB8((void*)0x7D5670);
    p = sub_6BA7A0(self);
    p = sub_710820(p);
    self->field_65c = (int)p;
    sub_77DDB8((void*)0x7D55D4);

    sub_77DDB8((void*)0x7D5670);
    p = sub_6BA7A0(self);
    p = sub_710820(p);
    self->field_660 = (int)p;
    sub_77DDB8((void*)0x7D55C4);

    sub_77DDB8((void*)0x7D5670);
    p = sub_6BA7A0(self);
    p = sub_710820(p);
    self->field_358 = (int)p;
    self->field_20 = 0;
    self->field_2ec = 0xA7A7A7;
    sub_77DDB8((void*)0x7D55AC);

    sub_77DDB8((void*)0x7D5670);
    p = sub_6BA7A0(self);
    p = sub_710820(p);
    self->field_364 = (int)p;
    self->field_34c = 0x868686;
    self->field_334 = 0xFAFAFA;
    sub_6684F0(self->field_49c, 0xEEEEE9, 0xEEEEE9, g_float_797E9C);
    sub_6C0AC0(self);
}
