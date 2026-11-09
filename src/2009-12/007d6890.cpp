// from server: 100% by nuck16
// roc 2009-12 007d6890  unit: RBX::PartDropTool  size: 99 bytes
//
// 007d6890  64a100000000         mov eax, dword ptr fs:[0]
// 007d6896  6aff                 push -1
// 007d6898  681e6f9500           push 0x956f1e
// 007d689d  50                   push eax
// 007d689e  b801000000           mov eax, 1
// 007d68a3  64892500000000       mov dword ptr fs:[0], esp
// 007d68aa  8405448eb900         test byte ptr [0xb98e44], al
// 007d68b0  752e                 jne 0x7d68e0
// 007d68b2  0905448eb900         or dword ptr [0xb98e44], eax
// 007d68b8  68743db600           push 0xb63d74
// 007d68bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 007d68c5  e816bae5ff           call 0x6322e0
// 007d68ca  83c404               add esp, 4
// 007d68cd  a3408eb900           mov dword ptr [0xb98e40], eax
// 007d68d2  8b0c24               mov ecx, dword ptr [esp]
// 007d68d5  64890d00000000       mov dword ptr fs:[0], ecx
// 007d68dc  83c40c               add esp, 0xc
// 007d68df  c3                   ret 
// 007d68e0  8b0c24               mov ecx, dword ptr [esp]
// 007d68e3  a1408eb900           mov eax, dword ptr [0xb98e40]
// 007d68e8  64890d00000000       mov dword ptr fs:[0], ecx
// 007d68ef  83c40c               add esp, 0xc
// 007d68f2  c3                   ret 

extern char string_00b63d74[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b63d74);
    return *name;
}
