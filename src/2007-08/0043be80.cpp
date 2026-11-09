// from server: 100% by Intel
// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 0043ab10  unit: MVCXTPPropertyGridItem::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043ab10
//
// 0043ab10  6aff                 push -1
// 0043ab12  6826057c00           push 0x7c0526
// 0043ab17  64a100000000         mov eax, dword ptr fs:[0]
// 0043ab1d  50                   push eax
// 0043ab1e  64892500000000       mov dword ptr fs:[0], esp
// 0043ab25  51                   push ecx
// 0043ab26  53                   push ebx
// 0043ab27  56                   push esi
// 0043ab28  57                   push edi
// 0043ab29  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043ab2d  8b4704               mov eax, dword ptr [edi + 4]
// 0043ab30  8bf1                 mov esi, ecx
// 0043ab32  8d4804               lea ecx, [eax + 4]
// 0043ab35  8974240c             mov dword ptr [esp + 0xc], esi
// 0043ab39  ff1564248000         call dword ptr [0x802464]
// 0043ab3f  6a00                 push 0
// 0043ab41  6a00                 push 0
// 0043ab43  50                   push eax
// 0043ab44  8bce                 mov ecx, esi
// 0043ab46  e8c5892d00           call 0x713510
// 0043ab4b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043ab4f  50                   push eax
// 0043ab50  8d9e0c010000         lea ebx, [esi + 0x10c]
// 0043ab56  57                   push edi
// 0043ab57  8bcb                 mov ecx, ebx
// 0043ab59  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043ab61  e80af5ffff           call 0x43a070
// 0043ab66  b801000000           mov eax, 1
// 0043ab6b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043ab71  c706ec3a8100         mov dword ptr [esi], 0x813aec
// 0043ab77  c746208c3a8100       mov dword ptr [esi + 0x20], 0x813a8c
// 0043ab7e  c703803a8100         mov dword ptr [ebx], 0x813a80
// 0043ab84  89be2c010000         mov dword ptr [esi + 0x12c], edi
// 0043ab8a  8b17                 mov edx, dword ptr [edi]
// 0043ab8c  88442418             mov byte ptr [esp + 0x18], al
// 0043ab90  8b4204               mov eax, dword ptr [edx + 4]
// 0043ab93  8bcf                 mov ecx, edi
// 0043ab95  ffd0                 call eax
// 0043ab97  0fb6c8               movzx ecx, al
// 0043ab9a  51                   push ecx
// 0043ab9b  8bce                 mov ecx, esi
// 0043ab9d  e83e752d00           call 0x7120e0
// 0043aba2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043aba6  5f                   pop edi
// 0043aba7  8bc6                 mov eax, esi
// 0043aba9  5e                   pop esi
// 0043abaa  5b                   pop ebx
// 0043abab  64890d00000000       mov dword ptr fs:[0], ecx
// 0043abb2  83c410               add esp, 0x10
// 0043abb5  c20800               ret 8

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
