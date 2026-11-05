// roc 2012-06 00999e40  unit: CXTPImageManagerResource::CBitmapDC  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00999e40
//
// 00999e40  8bc1                 mov eax, ecx
// 00999e42  33c9                 xor ecx, ecx
// 00999e44  c70050e7c000         mov dword ptr [eax], 0xc0e750
// 00999e4a  894804               mov dword ptr [eax + 4], ecx
// 00999e4d  894810               mov dword ptr [eax + 0x10], ecx
// 00999e50  89480c               mov dword ptr [eax + 0xc], ecx
// 00999e53  894808               mov dword ptr [eax + 8], ecx
// 00999e56  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00999e40
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00999e40();
};
S_func_00999e40::S_func_00999e40()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
