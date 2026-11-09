// roc 2012-06 009f8c30  unit: CXTPResourceManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f8c30
//
// 009f8c30  8bc1                 mov eax, ecx
// 009f8c32  33c9                 xor ecx, ecx
// 009f8c34  c700b0b0c100         mov dword ptr [eax], 0xc1b0b0
// 009f8c3a  894804               mov dword ptr [eax + 4], ecx
// 009f8c3d  894810               mov dword ptr [eax + 0x10], ecx
// 009f8c40  89480c               mov dword ptr [eax + 0xc], ecx
// 009f8c43  894808               mov dword ptr [eax + 8], ecx
// 009f8c46  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009f8c30
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009f8c30();
};
S_func_009f8c30::S_func_009f8c30()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
