// from server: 100% by nuck16
// roc 2009-12 0052bb10  unit: RBX::Network::Server  size: 99 bytes
//
// 0052bb10  64a100000000         mov eax, dword ptr fs:[0]
// 0052bb16  6aff                 push -1
// 0052bb18  68ee8f9300           push 0x938fee
// 0052bb1d  50                   push eax
// 0052bb1e  b801000000           mov eax, 1
// 0052bb23  64892500000000       mov dword ptr fs:[0], esp
// 0052bb2a  84055c01b800         test byte ptr [0xb8015c], al
// 0052bb30  752e                 jne 0x52bb60
// 0052bb32  09055c01b800         or dword ptr [0xb8015c], eax
// 0052bb38  6878b5b400           push 0xb4b578
// 0052bb3d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0052bb45  e896671000           call 0x6322e0
// 0052bb4a  83c404               add esp, 4
// 0052bb4d  a35801b800           mov dword ptr [0xb80158], eax
// 0052bb52  8b0c24               mov ecx, dword ptr [esp]
// 0052bb55  64890d00000000       mov dword ptr fs:[0], ecx
// 0052bb5c  83c40c               add esp, 0xc
// 0052bb5f  c3                   ret 
// 0052bb60  8b0c24               mov ecx, dword ptr [esp]
// 0052bb63  a15801b800           mov eax, dword ptr [0xb80158]
// 0052bb68  64890d00000000       mov dword ptr fs:[0], ecx
// 0052bb6f  83c40c               add esp, 0xc
// 0052bb72  c3                   ret 

extern char string_00b4b578[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4b578);
    return *name;
}
