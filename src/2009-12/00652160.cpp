// from server: 100% by nuck16
// roc 2009-12 00652160  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 00652160  64a100000000         mov eax, dword ptr fs:[0]
// 00652166  6aff                 push -1
// 00652168  687e2d9400           push 0x942d7e
// 0065216d  50                   push eax
// 0065216e  b801000000           mov eax, 1
// 00652173  64892500000000       mov dword ptr fs:[0], esp
// 0065217a  840598ddb800         test byte ptr [0xb8dd98], al
// 00652180  7532                 jne 0x6521b4
// 00652182  090598ddb800         or dword ptr [0xb8dd98], eax
// 00652188  6a00                 push 0
// 0065218a  688cf4b400           push 0xb4f48c
// 0065218f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00652197  e81482dbff           call 0x40a3b0
// 0065219c  50                   push eax
// 0065219d  b9a0dcb800           mov ecx, 0xb8dca0
// 006521a2  e8591e0100           call 0x664000
// 006521a7  68b02f9800           push 0x982fb0
// 006521ac  e878271a00           call 0x7f4929
// 006521b1  83c404               add esp, 4
// 006521b4  8b0c24               mov ecx, dword ptr [esp]
// 006521b7  b8a0dcb800           mov eax, 0xb8dca0
// 006521bc  64890d00000000       mov dword ptr fs:[0], ecx
// 006521c3  83c40c               add esp, 0xc
// 006521c6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b4f48c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b4f48c, 0);
    return object;
}
