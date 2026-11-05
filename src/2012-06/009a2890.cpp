// roc 2012-06 009a2890  unit: MyXTPCommandBars  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a2890
//
// 009a2890  8bc1                 mov eax, ecx
// 009a2892  33c9                 xor ecx, ecx
// 009a2894  c7009cf3c000         mov dword ptr [eax], 0xc0f39c
// 009a289a  894804               mov dword ptr [eax + 4], ecx
// 009a289d  894810               mov dword ptr [eax + 0x10], ecx
// 009a28a0  89480c               mov dword ptr [eax + 0xc], ecx
// 009a28a3  894808               mov dword ptr [eax + 8], ecx
// 009a28a6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009a2890
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009a2890();
};
S_func_009a2890::S_func_009a2890()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
