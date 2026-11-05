// from server: 100% by nuck16
// roc 2009-12 0076b330  unit: RBX::VContentFilter::?$BoundFuncDesc  size: 99 bytes
//
// 0076b330  64a100000000         mov eax, dword ptr fs:[0]
// 0076b336  6aff                 push -1
// 0076b338  682e289500           push 0x95282e
// 0076b33d  50                   push eax
// 0076b33e  b801000000           mov eax, 1
// 0076b343  64892500000000       mov dword ptr fs:[0], esp
// 0076b34a  8405a07eb900         test byte ptr [0xb97ea0], al
// 0076b350  752e                 jne 0x76b380
// 0076b352  0905a07eb900         or dword ptr [0xb97ea0], eax
// 0076b358  68507e9e00           push 0x9e7e50
// 0076b35d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0076b365  e8766fecff           call 0x6322e0
// 0076b36a  83c404               add esp, 4
// 0076b36d  a39c7eb900           mov dword ptr [0xb97e9c], eax
// 0076b372  8b0c24               mov ecx, dword ptr [esp]
// 0076b375  64890d00000000       mov dword ptr fs:[0], ecx
// 0076b37c  83c40c               add esp, 0xc
// 0076b37f  c3                   ret 
// 0076b380  8b0c24               mov ecx, dword ptr [esp]
// 0076b383  a19c7eb900           mov eax, dword ptr [0xb97e9c]
// 0076b388  64890d00000000       mov dword ptr fs:[0], ecx
// 0076b38f  83c40c               add esp, 0xc
// 0076b392  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Mouse");
    return *name;
}
