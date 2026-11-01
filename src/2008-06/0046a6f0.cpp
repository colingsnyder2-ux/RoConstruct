// from server: 100% by atomic.potato
struct CWebToolbox
{
    char pad[0xf8];
    void* field_f8;
    int func_0046a6f0(int, int, int);
    void sub_006a0a28();
};

int CWebToolbox::func_0046a6f0(int, int, int)
{
    if (field_f8 != 0) {
        ((CWebToolbox*)field_f8)->sub_006a0a28();
    }
    return 3;
}
