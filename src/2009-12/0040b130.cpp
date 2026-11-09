// from server: 100% by nuck16
// roc 2009-12 0040b130  unit: RBX::Reflection::Metadata::VProperties::?$FactoryProduct  size: 103 bytes
//
// 0040b130  64a100000000         mov eax, dword ptr fs:[0]
// 0040b136  6aff                 push -1
// 0040b138  683e779200           push 0x92773e
// 0040b13d  50                   push eax
// 0040b13e  b801000000           mov eax, 1
// 0040b143  64892500000000       mov dword ptr fs:[0], esp
// 0040b14a  8405389db700         test byte ptr [0xb79d38], al
// 0040b150  7532                 jne 0x40b184
// 0040b152  0905389db700         or dword ptr [0xb79d38], eax
// 0040b158  6a00                 push 0
// 0040b15a  68306cb000           push 0xb06c30
// 0040b15f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040b167  e844f2ffff           call 0x40a3b0
// 0040b16c  50                   push eax
// 0040b16d  b9409cb700           mov ecx, 0xb79c40
// 0040b172  e8898e2500           call 0x664000
// 0040b177  6820d99700           push 0x97d920
// 0040b17c  e8a8973e00           call 0x7f4929
// 0040b181  83c404               add esp, 4
// 0040b184  8b0c24               mov ecx, dword ptr [esp]
// 0040b187  b8409cb700           mov eax, 0xb79c40
// 0040b18c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b193  83c40c               add esp, 0xc
// 0040b196  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b06c30[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b06c30, 0);
    return object;
}
