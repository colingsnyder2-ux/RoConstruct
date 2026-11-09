// from server: 100% by nuck16
// roc 2009-12 0064f990  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064f990  64a100000000         mov eax, dword ptr fs:[0]
// 0064f996  6aff                 push -1
// 0064f998  681e229400           push 0x94221e
// 0064f99d  50                   push eax
// 0064f99e  b801000000           mov eax, 1
// 0064f9a3  64892500000000       mov dword ptr fs:[0], esp
// 0064f9aa  84059882b800         test byte ptr [0xb88298], al
// 0064f9b0  7532                 jne 0x64f9e4
// 0064f9b2  09059882b800         or dword ptr [0xb88298], eax
// 0064f9b8  6a00                 push 0
// 0064f9ba  68f0c59d00           push 0x9dc5f0
// 0064f9bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f9c7  e8e4a9dbff           call 0x40a3b0
// 0064f9cc  50                   push eax
// 0064f9cd  b9a081b800           mov ecx, 0xb881a0
// 0064f9d2  e829460100           call 0x664000
// 0064f9d7  6860359800           push 0x983560
// 0064f9dc  e8484f1a00           call 0x7f4929
// 0064f9e1  83c404               add esp, 4
// 0064f9e4  8b0c24               mov ecx, dword ptr [esp]
// 0064f9e7  b8a081b800           mov eax, 0xb881a0
// 0064f9ec  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f9f3  83c40c               add esp, 0xc
// 0064f9f6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "FaceInstance", 0);
    return object;
}
