// from server: 88% by atomic.potato
struct CWebToolbox {
    char pad[0xf8];
    void* field_f8;
    void sub_9826de();
    void sub_9824a4();
    void func_004b0d60();
};

void CWebToolbox::func_004b0d60()
{
    sub_9826de();
    if (field_f8 != 0) {
        ((CWebToolbox*)field_f8)->sub_9824a4();
    }
}
