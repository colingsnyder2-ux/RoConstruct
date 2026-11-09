// roc 2012-06 00a56780  unit: CXTPPropertyGridInplaceButton  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a56780
//
// 00a56780  8bc1                 mov eax, ecx
// 00a56782  33c9                 xor ecx, ecx
// 00a56784  c7006835c200         mov dword ptr [eax], 0xc23568
// 00a5678a  894804               mov dword ptr [eax + 4], ecx
// 00a5678d  894810               mov dword ptr [eax + 0x10], ecx
// 00a56790  89480c               mov dword ptr [eax + 0xc], ecx
// 00a56793  894808               mov dword ptr [eax + 8], ecx
// 00a56796  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a56780
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a56780();
};
S_func_00a56780::S_func_00a56780()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
