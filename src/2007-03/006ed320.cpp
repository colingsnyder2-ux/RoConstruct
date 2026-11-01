// from server: 100% by tester
struct CXTColorHex_PAUHEXCOLOR_CELL_CList
{
    void f(int);
    void sub_70A180(int);
    char pad[0x78];
    int field_78;
    char pad2[4];
    void* field_80;
};

void CXTColorHex_PAUHEXCOLOR_CELL_CList::f(int arg)
{
    void* node = field_80;
    int idx = -1;
    field_78 = arg;
    while (node != 0)
    {
        void* data = *(void**)((char*)node + 8);
        if (data != 0 && arg == *(int*)((char*)data + 0x18))
        {
            sub_70A180(idx);
        }
        node = *(void**)node;
        idx++;
    }
}
