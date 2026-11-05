// from server: 100% by nuck16
// roc 2009-12 0040b8c0  unit: RBX::Reflection::Metadata::VMember::?$FactoryProduct  size: 103 bytes
//
// 0040b8c0  64a100000000         mov eax, dword ptr fs:[0]
// 0040b8c6  6aff                 push -1
// 0040b8c8  682e789200           push 0x92782e
// 0040b8cd  50                   push eax
// 0040b8ce  b801000000           mov eax, 1
// 0040b8d3  64892500000000       mov dword ptr fs:[0], esp
// 0040b8da  840538a0b700         test byte ptr [0xb7a038], al
// 0040b8e0  7532                 jne 0x40b914
// 0040b8e2  090538a0b700         or dword ptr [0xb7a038], eax
// 0040b8e8  6a00                 push 0
// 0040b8ea  68886cb000           push 0xb06c88
// 0040b8ef  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0040b8f7  e864f5ffff           call 0x40ae60
// 0040b8fc  50                   push eax
// 0040b8fd  b9409fb700           mov ecx, 0xb79f40
// 0040b902  e8f9862500           call 0x664000
// 0040b907  68f0d89700           push 0x97d8f0
// 0040b90c  e818903e00           call 0x7f4929
// 0040b911  83c404               add esp, 4
// 0040b914  8b0c24               mov ecx, dword ptr [esp]
// 0040b917  b8409fb700           mov eax, 0xb79f40
// 0040b91c  64890d00000000       mov dword ptr fs:[0], ecx
// 0040b923  83c40c               add esp, 0xc
// 0040b926  c3                   ret 

struct Base;
Base &get_40ae60();
extern char string_00b06c88[];

struct Object
{
    Object(Base &, const char *, int);
    ~Object();
};

Object &f()
{
    static Object object(get_40ae60(), string_00b06c88, 0);
    return object;
}
