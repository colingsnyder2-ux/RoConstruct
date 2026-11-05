// from server: 100% by atomic.potato
struct CWebToolbox
{
    char pad[0xf8];
    void* field_f8;
    void sub_80a4c0(int, int, int);
    void sub_80a400();
    void func_0049ba60(int, int, int);
};

void CWebToolbox::func_0049ba60(int arg1, int arg2, int arg3)
{
    sub_80a4c0(arg1, arg2, arg3);
    if (field_f8 != 0)
        ((CWebToolbox*)field_f8)->sub_80a400();
}
