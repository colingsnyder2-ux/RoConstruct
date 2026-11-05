// from server: 100% by nuck16
// roc 2009-12 0063d4b0  unit: RBX::VTeam::?$FactoryProduct  size: 103 bytes
//
// 0063d4b0  64a100000000         mov eax, dword ptr fs:[0]
// 0063d4b6  6aff                 push -1
// 0063d4b8  68de0b9400           push 0x940bde
// 0063d4bd  50                   push eax
// 0063d4be  b801000000           mov eax, 1
// 0063d4c3  64892500000000       mov dword ptr fs:[0], esp
// 0063d4ca  8405c85ab800         test byte ptr [0xb85ac8], al
// 0063d4d0  7532                 jne 0x63d504
// 0063d4d2  0905c85ab800         or dword ptr [0xb85ac8], eax
// 0063d4d8  6a00                 push 0
// 0063d4da  68d8c39c00           push 0x9cc3d8
// 0063d4df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0063d4e7  e8c4cedcff           call 0x40a3b0
// 0063d4ec  50                   push eax
// 0063d4ed  b9d059b800           mov ecx, 0xb859d0
// 0063d4f2  e8096b0200           call 0x664000
// 0063d4f7  68401d9800           push 0x981d40
// 0063d4fc  e828741b00           call 0x7f4929
// 0063d501  83c404               add esp, 4
// 0063d504  8b0c24               mov ecx, dword ptr [esp]
// 0063d507  b8d059b800           mov eax, 0xb859d0
// 0063d50c  64890d00000000       mov dword ptr fs:[0], ecx
// 0063d513  83c40c               add esp, 0xc
// 0063d516  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Team", 0);
    return object;
}
