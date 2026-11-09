// roc 2012-06 005ba530  unit: RBX::Network::InterpolatingPhysicsReceiver::Job  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 005ba530
//
// 005ba530  8bc1                 mov eax, ecx
// 005ba532  33c9                 xor ecx, ecx
// 005ba534  c700f402b800         mov dword ptr [eax], 0xb802f4
// 005ba53a  894804               mov dword ptr [eax + 4], ecx
// 005ba53d  894808               mov dword ptr [eax + 8], ecx
// 005ba540  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G;
struct S_func_005ba530
{
    void* p0;
    int z0;
    int z1;
    S_func_005ba530();
};
S_func_005ba530::S_func_005ba530()
{
    p0 = (void*)&G;
    z0 = 0;
    z1 = 0;
}
