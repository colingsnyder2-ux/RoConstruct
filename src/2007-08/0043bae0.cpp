// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043bae0  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043bae0
//
// 0043bae0  6aff                 push -1
// 0043bae2  6836ea7300           push 0x73ea36
// 0043bae7  64a100000000         mov eax, dword ptr fs:[0]
// 0043baed  50                   push eax
// 0043baee  51                   push ecx
// 0043baef  53                   push ebx
// 0043baf0  56                   push esi
// 0043baf1  57                   push edi
// 0043baf2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043baf7  33c4                 xor eax, esp
// 0043baf9  50                   push eax
// 0043bafa  8d442414             lea eax, [esp + 0x14]
// 0043bafe  64a300000000         mov dword ptr fs:[0], eax
// 0043bb04  8bf1                 mov esi, ecx
// 0043bb06  89742410             mov dword ptr [esp + 0x10], esi
// 0043bb0a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043bb0e  8b4704               mov eax, dword ptr [edi + 4]
// 0043bb11  8d4804               lea ecx, [eax + 4]
// 0043bb14  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043bb1a  6a00                 push 0
// 0043bb1c  6a00                 push 0
// 0043bb1e  50                   push eax
// 0043bb1f  8bce                 mov ecx, esi
// 0043bb21  e81ae52500           call 0x69a040
// 0043bb26  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043bb2a  50                   push eax
// 0043bb2b  8d9e00010000         lea ebx, [esi + 0x100]
// 0043bb31  57                   push edi
// 0043bb32  8bcb                 mov ecx, ebx
// 0043bb34  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043bb3c  e88ffaffff           call 0x43b5d0
// 0043bb41  b801000000           mov eax, 1
// 0043bb46  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0043bb4c  c70654d77800         mov dword ptr [esi], 0x78d754
// 0043bb52  c74620f4d67800       mov dword ptr [esi + 0x20], 0x78d6f4
// 0043bb59  c703ecd67800         mov dword ptr [ebx], 0x78d6ec
// 0043bb5f  89be18010000         mov dword ptr [esi + 0x118], edi
// 0043bb65  8b17                 mov edx, dword ptr [edi]
// 0043bb67  8844241c             mov byte ptr [esp + 0x1c], al
// 0043bb6b  8b4204               mov eax, dword ptr [edx + 4]
// 0043bb6e  8bcf                 mov ecx, edi
// 0043bb70  ffd0                 call eax
// 0043bb72  0fb6c8               movzx ecx, al
// 0043bb75  51                   push ecx
// 0043bb76  8bce                 mov ecx, esi
// 0043bb78  e843d12500           call 0x698cc0
// 0043bb7d  8bc6                 mov eax, esi
// 0043bb7f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043bb83  64890d00000000       mov dword ptr fs:[0], ecx
// 0043bb8a  59                   pop ecx
// 0043bb8b  5f                   pop edi
// 0043bb8c  5e                   pop esi
// 0043bb8d  5b                   pop ebx
// 0043bb8e  83c410               add esp, 0x10
// 0043bb91  c20800               ret 8

// from server: 100% by colin
// roc 2008-06 0043a650  unit: _NVCXTPPropertyGridItemBool::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043a650
//
// 0043a650  6aff                 push -1
// 0043a652  6826057c00           push 0x7c0526
// 0043a657  64a100000000         mov eax, dword ptr fs:[0]
// 0043a65d  50                   push eax
// 0043a65e  64892500000000       mov dword ptr fs:[0], esp
// 0043a665  51                   push ecx
// 0043a666  53                   push ebx
// 0043a667  56                   push esi
// 0043a668  57                   push edi
// 0043a669  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043a66d  8b4704               mov eax, dword ptr [edi + 4]
// 0043a670  8bf1                 mov esi, ecx
// 0043a672  8d4804               lea ecx, [eax + 4]
// 0043a675  8974240c             mov dword ptr [esp + 0xc], esi
// 0043a679  ff1564248000         call dword ptr [0x802464]
// 0043a67f  6a00                 push 0
// 0043a681  6a00                 push 0
// 0043a683  50                   push eax
// 0043a684  8bce                 mov ecx, esi
// 0043a686  e8858e2d00           call 0x713510
// 0043a68b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043a68f  50                   push eax
// 0043a690  8d9e0c010000         lea ebx, [esi + 0x10c]
// 0043a696  57                   push edi
// 0043a697  8bcb                 mov ecx, ebx
// 0043a699  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043a6a1  e8caf9ffff           call 0x43a070
// 0043a6a6  b801000000           mov eax, 1
// 0043a6ab  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043a6b1  c70684398100         mov dword ptr [esi], 0x813984
// 0043a6b7  c7462024398100       mov dword ptr [esi + 0x20], 0x813924
// 0043a6be  c7031c398100         mov dword ptr [ebx], 0x81391c
// 0043a6c4  89be2c010000         mov dword ptr [esi + 0x12c], edi
// 0043a6ca  8b17                 mov edx, dword ptr [edi]
// 0043a6cc  88442418             mov byte ptr [esp + 0x18], al
// 0043a6d0  8b4204               mov eax, dword ptr [edx + 4]
// 0043a6d3  8bcf                 mov ecx, edi
// 0043a6d5  ffd0                 call eax
// 0043a6d7  0fb6c8               movzx ecx, al
// 0043a6da  51                   push ecx
// 0043a6db  8bce                 mov ecx, esi
// 0043a6dd  e8fe792d00           call 0x7120e0
// 0043a6e2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043a6e6  5f                   pop edi
// 0043a6e7  8bc6                 mov eax, esi
// 0043a6e9  5e                   pop esi
// 0043a6ea  5b                   pop ebx
// 0043a6eb  64890d00000000       mov dword ptr fs:[0], ecx
// 0043a6f2  83c410               add esp, 0x10
// 0043a6f5  c20800               ret 8

struct String {
    const char* c_str() const;
};

extern const char* (__thiscall* string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct Name {
    char pad[4];
    String text;
};

struct Item {
    virtual ~Item();
    virtual bool value();
    Name* name;
};

struct Primary {
    virtual ~Primary();
    char pad[0x1c];
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char pad0[0xcc];
    int flag;
    char pad1[0xc];

    Base(const char*, int, int);
    virtual ~Base();
    void SetValue(int);
};

struct Helper {
    virtual ~Helper();
    char pad[0x14];

    Helper(Item*, int);
};

struct S : Base, Helper {
    Item* item;

    S(Item*, int);
    virtual ~S();
};

static Name* nameOf(Item* p)
{
    return p->name;
}

S::S(Item* p, int n)
    : Base(nameOf(p)->text.c_str(), 0, 0),
      Helper(p, n)
{
    flag = 1;
    item = p;
    SetValue(p->value());
}
