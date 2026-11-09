// from server: 100% by nuck16
// roc 2009-12 0064fa70  unit: RBX::Script::W4ScriptExecutionLocation::?$EnumDesc  size: 103 bytes
//
// 0064fa70  64a100000000         mov eax, dword ptr fs:[0]
// 0064fa76  6aff                 push -1
// 0064fa78  685e229400           push 0x94225e
// 0064fa7d  50                   push eax
// 0064fa7e  b801000000           mov eax, 1
// 0064fa83  64892500000000       mov dword ptr fs:[0], esp
// 0064fa8a  84059884b800         test byte ptr [0xb88498], al
// 0064fa90  7532                 jne 0x64fac4
// 0064fa92  09059884b800         or dword ptr [0xb88498], eax
// 0064fa98  6a00                 push 0
// 0064fa9a  6804b9b300           push 0xb3b904
// 0064fa9f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064faa7  e854ffffff           call 0x64fa00
// 0064faac  50                   push eax
// 0064faad  b9a083b800           mov ecx, 0xb883a0
// 0064fab2  e849450100           call 0x664000
// 0064fab7  6840359800           push 0x983540
// 0064fabc  e8684e1a00           call 0x7f4929
// 0064fac1  83c404               add esp, 4
// 0064fac4  8b0c24               mov ecx, dword ptr [esp]
// 0064fac7  b8a083b800           mov eax, 0xb883a0
// 0064facc  64890d00000000       mov dword ptr fs:[0], ecx
// 0064fad3  83c40c               add esp, 0xc
// 0064fad6  c3                   ret 

struct Base;
Base &get_64fa00();
extern char string_00b3b904[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_64fa00(), string_00b3b904, 0);
    return object;
}
