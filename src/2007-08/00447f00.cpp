// from server: 100% by colin
struct CRbxPlayDocTemplate
{
    char pad[0x90];
    void* field_0x90;
    void sub_63074e(void*);
    void func_00447f00(void*);
};

void CRbxPlayDocTemplate::func_00447f00(void* arg)
{
    sub_63074e(arg);
    if (arg == field_0x90)
        field_0x90 = 0;
}
