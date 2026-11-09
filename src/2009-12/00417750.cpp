// from server: 100% by nuck16
// roc 2009-12 00417750  unit: VCContent::?$CComObject  size: 99 bytes
//
// 00417750  64a100000000         mov eax, dword ptr fs:[0]
// 00417756  6aff                 push -1
// 00417758  681e829200           push 0x92821e
// 0041775d  50                   push eax
// 0041775e  b801000000           mov eax, 1
// 00417763  64892500000000       mov dword ptr fs:[0], esp
// 0041776a  8405b8a1b700         test byte ptr [0xb7a1b8], al
// 00417770  752e                 jne 0x4177a0
// 00417772  0905b8a1b700         or dword ptr [0xb7a1b8], eax
// 00417778  68c01b9d00           push 0x9d1bc0
// 0041777d  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00417785  e856ab2100           call 0x6322e0
// 0041778a  83c404               add esp, 4
// 0041778d  a3b4a1b700           mov dword ptr [0xb7a1b4], eax
// 00417792  8b0c24               mov ecx, dword ptr [esp]
// 00417795  64890d00000000       mov dword ptr fs:[0], ecx
// 0041779c  83c40c               add esp, 0xc
// 0041779f  c3                   ret 
// 004177a0  8b0c24               mov ecx, dword ptr [esp]
// 004177a3  a1b4a1b700           mov eax, dword ptr [0xb7a1b4]
// 004177a8  64890d00000000       mov dword ptr fs:[0], ecx
// 004177af  83c40c               add esp, 0xc
// 004177b2  c3                   ret 

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup("Tool");
    return *name;
}
