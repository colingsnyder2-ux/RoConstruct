// from server: 100% by nuck16
// roc 2009-12 0062f2d0  unit: RBX::DataModelArbiter::W4ConcurrencyModel::?$EnumDesc  size: 103 bytes
//
// 0062f2d0  64a100000000         mov eax, dword ptr fs:[0]
// 0062f2d6  6aff                 push -1
// 0062f2d8  68eefc9300           push 0x93fcee
// 0062f2dd  50                   push eax
// 0062f2de  b801000000           mov eax, 1
// 0062f2e3  64892500000000       mov dword ptr fs:[0], esp
// 0062f2ea  84051843b800         test byte ptr [0xb84318], al
// 0062f2f0  7532                 jne 0x62f324
// 0062f2f2  09051843b800         or dword ptr [0xb84318], eax
// 0062f2f8  6a00                 push 0
// 0062f2fa  68b8ac9c00           push 0x9cacb8
// 0062f2ff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0062f307  e8a4b0ddff           call 0x40a3b0
// 0062f30c  50                   push eax
// 0062f30d  b92042b800           mov ecx, 0xb84220
// 0062f312  e8e94c0300           call 0x664000
// 0062f317  6840169800           push 0x981640
// 0062f31c  e808561c00           call 0x7f4929
// 0062f321  83c404               add esp, 4
// 0062f324  8b0c24               mov ecx, dword ptr [esp]
// 0062f327  b82042b800           mov eax, 0xb84220
// 0062f32c  64890d00000000       mov dword ptr fs:[0], ecx
// 0062f333  83c40c               add esp, 0xc
// 0062f336  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "DebugSettings", 0);
    return object;
}
