// from server: 100% by nuck16
// roc 2009-12 00442c60  unit: RBX::Reflection::H::?$TypedPropertyDescriptor  size: 103 bytes
//
// 00442c60  64a100000000         mov eax, dword ptr fs:[0]
// 00442c66  6aff                 push -1
// 00442c68  68bea99200           push 0x92a9be
// 00442c6d  50                   push eax
// 00442c6e  b801000000           mov eax, 1
// 00442c73  64892500000000       mov dword ptr fs:[0], esp
// 00442c7a  840590a4b700         test byte ptr [0xb7a490], al
// 00442c80  7532                 jne 0x442cb4
// 00442c82  090590a4b700         or dword ptr [0xb7a490], eax
// 00442c88  6a00                 push 0
// 00442c8a  68d06bb000           push 0xb06bd0
// 00442c8f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00442c97  e81477fcff           call 0x40a3b0
// 00442c9c  50                   push eax
// 00442c9d  b998a3b700           mov ecx, 0xb7a398
// 00442ca2  e859132200           call 0x664000
// 00442ca7  68a0e19700           push 0x97e1a0
// 00442cac  e8781c3b00           call 0x7f4929
// 00442cb1  83c404               add esp, 4
// 00442cb4  8b0c24               mov ecx, dword ptr [esp]
// 00442cb7  b898a3b700           mov eax, 0xb7a398
// 00442cbc  64890d00000000       mov dword ptr fs:[0], ecx
// 00442cc3  83c40c               add esp, 0xc
// 00442cc6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b06bd0[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b06bd0, 0);
    return object;
}
