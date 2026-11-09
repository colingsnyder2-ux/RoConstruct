// from server: 100% by atomic.potato
struct CWebToolbox
{
    char padding[0xf8];
    void* field_f8;
    int func_0047c1b0(int, int, int);
};

extern void __fastcall G1_func_007a7d42(void*);

int CWebToolbox::func_0047c1b0(int, int, int)
{
    if (field_f8)
        G1_func_007a7d42(field_f8);
    return 3;
}
