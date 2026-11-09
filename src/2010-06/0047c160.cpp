// from server: 89% by atomic.potato

extern "C" void __stdcall sub_007a7d42(void*);

struct CWebToolbox
{
    char padding_0[0xf8];
    void* field_f8;
    void func_0047c160(int, int, int);
void sub_007a7e02(int, int, int);
};

void CWebToolbox::func_0047c160(int arg1, int arg2, int arg3)
{
    sub_007a7e02(arg1, arg2, arg3);
    if (field_f8 != 0)
        sub_007a7d42(field_f8);
}
