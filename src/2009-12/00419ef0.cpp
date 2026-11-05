// from server: 100% by nuck16
// roc 2009-12 00419ef0  unit: CInsertObjectDialog  size: 99 bytes
//
// 00419ef0  64a100000000         mov eax, dword ptr fs:[0]
// 00419ef6  6aff                 push -1
// 00419ef8  684e849200           push 0x92844e
// 00419efd  50                   push eax
// 00419efe  b801000000           mov eax, 1
// 00419f03  64892500000000       mov dword ptr fs:[0], esp
// 00419f0a  840508a2b700         test byte ptr [0xb7a208], al
// 00419f10  752e                 jne 0x419f40
// 00419f12  090508a2b700         or dword ptr [0xb7a208], eax
// 00419f18  68e8e79c00           push 0x9ce7e8
// 00419f1d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00419f25  e8b6832100           call 0x6322e0
// 00419f2a  83c404               add esp, 4
// 00419f2d  a304a2b700           mov dword ptr [0xb7a204], eax
// 00419f32  8b0c24               mov ecx, dword ptr [esp]
// 00419f35  64890d00000000       mov dword ptr fs:[0], ecx
// 00419f3c  83c40c               add esp, 0xc
// 00419f3f  c3                   ret 
// 00419f40  8b0c24               mov ecx, dword ptr [esp]
// 00419f43  a104a2b700           mov eax, dword ptr [0xb7a204]
// 00419f48  64890d00000000       mov dword ptr fs:[0], ecx
// 00419f4f  83c40c               add esp, 0xc
// 00419f52  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("DataModel");
    return *name;
}
