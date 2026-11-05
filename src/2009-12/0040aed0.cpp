// from server: 100% by nuck16
// roc 2009-12 0040aed0  unit: RBX::Reflection::Metadata::VClass::?$FactoryProduct  size: 103 bytes
//
// 0040aed0  64a100000000         mov eax, dword ptr fs:[0]
// 0040aed6  6aff                 push -1
// 0040aed8  680e779200           push 0x92770e
// 0040aedd  50                   push eax
// 0040aede  b801000000           mov eax, 1
// 0040aee3  64892500000000       mov dword ptr fs:[0], esp
// 0040aeea  8405389cb700         test byte ptr [0xb79c38], al
// 0040aef0  7532                 jne 0x40af24
// 0040aef2  0905389cb700         or dword ptr [0xb79c38], eax
// 0040aef8  6a00                 push 0
// 0040aefa  68186cb000           push 0xb06c18
// 0040aeff  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040af07  e854ffffff           call 0x40ae60
// 0040af0c  50                   push eax
// 0040af0d  b9409bb700           mov ecx, 0xb79b40
// 0040af12  e8e9902500           call 0x664000
// 0040af17  68b0d89700           push 0x97d8b0
// 0040af1c  e8089a3e00           call 0x7f4929
// 0040af21  83c404               add esp, 4
// 0040af24  8b0c24               mov ecx, dword ptr [esp]
// 0040af27  b8409bb700           mov eax, 0xb79b40
// 0040af2c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040af33  83c40c               add esp, 0xc
// 0040af36  c3                   ret 

struct Base;
Base &get_40ae60();
extern char string_00b06c18[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40ae60(), string_00b06c18, 0);
    return object;
}
