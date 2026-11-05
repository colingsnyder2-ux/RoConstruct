// roc 2012-06 009861f0  unit: CPatchedControlComboBox  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009861f0
//
// 009861f0  8bc1                 mov eax, ecx
// 009861f2  33c9                 xor ecx, ecx
// 009861f4  c70000cec000         mov dword ptr [eax], 0xc0ce00
// 009861fa  894804               mov dword ptr [eax + 4], ecx
// 009861fd  894810               mov dword ptr [eax + 0x10], ecx
// 00986200  89480c               mov dword ptr [eax + 0xc], ecx
// 00986203  894808               mov dword ptr [eax + 8], ecx
// 00986206  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009861f0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009861f0();
};
S_func_009861f0::S_func_009861f0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
