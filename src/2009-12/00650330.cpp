// from server: 100% by nuck16
// roc 2009-12 00650330  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00650330  64a100000000         mov eax, dword ptr fs:[0]
// 00650336  6aff                 push -1
// 00650338  68de249400           push 0x9424de
// 0065033d  50                   push eax
// 0065033e  b801000000           mov eax, 1
// 00650343  64892500000000       mov dword ptr fs:[0], esp
// 0065034a  84059898b800         test byte ptr [0xb89898], al
// 00650350  7532                 jne 0x650384
// 00650352  09059898b800         or dword ptr [0xb89898], eax
// 00650358  6a00                 push 0
// 0065035a  68585eb500           push 0xb55e58
// 0065035f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00650367  e894efffff           call 0x64f300
// 0065036c  50                   push eax
// 0065036d  b9a097b800           mov ecx, 0xb897a0
// 00650372  e8893c0100           call 0x664000
// 00650377  6800349800           push 0x983400
// 0065037c  e8a8451a00           call 0x7f4929
// 00650381  83c404               add esp, 4
// 00650384  8b0c24               mov ecx, dword ptr [esp]
// 00650387  b8a097b800           mov eax, 0xb897a0
// 0065038c  64890d00000000       mov dword ptr fs:[0], ecx
// 00650393  83c40c               add esp, 0xc
// 00650396  c3                   ret 

struct Base;
Base &get_64f300();
extern char string_00b55e58[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64f300(), string_00b55e58, 0);
    return object;
}
