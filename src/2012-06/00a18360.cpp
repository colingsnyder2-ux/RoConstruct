// roc 2012-06 00a18360  unit: CXTPShortcutManager::CKeyHelper  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a18360
//
// 00a18360  8bc1                 mov eax, ecx
// 00a18362  33c9                 xor ecx, ecx
// 00a18364  c70060d5c100         mov dword ptr [eax], 0xc1d560
// 00a1836a  894804               mov dword ptr [eax + 4], ecx
// 00a1836d  894810               mov dword ptr [eax + 0x10], ecx
// 00a18370  89480c               mov dword ptr [eax + 0xc], ecx
// 00a18373  894808               mov dword ptr [eax + 8], ecx
// 00a18376  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a18360
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a18360();
};
S_func_00a18360::S_func_00a18360()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
