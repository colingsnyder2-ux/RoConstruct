// roc 2012-06 006283b0  unit: G3D::Log  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006283b0
//
// 006283b0  8bc1                 mov eax, ecx
// 006283b2  33c9                 xor ecx, ecx
// 006283b4  c7003835b800         mov dword ptr [eax], 0xb83538
// 006283ba  894804               mov dword ptr [eax + 4], ecx
// 006283bd  894808               mov dword ptr [eax + 8], ecx
// 006283c0  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_006283b0
{
    void* p0;
    int z0;
    int z1;
    S_func_006283b0();
};
S_func_006283b0::S_func_006283b0()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = 0;
}
