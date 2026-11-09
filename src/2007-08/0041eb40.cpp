// from server: 100% by colin
struct CSettingsExplorer {
    char pad[0xbc];
    CSettingsExplorer* field_bc;
};

extern "C" int __cdecl sub_630d36(CSettingsExplorer*, int, int, int, int);
extern "C" int __fastcall sub_410d40(int);

int __cdecl sub_41eb40(CSettingsExplorer* p)
{
    while (p != 0)
    {
        int r = sub_630d36(p, 0, 0x881f4c, 0x884e04, 0);
        if (r != 0)
        {
            return sub_410d40(r);
        }
        p = p->field_bc;
    }
    return 0;
}
