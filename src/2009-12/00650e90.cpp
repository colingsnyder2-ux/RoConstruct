// from server: 100% by nuck16
// roc 2009-12 00650e90  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650e90  64a100000000         mov eax, dword ptr fs:[0]
// 00650e96  6aff                 push -1
// 00650e98  681e289400           push 0x94281e
// 00650e9d  50                   push eax
// 00650e9e  b801000000           mov eax, 1
// 00650ea3  64892500000000       mov dword ptr fs:[0], esp
// 00650eaa  840598b2b800         test byte ptr [0xb8b298], al
// 00650eb0  7532                 jne 0x650ee4
// 00650eb2  090598b2b800         or dword ptr [0xb8b298], eax
// 00650eb8  6a00                 push 0
// 00650eba  680895b500           push 0xb59508
// 00650ebf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650ec7  e834ddffff           call 0x64ec00
// 00650ecc  50                   push eax
// 00650ecd  b9a0b1b800           mov ecx, 0xb8b1a0
// 00650ed2  e829310100           call 0x664000
// 00650ed7  6860329800           push 0x983260
// 00650edc  e8483a1a00           call 0x7f4929
// 00650ee1  83c404               add esp, 4
// 00650ee4  8b0c24               mov ecx, dword ptr [esp]
// 00650ee7  b8a0b1b800           mov eax, 0xb8b1a0
// 00650eec  64890d00000000       mov dword ptr fs:[0], ecx
// 00650ef3  83c40c               add esp, 0xc
// 00650ef6  c3                   ret 

struct Base;
Base &get_64ec00();
extern char string_00b59508[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64ec00(), string_00b59508, 0);
    return object;
}
