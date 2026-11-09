// from server: 100% by nuck16
// roc 2009-12 0040b3f0  unit: RBX::Reflection::Metadata::VFunctions::?$FactoryProduct  size: 103 bytes
//
// 0040b3f0  64a100000000         mov eax, dword ptr fs:[0]
// 0040b3f6  6aff                 push -1
// 0040b3f8  688e779200           push 0x92778e
// 0040b3fd  50                   push eax
// 0040b3fe  b801000000           mov eax, 1
// 0040b403  64892500000000       mov dword ptr fs:[0], esp
// 0040b40a  8405389eb700         test byte ptr [0xb79e38], al
// 0040b410  7532                 jne 0x40b444
// 0040b412  0905389eb700         or dword ptr [0xb79e38], eax
// 0040b418  6a00                 push 0
// 0040b41a  68506cb000           push 0xb06c50
// 0040b41f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040b427  e884efffff           call 0x40a3b0
// 0040b42c  50                   push eax
// 0040b42d  b9409db700           mov ecx, 0xb79d40
// 0040b432  e8c98b2500           call 0x664000
// 0040b437  6810d99700           push 0x97d910
// 0040b43c  e8e8943e00           call 0x7f4929
// 0040b441  83c404               add esp, 4
// 0040b444  8b0c24               mov ecx, dword ptr [esp]
// 0040b447  b8409db700           mov eax, 0xb79d40
// 0040b44c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b453  83c40c               add esp, 0xc
// 0040b456  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b06c50[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b06c50, 0);
    return object;
}
