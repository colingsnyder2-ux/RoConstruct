// roc 2012-06 009bae70  unit: VCXTPReportRecords::?$CXTPHeapObjectT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009bae70
//
// 009bae70  8bc1                 mov eax, ecx
// 009bae72  33c9                 xor ecx, ecx
// 009bae74  c700c817c100         mov dword ptr [eax], 0xc117c8
// 009bae7a  894804               mov dword ptr [eax + 4], ecx
// 009bae7d  894810               mov dword ptr [eax + 0x10], ecx
// 009bae80  89480c               mov dword ptr [eax + 0xc], ecx
// 009bae83  894808               mov dword ptr [eax + 8], ecx
// 009bae86  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009bae70
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009bae70();
};
S_func_009bae70::S_func_009bae70()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
