// from server: 100% by nuck16
// roc 2009-12 00577890  unit: RBX::ViewRbxGfx  size: 99 bytes
//
// 00577890  64a100000000         mov eax, dword ptr fs:[0]
// 00577896  6aff                 push -1
// 00577898  682ebf9300           push 0x93bf2e
// 0057789d  50                   push eax
// 0057789e  b801000000           mov eax, 1
// 005778a3  64892500000000       mov dword ptr fs:[0], esp
// 005778aa  84056027b800         test byte ptr [0xb82760], al
// 005778b0  752e                 jne 0x5778e0
// 005778b2  09056027b800         or dword ptr [0xb82760], eax
// 005778b8  6888d8b400           push 0xb4d888
// 005778bd  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 005778c5  e816aa0b00           call 0x6322e0
// 005778ca  83c404               add esp, 4
// 005778cd  a35c27b800           mov dword ptr [0xb8275c], eax
// 005778d2  8b0c24               mov ecx, dword ptr [esp]
// 005778d5  64890d00000000       mov dword ptr fs:[0], ecx
// 005778dc  83c40c               add esp, 0xc
// 005778df  c3                   ret 
// 005778e0  8b0c24               mov ecx, dword ptr [esp]
// 005778e3  a15c27b800           mov eax, dword ptr [0xb8275c]
// 005778e8  64890d00000000       mov dword ptr fs:[0], ecx
// 005778ef  83c40c               add esp, 0xc
// 005778f2  c3                   ret 

extern char string_00b4d888[];

struct Name
{
    static const Name &lookup(const char *name);
};

const Name &f()
{
    static const Name *name = &Name::lookup(string_00b4d888);
    return *name;
}
