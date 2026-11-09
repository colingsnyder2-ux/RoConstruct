// roc 2012-06 009fa510  unit: CXTPControlGalleryPaintManager  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009fa510
//
// 009fa510  8bc1                 mov eax, ecx
// 009fa512  33c9                 xor ecx, ecx
// 009fa514  c700c0b1c100         mov dword ptr [eax], 0xc1b1c0
// 009fa51a  894804               mov dword ptr [eax + 4], ecx
// 009fa51d  894810               mov dword ptr [eax + 0x10], ecx
// 009fa520  89480c               mov dword ptr [eax + 0xc], ecx
// 009fa523  894808               mov dword ptr [eax + 8], ecx
// 009fa526  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_009fa510
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_009fa510();
};
S_func_009fa510::S_func_009fa510()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
