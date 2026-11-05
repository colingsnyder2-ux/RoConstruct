// from server: 100% by nuck16
// roc 2009-12 004137a0  unit: CutVerb  size: 99 bytes
//
// 004137a0  64a100000000         mov eax, dword ptr fs:[0]
// 004137a6  6aff                 push -1
// 004137a8  685e7e9200           push 0x927e5e
// 004137ad  50                   push eax
// 004137ae  b801000000           mov eax, 1
// 004137b3  64892500000000       mov dword ptr fs:[0], esp
// 004137ba  8405fca0b700         test byte ptr [0xb7a0fc], al
// 004137c0  752e                 jne 0x4137f0
// 004137c2  0905fca0b700         or dword ptr [0xb7a0fc], eax
// 004137c8  687859b300           push 0xb35978
// 004137cd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004137d5  e806eb2100           call 0x6322e0
// 004137da  83c404               add esp, 4
// 004137dd  a3f8a0b700           mov dword ptr [0xb7a0f8], eax
// 004137e2  8b0c24               mov ecx, dword ptr [esp]
// 004137e5  64890d00000000       mov dword ptr fs:[0], ecx
// 004137ec  83c40c               add esp, 0xc
// 004137ef  c3                   ret 
// 004137f0  8b0c24               mov ecx, dword ptr [esp]
// 004137f3  a1f8a0b700           mov eax, dword ptr [0xb7a0f8]
// 004137f8  64890d00000000       mov dword ptr fs:[0], ecx
// 004137ff  83c40c               add esp, 0xc
// 00413802  c3                   ret 

extern char string_00b35978[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b35978);
    return *name;
}
