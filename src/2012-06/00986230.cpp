// roc 2012-06 00986230  unit: CPatchedControlComboBox  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00986230
//
// 00986230  8bc1                 mov eax, ecx
// 00986232  33c9                 xor ecx, ecx
// 00986234  c70018cec000         mov dword ptr [eax], 0xc0ce18
// 0098623a  894804               mov dword ptr [eax + 4], ecx
// 0098623d  894810               mov dword ptr [eax + 0x10], ecx
// 00986240  89480c               mov dword ptr [eax + 0xc], ecx
// 00986243  894808               mov dword ptr [eax + 8], ecx
// 00986246  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00986230
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00986230();
};
S_func_00986230::S_func_00986230()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
