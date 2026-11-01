// from server: 100% by colin
struct CXTColorSelectorCtrl
{
    char pad[0x144];
    int field_144;
    int sub_711000(int);
    int func(int);
};

int CXTColorSelectorCtrl::func(int arg)
{
    int result = ((CXTColorSelectorCtrl*)((char*)this + 0x144))->sub_711000(arg);
    if (result != 0)
        return *(int*)(result + 8);
    return 0;
}
