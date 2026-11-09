// from server: 100% by colin
struct CWebToolbox {
    char pad[0xf4];
    void* field_f4;
    void sub_630004();
    void sub_63011e(int);
    void func_004667a0(int);
};

void CWebToolbox::func_004667a0(int arg)
{
    if (field_f4 != 0) {
        ((CWebToolbox*)field_f4)->sub_630004();
    }
    sub_63011e(0);
}
