// from server: 100% by nuck16
// roc 2009-12 006b63c0  unit: RBX::Soundscape::W4ReverbType::?$EnumDesc  size: 103 bytes
//
// 006b63c0  64a100000000         mov eax, dword ptr fs:[0]
// 006b63c6  6aff                 push -1
// 006b63c8  687e869400           push 0x94867e
// 006b63cd  50                   push eax
// 006b63ce  b801000000           mov eax, 1
// 006b63d3  64892500000000       mov dword ptr fs:[0], esp
// 006b63da  8405a01db900         test byte ptr [0xb91da0], al
// 006b63e0  7532                 jne 0x6b6414
// 006b63e2  0905a01db900         or dword ptr [0xb91da0], eax
// 006b63e8  6a00                 push 0
// 006b63ea  684ca7b300           push 0xb3a74c
// 006b63ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006b63f7  e8b43fd5ff           call 0x40a3b0
// 006b63fc  50                   push eax
// 006b63fd  b9a81cb900           mov ecx, 0xb91ca8
// 006b6402  e8f9dbfaff           call 0x664000
// 006b6407  68b0579800           push 0x9857b0
// 006b640c  e818e51300           call 0x7f4929
// 006b6411  83c404               add esp, 4
// 006b6414  8b0c24               mov ecx, dword ptr [esp]
// 006b6417  b8a81cb900           mov eax, 0xb91ca8
// 006b641c  64890d00000000       mov dword ptr fs:[0], ecx
// 006b6423  83c40c               add esp, 0xc
// 006b6426  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b3a74c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b3a74c, 0);
    return object;
}
