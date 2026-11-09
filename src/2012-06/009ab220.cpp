// roc 2012-06 009ab220  unit: CXTPReportControl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ab220
//
// 009ab220  8bc1                 mov eax, ecx
// 009ab222  33c9                 xor ecx, ecx
// 009ab224  c7005402c100         mov dword ptr [eax], 0xc10254
// 009ab22a  894804               mov dword ptr [eax + 4], ecx
// 009ab22d  894810               mov dword ptr [eax + 0x10], ecx
// 009ab230  89480c               mov dword ptr [eax + 0xc], ecx
// 009ab233  894808               mov dword ptr [eax + 8], ecx
// 009ab236  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009ab220
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009ab220();
};
S_func_009ab220::S_func_009ab220()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
