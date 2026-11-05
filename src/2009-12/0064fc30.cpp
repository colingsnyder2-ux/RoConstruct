// from server: 100% by nuck16
// roc 2009-12 0064fc30  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fc30  64a100000000         mov eax, dword ptr fs:[0]
// 0064fc36  6aff                 push -1
// 0064fc38  68de229400           push 0x9422de
// 0064fc3d  50                   push eax
// 0064fc3e  b801000000           mov eax, 1
// 0064fc43  64892500000000       mov dword ptr fs:[0], esp
// 0064fc4a  84059888b800         test byte ptr [0xb88898], al
// 0064fc50  7532                 jne 0x64fc84
// 0064fc52  09059888b800         or dword ptr [0xb88898], eax
// 0064fc58  6a00                 push 0
// 0064fc5a  68e8e79d00           push 0x9de7e8
// 0064fc5f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064fc67  e844a7dbff           call 0x40a3b0
// 0064fc6c  50                   push eax
// 0064fc6d  b9a087b800           mov ecx, 0xb887a0
// 0064fc72  e889430100           call 0x664000
// 0064fc77  6800359800           push 0x983500
// 0064fc7c  e8a84c1a00           call 0x7f4929
// 0064fc81  83c404               add esp, 4
// 0064fc84  8b0c24               mov ecx, dword ptr [esp]
// 0064fc87  b8a087b800           mov eax, 0xb887a0
// 0064fc8c  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fc93  83c40c               add esp, 0xc
// 0064fc96  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "JointInstance", 0);
    return object;
}
