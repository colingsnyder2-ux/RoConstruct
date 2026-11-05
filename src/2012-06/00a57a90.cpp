// roc 2012-06 00a57a90  unit: VCEdit::?$CXTMaskEditT  size: 23 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a57a90
//
// 00a57a90  8bc1                 mov eax, ecx
// 00a57a92  33c9                 xor ecx, ecx
// 00a57a94  c700f838c200         mov dword ptr [eax], 0xc238f8
// 00a57a9a  894804               mov dword ptr [eax + 4], ecx
// 00a57a9d  894810               mov dword ptr [eax + 0x10], ecx
// 00a57aa0  89480c               mov dword ptr [eax + 0xc], ecx
// 00a57aa3  894808               mov dword ptr [eax + 8], ecx
// 00a57aa6  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_00a57a90
{
    void* p0;
    int z0;
    int z1;
    int z2;
    int z3;
    S_func_00a57a90();
};
S_func_00a57a90::S_func_00a57a90()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = z2 = z3 = 0;
}
