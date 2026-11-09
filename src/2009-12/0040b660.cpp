// from server: 100% by nuck16
// roc 2009-12 0040b660  unit: RBX::Reflection::Metadata::VEvents::?$FactoryProduct  size: 103 bytes
//
// 0040b660  64a100000000         mov eax, dword ptr fs:[0]
// 0040b666  6aff                 push -1
// 0040b668  68de779200           push 0x9277de
// 0040b66d  50                   push eax
// 0040b66e  b801000000           mov eax, 1
// 0040b673  64892500000000       mov dword ptr fs:[0], esp
// 0040b67a  8405389fb700         test byte ptr [0xb79f38], al
// 0040b680  7532                 jne 0x40b6b4
// 0040b682  0905389fb700         or dword ptr [0xb79f38], eax
// 0040b688  6a00                 push 0
// 0040b68a  686c6cb000           push 0xb06c6c
// 0040b68f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040b697  e814edffff           call 0x40a3b0
// 0040b69c  50                   push eax
// 0040b69d  b9409eb700           mov ecx, 0xb79e40
// 0040b6a2  e859892500           call 0x664000
// 0040b6a7  6800d99700           push 0x97d900
// 0040b6ac  e878923e00           call 0x7f4929
// 0040b6b1  83c404               add esp, 4
// 0040b6b4  8b0c24               mov ecx, dword ptr [esp]
// 0040b6b7  b8409eb700           mov eax, 0xb79e40
// 0040b6bc  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b6c3  83c40c               add esp, 0xc
// 0040b6c6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b06c6c[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b06c6c, 0);
    return object;
}
