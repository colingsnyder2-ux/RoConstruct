// from server: 46% by Intel
extern "C" void __stdcall sub_6861b0();
extern "C" void __cdecl sub_684840(void*, void*);
extern "C" void __stdcall sub_B22648(void*);
extern "C" void __stdcall sub_B2263C(void*);

struct FilteredSelection {
    void* vftable;
    void* field_4;
    char gap_8[0x10];
    void* field_18;
    void* field_1C;
    char gap_20[0x60];
    void* field_80;
    int field_84;
    int field_88;
    int field_8C;
    char gap_90[4];
    int field_94;
    int field_98;
    int field_9C;

    void* ctor();
};

void* FilteredSelection::ctor()
{
    sub_6861b0();
    this->field_84 = 1;
    int zero = 0;
    this->vftable = (void*)0xB9C524;
    this->field_4 = (void*)0xB9C51C;
    this->field_18 = (void*)0xB9C510;
    this->field_1C = (void*)0xB9C504;
    this->field_80 = (void*)0xB9C4FC;
    this->field_88 = zero;
    this->field_8C = zero;
    this->field_94 = zero;
    this->field_98 = zero;
    this->field_9C = zero;

    void* str = (void*)0xB9C3E4;
    sub_B22648(str);
    sub_684840(this, &str);
    sub_B2263C(&str);

    return this;
}
