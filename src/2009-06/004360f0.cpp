// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0043c020  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043c020
//
// 0043c020  6aff                 push -1
// 0043c022  6826057c00           push 0x7c0526
// 0043c027  64a100000000         mov eax, dword ptr fs:[0]
// 0043c02d  50                   push eax
// 0043c02e  64892500000000       mov dword ptr fs:[0], esp
// 0043c035  51                   push ecx
// 0043c036  53                   push ebx
// 0043c037  56                   push esi
// 0043c038  57                   push edi
// 0043c039  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c03d  8b4704               mov eax, dword ptr [edi + 4]
// 0043c040  8bf1                 mov esi, ecx
// 0043c042  8d4804               lea ecx, [eax + 4]
// 0043c045  8974240c             mov dword ptr [esp + 0xc], esi
// 0043c049  ff1564248000         call dword ptr [0x802464]
// 0043c04f  6a00                 push 0
// 0043c051  6a00                 push 0
// 0043c053  50                   push eax
// 0043c054  8bce                 mov ecx, esi
// 0043c056  e8b5742d00           call 0x713510
// 0043c05b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043c05f  50                   push eax
// 0043c060  8d9e0c010000         lea ebx, [esi + 0x10c]
// 0043c066  57                   push edi
// 0043c067  8bcb                 mov ecx, ebx
// 0043c069  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043c071  e8fadfffff           call 0x43a070
// 0043c076  b801000000           mov eax, 1
// 0043c07b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043c081  c7069c408100         mov dword ptr [esi], 0x81409c
// 0043c087  c746203c408100       mov dword ptr [esi + 0x20], 0x81403c
// 0043c08e  c70330408100         mov dword ptr [ebx], 0x814030
// 0043c094  89be2c010000         mov dword ptr [esi + 0x12c], edi
// 0043c09a  8b17                 mov edx, dword ptr [edi]
// 0043c09c  88442418             mov byte ptr [esp + 0x18], al
// 0043c0a0  8b4204               mov eax, dword ptr [edx + 4]
// 0043c0a3  8bcf                 mov ecx, edi
// 0043c0a5  ffd0                 call eax
// 0043c0a7  0fb6c8               movzx ecx, al
// 0043c0aa  51                   push ecx
// 0043c0ab  8bce                 mov ecx, esi
// 0043c0ad  e82e602d00           call 0x7120e0
// 0043c0b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043c0b6  5f                   pop edi
// 0043c0b7  8bc6                 mov eax, esi
// 0043c0b9  5e                   pop esi
// 0043c0ba  5b                   pop ebx
// 0043c0bb  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c0c2  83c410               add esp, 0x10
// 0043c0c5  c20800               ret 8

struct String
{
    const char* c_str() const;
};

extern const char* (__thiscall *stringData)(const String*);

__forceinline const char* String::c_str() const
{
    return stringData(this);
}

struct Holder
{
    String text;
};

struct Item
{
    virtual void unused();
    virtual bool value();
    Holder* holder;
};

inline const char* NameText(const Holder* n, const Holder*) { return n->text.c_str(); }

struct Base
{
    void* table;
    char pad04[0x1c];
    void* secondaryTable;
    char pad24[0xd8];
    int kind;
    char pad100[0x0c];

    Base(const char*, int, int);
    ~Base();
    void OnValueChanged(int);
};

struct Member
{
    void* table;
    char pad[0x1c];

    Member(Item*, int);
    ~Member();
};

extern void* primaryTable[];
extern void* secondaryTable[];
extern void* memberTable[];

struct S : Base
{
    Member member;
    Item* item;

    S(Item*, int);
};

S::S(Item* source, int argument)
    : Base(NameText(source->holder, source->holder), 0, 0),
      member(source, argument)
{
    kind = 1;
    table = primaryTable;
    secondaryTable = ::secondaryTable;
    member.table = memberTable;
    item = source;
    OnValueChanged(source->value());
}
