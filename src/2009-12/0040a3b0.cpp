// from server: 100% by nuck16
// roc 2009-12 0040a3b0  unit: RBX::Reflection::ClassDescriptor  size: 103 bytes
//
// 0040a3b0  64a100000000         mov eax, dword ptr fs:[0]
// 0040a3b6  6aff                 push -1
// 0040a3b8  68de759200           push 0x9275de
// 0040a3bd  50                   push eax
// 0040a3be  b801000000           mov eax, 1
// 0040a3c3  64892500000000       mov dword ptr fs:[0], esp
// 0040a3ca  84052098b700         test byte ptr [0xb79820], al
// 0040a3d0  7532                 jne 0x40a404
// 0040a3d2  09052098b700         or dword ptr [0xb79820], eax
// 0040a3d8  6a00                 push 0
// 0040a3da  68a8bc9c00           push 0x9cbca8
// 0040a3df  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040a3e7  e864ffffff           call 0x40a350
// 0040a3ec  50                   push eax
// 0040a3ed  b92897b700           mov ecx, 0xb79728
// 0040a3f2  e8099c2500           call 0x664000
// 0040a3f7  68e0d89700           push 0x97d8e0
// 0040a3fc  e828a53e00           call 0x7f4929
// 0040a401  83c404               add esp, 4
// 0040a404  8b0c24               mov ecx, dword ptr [esp]
// 0040a407  b82897b700           mov eax, 0xb79728
// 0040a40c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a413  83c40c               add esp, 0xc
// 0040a416  c3                   ret 

struct Base;
Base &get_40a350();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a350(), "Instance", 0);
    return object;
}
