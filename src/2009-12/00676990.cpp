// from server: 100% by nuck16
// roc 2009-12 00676990  unit: RBX::UnifiedWidget  size: 99 bytes
//
// 00676990  64a100000000         mov eax, dword ptr fs:[0]
// 00676996  6aff                 push -1
// 00676998  687e549400           push 0x94547e
// 0067699d  50                   push eax
// 0067699e  b801000000           mov eax, 1
// 006769a3  64892500000000       mov dword ptr fs:[0], esp
// 006769aa  84056c0bb900         test byte ptr [0xb90b6c], al
// 006769b0  752e                 jne 0x6769e0
// 006769b2  09056c0bb900         or dword ptr [0xb90b6c], eax
// 006769b8  6898f79c00           push 0x9cf798
// 006769bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 006769c5  e816b9fbff           call 0x6322e0
// 006769ca  83c404               add esp, 4
// 006769cd  a3680bb900           mov dword ptr [0xb90b68], eax
// 006769d2  8b0c24               mov ecx, dword ptr [esp]
// 006769d5  64890d00000000       mov dword ptr fs:[0], ecx
// 006769dc  83c40c               add esp, 0xc
// 006769df  c3                   ret 
// 006769e0  8b0c24               mov ecx, dword ptr [esp]
// 006769e3  a1680bb900           mov eax, dword ptr [0xb90b68]
// 006769e8  64890d00000000       mov dword ptr fs:[0], ecx
// 006769ef  83c40c               add esp, 0xc
// 006769f2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("GlobalSettings");
    return *name;
}
