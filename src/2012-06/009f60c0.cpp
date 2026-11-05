// roc 2012-06 009f60c0  unit: CXTPWinThemeWrapper  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f60c0
//
// 009f60c0  8bc1                 mov eax, ecx
// 009f60c2  33c9                 xor ecx, ecx
// 009f60c4  c70008a4c100         mov dword ptr [eax], 0xc1a408
// 009f60ca  894804               mov dword ptr [eax + 4], ecx
// 009f60cd  894810               mov dword ptr [eax + 0x10], ecx
// 009f60d0  89480c               mov dword ptr [eax + 0xc], ecx
// 009f60d3  894808               mov dword ptr [eax + 8], ecx
// 009f60d6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009f60c0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009f60c0();
};
S_func_009f60c0::S_func_009f60c0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
