// from server: 100% by nuck16
// roc 2009-12 0040aac0  unit: RBX::Reflection::Metadata::VClasses::?$FactoryProduct  size: 103 bytes
//
// 0040aac0  64a100000000         mov eax, dword ptr fs:[0]
// 0040aac6  6aff                 push -1
// 0040aac8  687e769200           push 0x92767e
// 0040aacd  50                   push eax
// 0040aace  b801000000           mov eax, 1
// 0040aad3  64892500000000       mov dword ptr fs:[0], esp
// 0040aada  8405289ab700         test byte ptr [0xb79a28], al
// 0040aae0  7532                 jne 0x40ab14
// 0040aae2  0905289ab700         or dword ptr [0xb79a28], eax
// 0040aae8  6a00                 push 0
// 0040aaea  68e46bb000           push 0xb06be4
// 0040aaef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040aaf7  e8b4f8ffff           call 0x40a3b0
// 0040aafc  50                   push eax
// 0040aafd  b93099b700           mov ecx, 0xb79930
// 0040ab02  e8f9942500           call 0x664000
// 0040ab07  6830d99700           push 0x97d930
// 0040ab0c  e8189e3e00           call 0x7f4929
// 0040ab11  83c404               add esp, 4
// 0040ab14  8b0c24               mov ecx, dword ptr [esp]
// 0040ab17  b83099b700           mov eax, 0xb79930
// 0040ab1c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040ab23  83c40c               add esp, 0xc
// 0040ab26  c3                   ret 

struct Base;
Base &get_40a3b0();
extern char string_00b06be4[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), string_00b06be4, 0);
    return object;
}
