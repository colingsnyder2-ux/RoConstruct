// roc 2012-06 009ebb00  unit: CXTPToolTipContext::CStandardToolTip  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ebb00
//
// 009ebb00  8bc1                 mov eax, ecx
// 009ebb02  33c9                 xor ecx, ecx
// 009ebb04  c7009c82c100         mov dword ptr [eax], 0xc1829c
// 009ebb0a  894804               mov dword ptr [eax + 4], ecx
// 009ebb0d  894810               mov dword ptr [eax + 0x10], ecx
// 009ebb10  89480c               mov dword ptr [eax + 0xc], ecx
// 009ebb13  894808               mov dword ptr [eax + 8], ecx
// 009ebb16  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009ebb00
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009ebb00();
};
S_func_009ebb00::S_func_009ebb00()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
