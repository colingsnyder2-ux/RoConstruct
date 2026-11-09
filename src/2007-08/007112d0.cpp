// from server: 100% by colin
struct CXTColorSelectorCtrl
{
    char pad[0x144];
    int field_144;
    int sub_711000(int);
    int sub_7111e0(int);
    void sub_7112d0(int);
};

void CXTColorSelectorCtrl::sub_7112d0(int a)
{
    int r = ((CXTColorSelectorCtrl*)((char*)this + 0x144))->sub_711000(a);
    if (r != 0)
    {
        sub_7111e0(*(int*)(r + 8));
    }
}
