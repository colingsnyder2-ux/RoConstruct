// from server: 100% by nuck16
// roc 2009-12 0054e6e0  unit: RBX::Network::IdSerializer  size: 99 bytes
//
// 0054e6e0  64a100000000         mov eax, dword ptr fs:[0]
// 0054e6e6  6aff                 push -1
// 0054e6e8  688ea79300           push 0x93a78e
// 0054e6ed  50                   push eax
// 0054e6ee  b801000000           mov eax, 1
// 0054e6f3  64892500000000       mov dword ptr fs:[0], esp
// 0054e6fa  84051806b800         test byte ptr [0xb80618], al
// 0054e700  752e                 jne 0x54e730
// 0054e702  09051806b800         or dword ptr [0xb80618], eax
// 0054e708  6880d09b00           push 0x9bd080
// 0054e70d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0054e715  e8c63b0e00           call 0x6322e0
// 0054e71a  83c404               add esp, 4
// 0054e71d  a31406b800           mov dword ptr [0xb80614], eax
// 0054e722  8b0c24               mov ecx, dword ptr [esp]
// 0054e725  64890d00000000       mov dword ptr fs:[0], ecx
// 0054e72c  83c40c               add esp, 0xc
// 0054e72f  c3                   ret 
// 0054e730  8b0c24               mov ecx, dword ptr [esp]
// 0054e733  a11406b800           mov eax, dword ptr [0xb80614]
// 0054e738  64890d00000000       mov dword ptr fs:[0], ecx
// 0054e73f  83c40c               add esp, 0xc
// 0054e742  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("NetworkReplicator");
    return *name;
}
