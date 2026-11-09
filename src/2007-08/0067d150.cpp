// from server: 100% by colin
struct CXTPControls
{
    char pad[0x3c];
    int field_3c;
    void sub_67a590();
    int sub_67d0c0(int);
    void func_67d150();
};

void CXTPControls::func_67d150()
{
    sub_67a590();
    field_3c = sub_67d0c0(1);
}
