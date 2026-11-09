// from server: 100% by nuck16
// roc 2009-12 00447c60  unit: RBX::CRenderSettings::W4MaterialQuality::?$EnumDesc  size: 103 bytes
//
// 00447c60  64a100000000         mov eax, dword ptr fs:[0]
// 00447c66  6aff                 push -1
// 00447c68  682eab9200           push 0x92ab2e
// 00447c6d  50                   push eax
// 00447c6e  b801000000           mov eax, 1
// 00447c73  64892500000000       mov dword ptr fs:[0], esp
// 00447c7a  840588a6b700         test byte ptr [0xb7a688], al
// 00447c80  7532                 jne 0x447cb4
// 00447c82  090588a6b700         or dword ptr [0xb7a688], eax
// 00447c88  6a00                 push 0
// 00447c8a  6890a09a00           push 0x9aa090
// 00447c8f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00447c97  e81427fcff           call 0x40a3b0
// 00447c9c  50                   push eax
// 00447c9d  b990a5b700           mov ecx, 0xb7a590
// 00447ca2  e859c32100           call 0x664000
// 00447ca7  6890e59700           push 0x97e590
// 00447cac  e878cc3a00           call 0x7f4929
// 00447cb1  83c404               add esp, 4
// 00447cb4  8b0c24               mov ecx, dword ptr [esp]
// 00447cb7  b890a5b700           mov eax, 0xb7a590
// 00447cbc  64890d00000000       mov dword ptr fs:[0], ecx
// 00447cc3  83c40c               add esp, 0xc
// 00447cc6  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "RenderSettings", 0);
    return object;
}
