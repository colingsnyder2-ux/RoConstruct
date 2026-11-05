// from server: 100% by colin
struct CXTPToolBar {
    char pad[0xf8];
    int field_f8;
    char pad2[0x168 - 0xf8 - 4];
    int field_168;
    int field_16c;
    int CControlButtonExpand();
};

extern "C" int __cdecl sub_677380(int);
extern "C" int __cdecl sub_630202(int);
extern "C" int __fastcall sub_679900(int);

int CXTPToolBar::CControlButtonExpand()
{
    int v = sub_630202(sub_677380(this->field_16c));
    if (this->field_168 != 0 && v != 0 && this->field_f8 == 2)
    {
        return sub_679900(v);
    }
    return v;
}
