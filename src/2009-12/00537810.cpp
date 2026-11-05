// from server: 100% by nuck16
// roc 2009-12 00537810  unit: RBX::Network::Replicator  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00537810
//
// 00537810  64a100000000         mov eax, dword ptr fs:[0]
// 00537816  6aff                 push -1
// 00537818  68ae979300           push 0x9397ae
// 0053781d  50                   push eax
// 0053781e  b801000000           mov eax, 1
// 00537823  64892500000000       mov dword ptr fs:[0], esp
// 0053782a  84057c05b800         test byte ptr [0xb8057c], al
// 00537830  752e                 jne 0x537860
// 00537832  09057c05b800         or dword ptr [0xb8057c], eax
// 00537838  6800e89d00           push 0x9de800
// 0053783d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537845  e896aa0f00           call 0x6322e0
// 0053784a  83c404               add esp, 4
// 0053784d  a37805b800           mov dword ptr [0xb80578], eax
// 00537852  8b0c24               mov ecx, dword ptr [esp]
// 00537855  64890d00000000       mov dword ptr fs:[0], ecx
// 0053785c  83c40c               add esp, 0xc
// 0053785f  c3                   ret 
// 00537860  8b0c24               mov ecx, dword ptr [esp]
// 00537863  a17805b800           mov eax, dword ptr [0xb80578]
// 00537868  64890d00000000       mov dword ptr fs:[0], ecx
// 0053786f  83c40c               add esp, 0xc
// 00537872  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Weld");
    return *name;
}
