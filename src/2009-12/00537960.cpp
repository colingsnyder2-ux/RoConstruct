// from server: 100% by nuck16
// roc 2009-12 00537960  unit: RBX::Network::Replicator  size: 99 bytes
//
// 00537960  64a100000000         mov eax, dword ptr fs:[0]
// 00537966  6aff                 push -1
// 00537968  680e989300           push 0x93980e
// 0053796d  50                   push eax
// 0053796e  b801000000           mov eax, 1
// 00537973  64892500000000       mov dword ptr fs:[0], esp
// 0053797a  84059405b800         test byte ptr [0xb80594], al
// 00537980  752e                 jne 0x5379b0
// 00537982  09059405b800         or dword ptr [0xb80594], eax
// 00537988  6828e89d00           push 0x9de828
// 0053798d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537995  e846a90f00           call 0x6322e0
// 0053799a  83c404               add esp, 4
// 0053799d  a39005b800           mov dword ptr [0xb80590], eax
// 005379a2  8b0c24               mov ecx, dword ptr [esp]
// 005379a5  64890d00000000       mov dword ptr fs:[0], ecx
// 005379ac  83c40c               add esp, 0xc
// 005379af  c3                   ret 
// 005379b0  8b0c24               mov ecx, dword ptr [esp]
// 005379b3  a19005b800           mov eax, dword ptr [0xb80590]
// 005379b8  64890d00000000       mov dword ptr fs:[0], ecx
// 005379bf  83c40c               add esp, 0xc
// 005379c2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("RotateP");
    return *name;
}
