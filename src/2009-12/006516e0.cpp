// from server: 100% by nuck16
// roc 2009-12 006516e0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 006516e0  64a100000000         mov eax, dword ptr fs:[0]
// 006516e6  6aff                 push -1
// 006516e8  687e2a9400           push 0x942a7e
// 006516ed  50                   push eax
// 006516ee  b801000000           mov eax, 1
// 006516f3  64892500000000       mov dword ptr fs:[0], esp
// 006516fa  840598c5b800         test byte ptr [0xb8c598], al
// 00651700  7532                 jne 0x651734
// 00651702  090598c5b800         or dword ptr [0xb8c598], eax
// 00651708  6a02                 push 2
// 0065170a  689cfdb500           push 0xb5fd9c
// 0065170f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00651717  e8948cdbff           call 0x40a3b0
// 0065171c  50                   push eax
// 0065171d  b9a0c4b800           mov ecx, 0xb8c4a0
// 00651722  e8d9280100           call 0x664000
// 00651727  6830319800           push 0x983130
// 0065172c  e8f8311a00           call 0x7f4929
// 00651731  83c404               add esp, 4
// 00651734  8b0c24               mov ecx, dword ptr [esp]
// 00651737  b8a0c4b800           mov eax, 0xb8c4a0
// 0065173c  64890d00000000       mov dword ptr fs:[0], ecx
// 00651743  83c40c               add esp, 0xc
// 00651746  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b5fd9c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b5fd9c, 2);
    return object;
}
