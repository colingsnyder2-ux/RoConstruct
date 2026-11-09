// from server: 100% by atomic.potato
struct CWebToolbox
{
    char pad[0xf8];
    void* field_f8;
    void sub_98256a(int, int, int);
    void sub_9824a4();

    void func_004b0cf0(int a, int b, int c);
};

void CWebToolbox::func_004b0cf0(int a, int b, int c)
{
    sub_98256a(a, b, c);
    if (field_f8 != 0)
        ((CWebToolbox*)field_f8)->sub_9824a4();
}
