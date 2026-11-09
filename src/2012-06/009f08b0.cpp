// roc 2012-06 009f08b0  unit: CXTPPropertyGridView  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f08b0
//
// 009f08b0  8bc1                 mov eax, ecx
// 009f08b2  33c9                 xor ecx, ecx
// 009f08b4  c700b490c100         mov dword ptr [eax], 0xc190b4
// 009f08ba  894804               mov dword ptr [eax + 4], ecx
// 009f08bd  894810               mov dword ptr [eax + 0x10], ecx
// 009f08c0  89480c               mov dword ptr [eax + 0xc], ecx
// 009f08c3  894808               mov dword ptr [eax + 8], ecx
// 009f08c6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009f08b0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009f08b0();
};
S_func_009f08b0::S_func_009f08b0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
