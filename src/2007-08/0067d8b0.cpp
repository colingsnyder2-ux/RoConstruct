// from server: 100% by atomic.potato
struct CXTPControlSelector {
    char pad[0x168];
    int field_168;
    int field_16c;
    int field_170;
    int field_174;
    char pad2[8];
    int field_180;
    int field_184;

    void func_0067d8b0(CXTPControlSelector* other, int arg);
};

extern "C" void __stdcall sub_0063cb00(CXTPControlSelector* other, int arg);

void CXTPControlSelector::func_0067d8b0(CXTPControlSelector* other, int arg)
{
    sub_0063cb00(other, arg);
    this->field_168 = other->field_168;
    this->field_16c = other->field_16c;
    this->field_170 = other->field_170;
    this->field_174 = other->field_174;
    this->field_180 = other->field_180;
    this->field_184 = other->field_184;
}
