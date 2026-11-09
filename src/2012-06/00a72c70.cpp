// roc 2012-06 00a72c70  unit: CXTPRibbonGroup  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a72c70
//
// 00a72c70  8bc1                 mov eax, ecx
// 00a72c72  33c9                 xor ecx, ecx
// 00a72c74  c700046fc200         mov dword ptr [eax], 0xc26f04
// 00a72c7a  894804               mov dword ptr [eax + 4], ecx
// 00a72c7d  894810               mov dword ptr [eax + 0x10], ecx
// 00a72c80  89480c               mov dword ptr [eax + 0xc], ecx
// 00a72c83  894808               mov dword ptr [eax + 8], ecx
// 00a72c86  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a72c70
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a72c70();
};
S_func_00a72c70::S_func_00a72c70()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
