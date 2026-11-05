// from server: 100% by nuck16
// roc 2009-12 00650800  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650800  64a100000000         mov eax, dword ptr fs:[0]
// 00650806  6aff                 push -1
// 00650808  683e269400           push 0x94263e
// 0065080d  50                   push eax
// 0065080e  b801000000           mov eax, 1
// 00650813  64892500000000       mov dword ptr fs:[0], esp
// 0065081a  840598a3b800         test byte ptr [0xb8a398], al
// 00650820  7532                 jne 0x650854
// 00650822  090598a3b800         or dword ptr [0xb8a398], eax
// 00650828  6a00                 push 0
// 0065082a  68681fb500           push 0xb51f68
// 0065082f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650837  e8749bdbff           call 0x40a3b0
// 0065083c  50                   push eax
// 0065083d  b9a0a2b800           mov ecx, 0xb8a2a0
// 00650842  e8b9370100           call 0x664000
// 00650847  6850339800           push 0x983350
// 0065084c  e8d8401a00           call 0x7f4929
// 00650851  83c404               add esp, 4
// 00650854  8b0c24               mov ecx, dword ptr [esp]
// 00650857  b8a0a2b800           mov eax, 0xb8a2a0
// 0065085c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650863  83c40c               add esp, 0xc
// 00650866  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b51f68[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b51f68, 0);
    return object;
}
