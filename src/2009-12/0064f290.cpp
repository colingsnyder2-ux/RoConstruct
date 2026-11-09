// from server: 100% by nuck16
// roc 2009-12 0064f290  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0064f290
//
// 0064f290  64a100000000         mov eax, dword ptr fs:[0]
// 0064f296  6aff                 push -1
// 0064f298  681e209400           push 0x94201e
// 0064f29d  50                   push eax
// 0064f29e  b801000000           mov eax, 1
// 0064f2a3  64892500000000       mov dword ptr fs:[0], esp
// 0064f2aa  84059872b800         test byte ptr [0xb87298], al
// 0064f2b0  7532                 jne 0x64f2e4
// 0064f2b2  09059872b800         or dword ptr [0xb87298], eax
// 0064f2b8  6a00                 push 0
// 0064f2ba  6878789e00           push 0x9e7878
// 0064f2bf  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064f2c7  e8e4b0dbff           call 0x40a3b0
// 0064f2cc  50                   push eax
// 0064f2cd  b9a071b800           mov ecx, 0xb871a0
// 0064f2d2  e8294d0100           call 0x664000
// 0064f2d7  6860369800           push 0x983660
// 0064f2dc  e848561a00           call 0x7f4929
// 0064f2e1  83c404               add esp, 4
// 0064f2e4  8b0c24               mov ecx, dword ptr [esp]
// 0064f2e7  b8a071b800           mov eax, 0xb871a0
// 0064f2ec  64890d00000000       mov dword ptr fs:[0], ecx
// 0064f2f3  83c40c               add esp, 0xc
// 0064f2f6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "BadgeService", 0);
    return object;
}
