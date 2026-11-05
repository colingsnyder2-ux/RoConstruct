// roc 2012-06 009e2e90  unit: CXTPPropertyGrid  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e2e90
//
// 009e2e90  8bc1                 mov eax, ecx
// 009e2e92  33c9                 xor ecx, ecx
// 009e2e94  c7000071c100         mov dword ptr [eax], 0xc17100
// 009e2e9a  894804               mov dword ptr [eax + 4], ecx
// 009e2e9d  894810               mov dword ptr [eax + 0x10], ecx
// 009e2ea0  89480c               mov dword ptr [eax + 0xc], ecx
// 009e2ea3  894808               mov dword ptr [eax + 8], ecx
// 009e2ea6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009e2e90
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009e2e90();
};
S_func_009e2e90::S_func_009e2e90()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
