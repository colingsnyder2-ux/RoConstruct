// roc 2012-06 00a183a0  unit: CXTPShortcutManager::CKeyHelper  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a183a0
//
// 00a183a0  8bc1                 mov eax, ecx
// 00a183a2  33c9                 xor ecx, ecx
// 00a183a4  c70078d5c100         mov dword ptr [eax], 0xc1d578
// 00a183aa  894804               mov dword ptr [eax + 4], ecx
// 00a183ad  894810               mov dword ptr [eax + 0x10], ecx
// 00a183b0  89480c               mov dword ptr [eax + 0xc], ecx
// 00a183b3  894808               mov dword ptr [eax + 8], ecx
// 00a183b6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a183a0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a183a0();
};
S_func_00a183a0::S_func_00a183a0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
