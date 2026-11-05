// from server: 41% by colin
struct ScintillaFindReplaceDlg
{
    char pad[0x58];
    char sub_58[0x5c];
    int field_b4;
    int field_b8;
    void destruct();
};

extern "C" void __cdecl sub_62ff26(int);
extern "C" void __cdecl sub_630502(void*);
extern "C" void __cdecl sub_45be30(void*);

void ScintillaFindReplaceDlg::destruct()
{
    field_b4 = 0x7941c0;
    if (field_b8 != 0)
    {
        sub_62ff26(field_b8);
    }
    sub_45be30(&sub_58[0]);
    sub_630502(this);
}
