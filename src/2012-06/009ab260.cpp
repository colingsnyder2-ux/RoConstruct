// roc 2012-06 009ab260  unit: CXTPReportControl  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ab260
//
// 009ab260  8bc1                 mov eax, ecx
// 009ab262  33c9                 xor ecx, ecx
// 009ab264  c7006c02c100         mov dword ptr [eax], 0xc1026c
// 009ab26a  894804               mov dword ptr [eax + 4], ecx
// 009ab26d  894810               mov dword ptr [eax + 0x10], ecx
// 009ab270  89480c               mov dword ptr [eax + 0xc], ecx
// 009ab273  894808               mov dword ptr [eax + 8], ecx
// 009ab276  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009ab260
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009ab260();
};
S_func_009ab260::S_func_009ab260()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
