// roc 2012-06 009f2b50  unit: CXTPPropertyGridItemConstraints  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f2b50
//
// 009f2b50  8bc1                 mov eax, ecx
// 009f2b52  33c9                 xor ecx, ecx
// 009f2b54  c7003094c100         mov dword ptr [eax], 0xc19430
// 009f2b5a  894804               mov dword ptr [eax + 4], ecx
// 009f2b5d  894810               mov dword ptr [eax + 0x10], ecx
// 009f2b60  89480c               mov dword ptr [eax + 0xc], ecx
// 009f2b63  894808               mov dword ptr [eax + 8], ecx
// 009f2b66  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009f2b50
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009f2b50();
};
S_func_009f2b50::S_func_009f2b50()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
