// from server: 100% by nuck16
// roc 2009-12 0040ae60  unit: RBX::Reflection::Metadata::VClass::?$FactoryProduct  size: 103 bytes
//
// 0040ae60  64a100000000         mov eax, dword ptr fs:[0]
// 0040ae66  6aff                 push -1
// 0040ae68  68ee769200           push 0x9276ee
// 0040ae6d  50                   push eax
// 0040ae6e  b801000000           mov eax, 1
// 0040ae73  64892500000000       mov dword ptr fs:[0], esp
// 0040ae7a  8405389bb700         test byte ptr [0xb79b38], al
// 0040ae80  7532                 jne 0x40aeb4
// 0040ae82  0905389bb700         or dword ptr [0xb79b38], eax
// 0040ae88  6a00                 push 0
// 0040ae8a  68006cb000           push 0xb06c00
// 0040ae8f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040ae97  e814f5ffff           call 0x40a3b0
// 0040ae9c  50                   push eax
// 0040ae9d  b9409ab700           mov ecx, 0xb79a40
// 0040aea2  e859912500           call 0x664000
// 0040aea7  68c0d89700           push 0x97d8c0
// 0040aeac  e8789a3e00           call 0x7f4929
// 0040aeb1  83c404               add esp, 4
// 0040aeb4  8b0c24               mov ecx, dword ptr [esp]
// 0040aeb7  b8409ab700           mov eax, 0xb79a40
// 0040aebc  64890d00000000       mov dword ptr fs:[0], ecx
// 0040aec3  83c40c               add esp, 0xc
// 0040aec6  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b06c00[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b06c00, 0);
    return object;
}
