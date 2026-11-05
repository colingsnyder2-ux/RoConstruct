// from server: 86% by atomic.potato
extern "C" void __cdecl func_007a891e(void*);
extern "C" void __fastcall func_007a7d42(void*);

struct CWebToolbox
{
    char padding[0xf8];
    void* field_f8;
    void func_0047c190(void*);
};

void CWebToolbox::func_0047c190(void* arg)
{
    func_007a891e(arg);
    if (field_f8)
        func_007a7d42(field_f8);
}
