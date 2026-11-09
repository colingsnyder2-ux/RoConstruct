// from server: 100% by nuck16
// roc 2009-12 0064fe60  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0064fe60
//
// 0064fe60  64a100000000         mov eax, dword ptr fs:[0]
// 0064fe66  6aff                 push -1
// 0064fe68  687e239400           push 0x94237e
// 0064fe6d  50                   push eax
// 0064fe6e  b801000000           mov eax, 1
// 0064fe73  64892500000000       mov dword ptr fs:[0], esp
// 0064fe7a  8405988db800         test byte ptr [0xb88d98], al
// 0064fe80  7532                 jne 0x64feb4
// 0064fe82  0905988db800         or dword ptr [0xb88d98], eax
// 0064fe88  6a00                 push 0
// 0064fe8a  6818e89d00           push 0x9de818
// 0064fe8f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fe97  e894fdffff           call 0x64fc30
// 0064fe9c  50                   push eax
// 0064fe9d  b9a08cb800           mov ecx, 0xb88ca0
// 0064fea2  e859410100           call 0x664000
// 0064fea7  68b0349800           push 0x9834b0
// 0064feac  e8784a1a00           call 0x7f4929
// 0064feb1  83c404               add esp, 4
// 0064feb4  8b0c24               mov ecx, dword ptr [esp]
// 0064feb7  b8a08cb800           mov eax, 0xb88ca0
// 0064febc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fec3  83c40c               add esp, 0xc
// 0064fec6  c3                   ret 

struct Base;
Base &get_64fc30();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fc30(), "DynamicRotate", 0);
    return object;
}
