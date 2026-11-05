// from server: 100% by nuck16
// roc 2009-12 0064ee30  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064ee30  64a100000000         mov eax, dword ptr fs:[0]
// 0064ee36  6aff                 push -1
// 0064ee38  68de1e9400           push 0x941ede
// 0064ee3d  50                   push eax
// 0064ee3e  b801000000           mov eax, 1
// 0064ee43  64892500000000       mov dword ptr fs:[0], esp
// 0064ee4a  84059868b800         test byte ptr [0xb86898], al
// 0064ee50  7532                 jne 0x64ee84
// 0064ee52  09059868b800         or dword ptr [0xb86898], eax
// 0064ee58  6a00                 push 0
// 0064ee5a  68e0309d00           push 0x9d30e0
// 0064ee5f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064ee67  e844b5dbff           call 0x40a3b0
// 0064ee6c  50                   push eax
// 0064ee6d  b9a067b800           mov ecx, 0xb867a0
// 0064ee72  e889510100           call 0x664000
// 0064ee77  6800379800           push 0x983700
// 0064ee7c  e8a85a1a00           call 0x7f4929
// 0064ee81  83c404               add esp, 4
// 0064ee84  8b0c24               mov ecx, dword ptr [esp]
// 0064ee87  b8a067b800           mov eax, 0xb867a0
// 0064ee8c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ee93  83c40c               add esp, 0xc
// 0064ee96  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Accoutrement", 0);
    return object;
}
