// from server: 100% by nuck16
// roc 2009-12 00537730  unit: RBX::Network::Replicator  size: 99 bytes
//
// 00537730  64a100000000         mov eax, dword ptr fs:[0]
// 00537736  6aff                 push -1
// 00537738  686e979300           push 0x93976e
// 0053773d  50                   push eax
// 0053773e  b801000000           mov eax, 1
// 00537743  64892500000000       mov dword ptr fs:[0], esp
// 0053774a  84056c05b800         test byte ptr [0xb8056c], al
// 00537750  752e                 jne 0x537780
// 00537752  09056c05b800         or dword ptr [0xb8056c], eax
// 00537758  6800b7b400           push 0xb4b700
// 0053775d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00537765  e876ab0f00           call 0x6322e0
// 0053776a  83c404               add esp, 4
// 0053776d  a36805b800           mov dword ptr [0xb80568], eax
// 00537772  8b0c24               mov ecx, dword ptr [esp]
// 00537775  64890d00000000       mov dword ptr fs:[0], ecx
// 0053777c  83c40c               add esp, 0xc
// 0053777f  c3                   ret 
// 00537780  8b0c24               mov ecx, dword ptr [esp]
// 00537783  a16805b800           mov eax, dword ptr [0xb80568]
// 00537788  64890d00000000       mov dword ptr fs:[0], ecx
// 0053778f  83c40c               add esp, 0xc
// 00537792  c3                   ret 

extern char string_00b4b700[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4b700);
    return *name;
}
