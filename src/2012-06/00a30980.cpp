// roc 2012-06 00a30980  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a30980
//
// 00a30980  8bc1                 mov eax, ecx
// 00a30982  33c9                 xor ecx, ecx
// 00a30984  c700a404c200         mov dword ptr [eax], 0xc204a4
// 00a3098a  894804               mov dword ptr [eax + 4], ecx
// 00a3098d  894810               mov dword ptr [eax + 0x10], ecx
// 00a30990  89480c               mov dword ptr [eax + 0xc], ecx
// 00a30993  894808               mov dword ptr [eax + 8], ecx
// 00a30996  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a30980
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a30980();
};
S_func_00a30980::S_func_00a30980()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
