// from server: 100% by nuck16
// roc 2009-12 00537ab0  unit: RBX::Network::Replicator  size: 99 bytes
//
// 00537ab0  64a100000000         mov eax, dword ptr fs:[0]
// 00537ab6  6aff                 push -1
// 00537ab8  686e989300           push 0x93986e
// 00537abd  50                   push eax
// 00537abe  b801000000           mov eax, 1
// 00537ac3  64892500000000       mov dword ptr fs:[0], esp
// 00537aca  8405ac05b800         test byte ptr [0xb805ac], al
// 00537ad0  752e                 jne 0x537b00
// 00537ad2  0905ac05b800         or dword ptr [0xb805ac], eax
// 00537ad8  6830f59d00           push 0x9df530
// 00537add  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537ae5  e8f6a70f00           call 0x6322e0
// 00537aea  83c404               add esp, 4
// 00537aed  a3a805b800           mov dword ptr [0xb805a8], eax
// 00537af2  8b0c24               mov ecx, dword ptr [esp]
// 00537af5  64890d00000000       mov dword ptr fs:[0], ecx
// 00537afc  83c40c               add esp, 0xc
// 00537aff  c3                   ret 
// 00537b00  8b0c24               mov ecx, dword ptr [esp]
// 00537b03  a1a805b800           mov eax, dword ptr [0xb805a8]
// 00537b08  64890d00000000       mov dword ptr fs:[0], ecx
// 00537b0f  83c40c               add esp, 0xc
// 00537b12  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("JointsService");
    return *name;
}
