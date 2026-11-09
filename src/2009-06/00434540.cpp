// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0043a0f0  unit: CSelectionPropGrid  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043a0f0
//
// 0043a0f0  6aff                 push -1
// 0043a0f2  68e6047c00           push 0x7c04e6
// 0043a0f7  64a100000000         mov eax, dword ptr fs:[0]
// 0043a0fd  50                   push eax
// 0043a0fe  64892500000000       mov dword ptr fs:[0], esp
// 0043a105  51                   push ecx
// 0043a106  53                   push ebx
// 0043a107  56                   push esi
// 0043a108  57                   push edi
// 0043a109  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043a10d  8b4704               mov eax, dword ptr [edi + 4]
// 0043a110  8bf1                 mov esi, ecx
// 0043a112  8d4804               lea ecx, [eax + 4]
// 0043a115  8974240c             mov dword ptr [esp + 0xc], esi
// 0043a119  ff1564248000         call dword ptr [0x802464]
// 0043a11f  6a00                 push 0
// 0043a121  6a00                 push 0
// 0043a123  50                   push eax
// 0043a124  8bce                 mov ecx, esi
// 0043a126  e8f5d92d00           call 0x717b20
// 0043a12b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043a12f  50                   push eax
// 0043a130  8d9e20010000         lea ebx, [esi + 0x120]
// 0043a136  57                   push edi
// 0043a137  8bcb                 mov ecx, ebx
// 0043a139  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043a141  e82affffff           call 0x43a070
// 0043a146  b801000000           mov eax, 1
// 0043a14b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043a151  c70614388100         mov dword ptr [esi], 0x813814
// 0043a157  c74620b4378100       mov dword ptr [esi + 0x20], 0x8137b4
// 0043a15e  c703ac378100         mov dword ptr [ebx], 0x8137ac
// 0043a164  89be40010000         mov dword ptr [esi + 0x140], edi
// 0043a16a  8b17                 mov edx, dword ptr [edi]
// 0043a16c  88442418             mov byte ptr [esp + 0x18], al
// 0043a170  8b4204               mov eax, dword ptr [edx + 4]
// 0043a173  8bcf                 mov ecx, edi
// 0043a175  ffd0                 call eax
// 0043a177  0fb6c8               movzx ecx, al
// 0043a17a  51                   push ecx
// 0043a17b  8bce                 mov ecx, esi
// 0043a17d  e85e7f2d00           call 0x7120e0
// 0043a182  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043a186  5f                   pop edi
// 0043a187  8bc6                 mov eax, esi
// 0043a189  5e                   pop esi
// 0043a18a  5b                   pop ebx
// 0043a18b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043a192  83c410               add esp, 0x10
// 0043a195  c20800               ret 8

struct String {
    const char* c_str() const;
};

extern const char* (__thiscall* string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct Name {
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
    char pad0[0xd8];
    int flag;
    char pad1[0x20];

    Base(const char*, int, int);
    virtual ~Base();
    void SetValue(int);
};

struct Helper {
    virtual ~Helper();
    char pad[0x1c];

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
