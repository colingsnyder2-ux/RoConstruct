// from server: 47% by colin
struct CXTPControlCustom {
    void ctor();
    char pad[0x168];
    int field_168;
    int field_16c;
    int field_170;
    int field_174;
    char pad2[0x190 - 0x178];
    int field_190;
    int field_194;
    int field_184;
    int field_d4;
};

extern "C" int __stdcall SetRectEmpty(int *);
extern "C" void __stdcall sub_6ca460();
extern "C" void __stdcall sub_6a2b50();

void CXTPControlCustom::ctor()
{
    sub_6ca460();
    sub_6a2b50();
    SetRectEmpty(&field_174);
    field_170 = 0;
    field_190 = 0;
    field_184 = 1;
    field_d4 = 0x10;
    field_194 = 0;
}
