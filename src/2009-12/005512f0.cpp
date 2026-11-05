// from server: 100% by nuck16
// roc 2009-12 005512f0  unit: RBX::Network::VPeer::?$BoundFuncDesc  size: 99 bytes
//
// 005512f0  64a100000000         mov eax, dword ptr fs:[0]
// 005512f6  6aff                 push -1
// 005512f8  680ead9300           push 0x93ad0e
// 005512fd  50                   push eax
// 005512fe  b801000000           mov eax, 1
// 00551303  64892500000000       mov dword ptr fs:[0], esp
// 0055130a  8405e807b800         test byte ptr [0xb807e8], al
// 00551310  752e                 jne 0x551340
// 00551312  0905e807b800         or dword ptr [0xb807e8], eax
// 00551318  6800f69d00           push 0x9df600
// 0055131d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00551325  e8b60f0e00           call 0x6322e0
// 0055132a  83c404               add esp, 4
// 0055132d  a3e407b800           mov dword ptr [0xb807e4], eax
// 00551332  8b0c24               mov ecx, dword ptr [esp]
// 00551335  64890d00000000       mov dword ptr fs:[0], ecx
// 0055133c  83c40c               add esp, 0xc
// 0055133f  c3                   ret 
// 00551340  8b0c24               mov ecx, dword ptr [esp]
// 00551343  a1e407b800           mov eax, dword ptr [0xb807e4]
// 00551348  64890d00000000       mov dword ptr fs:[0], ecx
// 0055134f  83c40c               add esp, 0xc
// 00551352  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("PhysicsService");
    return *name;
}
