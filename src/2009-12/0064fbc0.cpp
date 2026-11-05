// from server: 100% by nuck16
// roc 2009-12 0064fbc0  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fbc0  64a100000000         mov eax, dword ptr fs:[0]
// 0064fbc6  6aff                 push -1
// 0064fbc8  68be229400           push 0x9422be
// 0064fbcd  50                   push eax
// 0064fbce  b801000000           mov eax, 1
// 0064fbd3  64892500000000       mov dword ptr fs:[0], esp
// 0064fbda  84059887b800         test byte ptr [0xb88798], al
// 0064fbe0  7532                 jne 0x64fc14
// 0064fbe2  09059887b800         or dword ptr [0xb88798], eax
// 0064fbe8  6a00                 push 0
// 0064fbea  68b0cdb300           push 0xb3cdb0
// 0064fbef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fbf7  e8b4a7dbff           call 0x40a3b0
// 0064fbfc  50                   push eax
// 0064fbfd  b9a086b800           mov ecx, 0xb886a0
// 0064fc02  e8f9430100           call 0x664000
// 0064fc07  6810359800           push 0x983510
// 0064fc0c  e8184d1a00           call 0x7f4929
// 0064fc11  83c404               add esp, 4
// 0064fc14  8b0c24               mov ecx, dword ptr [esp]
// 0064fc17  b8a086b800           mov eax, 0xb886a0
// 0064fc1c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fc23  83c40c               add esp, 0xc
// 0064fc26  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3cdb0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3cdb0, 0);
    return object;
}
