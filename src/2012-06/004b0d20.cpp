// from server: 100% by atomic.potato
struct CWebToolbox {
    char pad[0xf8];
    void* field_f8;
    void sub_9824a4();
    void sub_9830b0(const char*);
    void func_004b0d20(const char*);
};

void CWebToolbox::func_004b0d20(const char* arg)
{
    sub_9830b0(arg);
    if (field_f8 != 0)
        ((CWebToolbox*)field_f8)->sub_9824a4();
}
