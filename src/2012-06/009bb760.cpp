// roc 2012-06 009bb760  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bb760
//
// 009bb760  8bc1                 mov eax, ecx
// 009bb762  33c9                 xor ecx, ecx
// 009bb764  c7005818c100         mov dword ptr [eax], 0xc11858
// 009bb76a  894804               mov dword ptr [eax + 4], ecx
// 009bb76d  894810               mov dword ptr [eax + 0x10], ecx
// 009bb770  89480c               mov dword ptr [eax + 0xc], ecx
// 009bb773  894808               mov dword ptr [eax + 8], ecx
// 009bb776  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009bb760
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009bb760();
};
S_func_009bb760::S_func_009bb760()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
