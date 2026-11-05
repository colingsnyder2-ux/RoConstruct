// roc 2012-06 009b7cf0  unit: CInstanceRecord::CNameItem  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b7cf0
//
// 009b7cf0  8bc1                 mov eax, ecx
// 009b7cf2  33c9                 xor ecx, ecx
// 009b7cf4  c700f40dc100         mov dword ptr [eax], 0xc10df4
// 009b7cfa  894804               mov dword ptr [eax + 4], ecx
// 009b7cfd  894810               mov dword ptr [eax + 0x10], ecx
// 009b7d00  89480c               mov dword ptr [eax + 0xc], ecx
// 009b7d03  894808               mov dword ptr [eax + 8], ecx
// 009b7d06  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009b7cf0
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009b7cf0();
};
S_func_009b7cf0::S_func_009b7cf0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
