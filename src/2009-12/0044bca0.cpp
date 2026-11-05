// from server: 100% by nuck16
// roc 2009-12 0044bca0  unit: CRobloxApp  size: 99 bytes
//
// 0044bca0  64a100000000         mov eax, dword ptr fs:[0]
// 0044bca6  6aff                 push -1
// 0044bca8  68cead9200           push 0x92adce
// 0044bcad  50                   push eax
// 0044bcae  b801000000           mov eax, 1
// 0044bcb3  64892500000000       mov dword ptr fs:[0], esp
// 0044bcba  840564b4b700         test byte ptr [0xb7b464], al
// 0044bcc0  752e                 jne 0x44bcf0
// 0044bcc2  090564b4b700         or dword ptr [0xb7b464], eax
// 0044bcc8  6818729d00           push 0x9d7218
// 0044bccd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0044bcd5  e806661e00           call 0x6322e0
// 0044bcda  83c404               add esp, 4
// 0044bcdd  a360b4b700           mov dword ptr [0xb7b460], eax
// 0044bce2  8b0c24               mov ecx, dword ptr [esp]
// 0044bce5  64890d00000000       mov dword ptr fs:[0], ecx
// 0044bcec  83c40c               add esp, 0xc
// 0044bcef  c3                   ret 
// 0044bcf0  8b0c24               mov ecx, dword ptr [esp]
// 0044bcf3  a160b4b700           mov eax, dword ptr [0xb7b460]
// 0044bcf8  64890d00000000       mov dword ptr fs:[0], ecx
// 0044bcff  83c40c               add esp, 0xc
// 0044bd02  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("GameSettings");
    return *name;
}
