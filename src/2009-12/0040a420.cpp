// from server: 100% by nuck16
// roc 2009-12 0040a420  unit: RBX::Reflection::ClassDescriptor  size: 103 bytes
//
// 0040a420  64a100000000         mov eax, dword ptr fs:[0]
// 0040a426  6aff                 push -1
// 0040a428  68fe759200           push 0x9275fe
// 0040a42d  50                   push eax
// 0040a42e  b801000000           mov eax, 1
// 0040a433  64892500000000       mov dword ptr fs:[0], esp
// 0040a43a  84052099b700         test byte ptr [0xb79920], al
// 0040a440  7532                 jne 0x40a474
// 0040a442  09052099b700         or dword ptr [0xb79920], eax
// 0040a448  6a00                 push 0
// 0040a44a  6860fd9900           push 0x99fd60
// 0040a44f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040a457  e854ffffff           call 0x40a3b0
// 0040a45c  50                   push eax
// 0040a45d  b92898b700           mov ecx, 0xb79828
// 0040a462  e8999b2500           call 0x664000
// 0040a467  68d0d89700           push 0x97d8d0
// 0040a46c  e8b8a43e00           call 0x7f4929
// 0040a471  83c404               add esp, 4
// 0040a474  8b0c24               mov ecx, dword ptr [esp]
// 0040a477  b82898b700           mov eax, 0xb79828
// 0040a47c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040a483  83c40c               add esp, 0xc
// 0040a486  c3                   ret 

struct Base;
Base &get_40a3b0();

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40a3b0(), "Authoring", 0);
    return object;
}
