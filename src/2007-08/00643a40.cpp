// from server: 100% by colin
struct CXTPCommandBar {
    int field_0x164;
    int getSomething();
    CXTPCommandBar* getParent();
};

extern int g_008c86d8;
extern int __cdecl sub_0063dcb0(int);
extern int __fastcall sub_00643980();
extern CXTPCommandBar* __fastcall sub_00643950(CXTPCommandBar*);
extern int __fastcall sub_006321d0(CXTPCommandBar*);

int CXTPCommandBar::getSomething()
{
    int result = *(int*)((char*)this + 0x164);
    if (result != 0)
        return result;

    int v = sub_00643980();
    if (v != 0)
        return sub_006321d0((CXTPCommandBar*)v);

    CXTPCommandBar* p = sub_00643950(this);
    result = *(int*)((char*)p + 0x164);
    if (result != 0)
        return result;

    if (g_008c86d8 == 0)
    {
        sub_0063dcb0(0);
    }
    return g_008c86d8;
}
