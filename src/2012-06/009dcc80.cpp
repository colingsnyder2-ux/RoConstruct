// roc 2012-06 009dcc80  unit: CXTPTabClientWnd  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009dcc80
//
// 009dcc80  8bc1                 mov eax, ecx
// 009dcc82  33c9                 xor ecx, ecx
// 009dcc84  c7007c68c100         mov dword ptr [eax], 0xc1687c
// 009dcc8a  894804               mov dword ptr [eax + 4], ecx
// 009dcc8d  894810               mov dword ptr [eax + 0x10], ecx
// 009dcc90  89480c               mov dword ptr [eax + 0xc], ecx
// 009dcc93  894808               mov dword ptr [eax + 8], ecx
// 009dcc96  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009dcc80
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009dcc80();
};
S_func_009dcc80::S_func_009dcc80()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
