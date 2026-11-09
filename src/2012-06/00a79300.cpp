// roc 2012-06 00a79300  unit: CXTWindowMap  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a79300
//
// 00a79300  8bc1                 mov eax, ecx
// 00a79302  33c9                 xor ecx, ecx
// 00a79304  c7004c98c200         mov dword ptr [eax], 0xc2984c
// 00a7930a  89480c               mov dword ptr [eax + 0xc], ecx
// 00a7930d  894808               mov dword ptr [eax + 8], ecx
// 00a79310  894804               mov dword ptr [eax + 4], ecx
// 00a79313  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a79300
{
    void* p0;
    int z0;
    int z1;
    int z2;
    S_func_00a79300();
};
S_func_00a79300::S_func_00a79300()
{
    p0 = (void*)&G;
    z0 = z1 = z2 = 0;
}
