// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043d800  unit: RBX::VSoundId::?$XItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043d800
//
// 0043d800  6aff                 push -1
// 0043d802  6836ea7300           push 0x73ea36
// 0043d807  64a100000000         mov eax, dword ptr fs:[0]
// 0043d80d  50                   push eax
// 0043d80e  51                   push ecx
// 0043d80f  53                   push ebx
// 0043d810  56                   push esi
// 0043d811  57                   push edi
// 0043d812  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043d817  33c4                 xor eax, esp
// 0043d819  50                   push eax
// 0043d81a  8d442414             lea eax, [esp + 0x14]
// 0043d81e  64a300000000         mov dword ptr fs:[0], eax
// 0043d824  8bf1                 mov esi, ecx
// 0043d826  89742410             mov dword ptr [esp + 0x10], esi
// 0043d82a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043d82e  8b4704               mov eax, dword ptr [edi + 4]
// 0043d831  8d4804               lea ecx, [eax + 4]
// 0043d834  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043d83a  6a00                 push 0
// 0043d83c  6a00                 push 0
// 0043d83e  50                   push eax
// 0043d83f  8bce                 mov ecx, esi
// 0043d841  e8fac72500           call 0x69a040
// 0043d846  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043d84a  50                   push eax
// 0043d84b  8d9e00010000         lea ebx, [esi + 0x100]
// 0043d851  57                   push edi
// 0043d852  8bcb                 mov ecx, ebx
// 0043d854  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043d85c  e86fddffff           call 0x43b5d0
// 0043d861  b801000000           mov eax, 1
// 0043d866  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0043d86c  c706b4e27800         mov dword ptr [esi], 0x78e2b4
// 0043d872  c7462054e27800       mov dword ptr [esi + 0x20], 0x78e254
// 0043d879  c70348e27800         mov dword ptr [ebx], 0x78e248
// 0043d87f  89be18010000         mov dword ptr [esi + 0x118], edi
// 0043d885  8b17                 mov edx, dword ptr [edi]
// 0043d887  8844241c             mov byte ptr [esp + 0x1c], al
// 0043d88b  8b4204               mov eax, dword ptr [edx + 4]
// 0043d88e  8bcf                 mov ecx, edi
// 0043d890  ffd0                 call eax
// 0043d892  0fb6c8               movzx ecx, al
// 0043d895  51                   push ecx
// 0043d896  8bce                 mov ecx, esi
// 0043d898  e823b42500           call 0x698cc0
// 0043d89d  8bc6                 mov eax, esi
// 0043d89f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043d8a3  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d8aa  59                   pop ecx
// 0043d8ab  5f                   pop edi
// 0043d8ac  5e                   pop esi
// 0043d8ad  5b                   pop ebx
// 0043d8ae  83c410               add esp, 0x10
// 0043d8b1  c20800               ret 8

// from server: 100% by colin
// roc 2008-06 0043cfa0  unit: RBX::Soundscape::VSoundId::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043cfa0
//
// 0043cfa0  6aff                 push -1
// 0043cfa2  6826057c00           push 0x7c0526
// 0043cfa7  64a100000000         mov eax, dword ptr fs:[0]
// 0043cfad  50                   push eax
// 0043cfae  64892500000000       mov dword ptr fs:[0], esp
// 0043cfb5  51                   push ecx
// 0043cfb6  53                   push ebx
// 0043cfb7  56                   push esi
// 0043cfb8  57                   push edi
// 0043cfb9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043cfbd  8b4704               mov eax, dword ptr [edi + 4]
// 0043cfc0  8bf1                 mov esi, ecx
// 0043cfc2  8d4804               lea ecx, [eax + 4]
// 0043cfc5  8974240c             mov dword ptr [esp + 0xc], esi
// 0043cfc9  ff1564248000         call dword ptr [0x802464]
// 0043cfcf  6a00                 push 0
// 0043cfd1  6a00                 push 0
// 0043cfd3  50                   push eax
// 0043cfd4  8bce                 mov ecx, esi
// 0043cfd6  e835652d00           call 0x713510
// 0043cfdb  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043cfdf  50                   push eax
// 0043cfe0  8d9e0c010000         lea ebx, [esi + 0x10c]
// 0043cfe6  57                   push edi
// 0043cfe7  8bcb                 mov ecx, ebx
// 0043cfe9  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043cff1  e87ad0ffff           call 0x43a070
// 0043cff6  b801000000           mov eax, 1
// 0043cffb  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043d001  c706e4448100         mov dword ptr [esi], 0x8144e4
// 0043d007  c7462084448100       mov dword ptr [esi + 0x20], 0x814484
// 0043d00e  c70378448100         mov dword ptr [ebx], 0x814478
// 0043d014  89be2c010000         mov dword ptr [esi + 0x12c], edi
// 0043d01a  8b17                 mov edx, dword ptr [edi]
// 0043d01c  88442418             mov byte ptr [esp + 0x18], al
// 0043d020  8b4204               mov eax, dword ptr [edx + 4]
// 0043d023  8bcf                 mov ecx, edi
// 0043d025  ffd0                 call eax
// 0043d027  0fb6c8               movzx ecx, al
// 0043d02a  51                   push ecx
// 0043d02b  8bce                 mov ecx, esi
// 0043d02d  e8ae502d00           call 0x7120e0
// 0043d032  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043d036  5f                   pop edi
// 0043d037  8bc6                 mov eax, esi
// 0043d039  5e                   pop esi
// 0043d03a  5b                   pop ebx
// 0043d03b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d042  83c410               add esp, 0x10
// 0043d045  c20800               ret 8

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
    char pad1[0x0c];

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