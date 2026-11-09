// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043c9d0  unit: RBX::VBrickColor::?$XItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043c9d0
//
// 0043c9d0  6aff                 push -1
// 0043c9d2  6836ea7300           push 0x73ea36
// 0043c9d7  64a100000000         mov eax, dword ptr fs:[0]
// 0043c9dd  50                   push eax
// 0043c9de  51                   push ecx
// 0043c9df  53                   push ebx
// 0043c9e0  56                   push esi
// 0043c9e1  57                   push edi
// 0043c9e2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043c9e7  33c4                 xor eax, esp
// 0043c9e9  50                   push eax
// 0043c9ea  8d442414             lea eax, [esp + 0x14]
// 0043c9ee  64a300000000         mov dword ptr fs:[0], eax
// 0043c9f4  8bf1                 mov esi, ecx
// 0043c9f6  89742410             mov dword ptr [esp + 0x10], esi
// 0043c9fa  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043c9fe  8b4704               mov eax, dword ptr [edi + 4]
// 0043ca01  8d4804               lea ecx, [eax + 4]
// 0043ca04  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043ca0a  6a00                 push 0
// 0043ca0c  6a00                 push 0
// 0043ca0e  50                   push eax
// 0043ca0f  8bce                 mov ecx, esi
// 0043ca11  e82ad62500           call 0x69a040
// 0043ca16  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043ca1a  50                   push eax
// 0043ca1b  8d9e00010000         lea ebx, [esi + 0x100]
// 0043ca21  57                   push edi
// 0043ca22  8bcb                 mov ecx, ebx
// 0043ca24  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043ca2c  e89febffff           call 0x43b5d0
// 0043ca31  b801000000           mov eax, 1
// 0043ca36  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0043ca3c  c70604dd7800         mov dword ptr [esi], 0x78dd04
// 0043ca42  c74620a4dc7800       mov dword ptr [esi + 0x20], 0x78dca4
// 0043ca49  c7039cdc7800         mov dword ptr [ebx], 0x78dc9c
// 0043ca4f  89be18010000         mov dword ptr [esi + 0x118], edi
// 0043ca55  8b17                 mov edx, dword ptr [edi]
// 0043ca57  8844241c             mov byte ptr [esp + 0x1c], al
// 0043ca5b  8b4204               mov eax, dword ptr [edx + 4]
// 0043ca5e  8bcf                 mov ecx, edi
// 0043ca60  ffd0                 call eax
// 0043ca62  0fb6c8               movzx ecx, al
// 0043ca65  51                   push ecx
// 0043ca66  8bce                 mov ecx, esi
// 0043ca68  e853c22500           call 0x698cc0
// 0043ca6d  8bc6                 mov eax, esi
// 0043ca6f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043ca73  64890d00000000       mov dword ptr fs:[0], ecx
// 0043ca7a  59                   pop ecx
// 0043ca7b  5f                   pop edi
// 0043ca7c  5e                   pop esi
// 0043ca7d  5b                   pop ebx
// 0043ca7e  83c410               add esp, 0x10
// 0043ca81  c20800               ret 8

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 50727

struct String {
    const char* c_str() const;
};

extern const char* (__thiscall* const string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct Name {
    int unused;
    String text;
};

inline const char* NameText(const Name* n, const Name*) { return n->text.c_str(); }

struct Source {
    virtual void reserved();
    virtual unsigned char value();
    Name* name;
};

struct First {
    virtual ~First();
    char padding[0x1c];
};

struct Second {
    virtual ~Second();
    char padding[0xcc];
    int flag;
    char tail[0xc];
};

struct Base : First, Second {
    Base(const char*, int, int);
    ~Base();
    void OnValueChanged(int);
};

struct Link {
    virtual ~Link();
    char padding[0x14];
    Link(Source*, int);
};

struct Item : Base, Link {
    Source* source;
    Item(Source*, int);
    virtual ~Item();
};

Item::Item(Source* input, int option)
    : Base(NameText(input->name, input->name), 0, 0),
      Link(input, option),
      source(input)
{
    flag = 1;
    OnValueChanged(input->value());
}