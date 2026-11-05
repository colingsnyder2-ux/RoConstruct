// from server: 100% by colin
struct CXTPCommandBar
{
    char pad[0xbc];
    int field_bc;
    int HasVisibleItems();
};

struct CXTPCommandBarSite
{
    int field_0;
    int field_4;
};

extern "C" CXTPCommandBarSite* __stdcall sub_643980();
extern "C" CXTPCommandBarSite* __fastcall sub_633900(CXTPCommandBarSite*);

int CXTPCommandBar::HasVisibleItems()
{
    if (field_bc == 0)
    {
        CXTPCommandBarSite* p = sub_643980();
        CXTPCommandBarSite* q = sub_633900(p);
        if (q->field_4 > 0)
            return 1;
    }
    return 0;
}
