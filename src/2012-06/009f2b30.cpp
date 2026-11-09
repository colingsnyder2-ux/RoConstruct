// roc 2012-06 009f2b30  unit: CXTPPropertyGridItemConstraints  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f2b30
//
// 009f2b30  8bc1                 mov eax, ecx
// 009f2b32  33c9                 xor ecx, ecx
// 009f2b34  c7009c90c100         mov dword ptr [eax], 0xc1909c
// 009f2b3a  894804               mov dword ptr [eax + 4], ecx
// 009f2b3d  894810               mov dword ptr [eax + 0x10], ecx
// 009f2b40  89480c               mov dword ptr [eax + 0xc], ecx
// 009f2b43  894808               mov dword ptr [eax + 8], ecx
// 009f2b46  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009f2b30
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009f2b30();
};
S_func_009f2b30::S_func_009f2b30()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
