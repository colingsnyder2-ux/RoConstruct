// roc 2012-06 009dcc40  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dcc40
//
// 009dcc40  8bc1                 mov eax, ecx
// 009dcc42  33c9                 xor ecx, ecx
// 009dcc44  c7006468c100         mov dword ptr [eax], 0xc16864
// 009dcc4a  894804               mov dword ptr [eax + 4], ecx
// 009dcc4d  894810               mov dword ptr [eax + 0x10], ecx
// 009dcc50  89480c               mov dword ptr [eax + 0xc], ecx
// 009dcc53  894808               mov dword ptr [eax + 8], ecx
// 009dcc56  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009dcc40
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009dcc40();
};
S_func_009dcc40::S_func_009dcc40()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
