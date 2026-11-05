// roc 2012-06 009bb7a0  unit: VCXTPReportRows::?$CXTPHeapObjectT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bb7a0
//
// 009bb7a0  8bc1                 mov eax, ecx
// 009bb7a2  33c9                 xor ecx, ecx
// 009bb7a4  c7007018c100         mov dword ptr [eax], 0xc11870
// 009bb7aa  894804               mov dword ptr [eax + 4], ecx
// 009bb7ad  894810               mov dword ptr [eax + 0x10], ecx
// 009bb7b0  89480c               mov dword ptr [eax + 0xc], ecx
// 009bb7b3  894808               mov dword ptr [eax + 8], ecx
// 009bb7b6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009bb7a0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009bb7a0();
};
S_func_009bb7a0::S_func_009bb7a0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
