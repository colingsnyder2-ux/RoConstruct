// from server: 100% by Intel
// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by colin
// roc 2008-06 0043c440  unit: G3D::VVector3::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043c440
//
// 0043c440  6aff                 push -1
// 0043c442  6836067c00           push 0x7c0636
// 0043c447  64a100000000         mov eax, dword ptr fs:[0]
// 0043c44d  50                   push eax
// 0043c44e  64892500000000       mov dword ptr fs:[0], esp
// 0043c455  51                   push ecx
// 0043c456  53                   push ebx
// 0043c457  56                   push esi
// 0043c458  57                   push edi
// 0043c459  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c45d  8b4704               mov eax, dword ptr [edi + 4]
// 0043c460  8bf1                 mov esi, ecx
// 0043c462  8d4804               lea ecx, [eax + 4]
// 0043c465  8974240c             mov dword ptr [esp + 0xc], esi
// 0043c469  ff1564248000         call dword ptr [0x802464]
// 0043c46f  6a00                 push 0
// 0043c471  6a00                 push 0
// 0043c473  50                   push eax
// 0043c474  8bce                 mov ecx, esi
// 0043c476  e8b5b92d00           call 0x717e30
// 0043c47b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043c47f  50                   push eax
// 0043c480  8d9e14010000         lea ebx, [esi + 0x114]
// 0043c486  57                   push edi
// 0043c487  8bcb                 mov ecx, ebx
// 0043c489  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043c491  e8dadbffff           call 0x43a070
// 0043c496  b801000000           mov eax, 1
// 0043c49b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043c4a1  c70604428100         mov dword ptr [esi], 0x814204
// 0043c4a7  c74620a4418100       mov dword ptr [esi + 0x20], 0x8141a4
// 0043c4ae  c70398418100         mov dword ptr [ebx], 0x814198
// 0043c4b4  89be34010000         mov dword ptr [esi + 0x134], edi
// 0043c4ba  8b17                 mov edx, dword ptr [edi]
// 0043c4bc  88442418             mov byte ptr [esp + 0x18], al
// 0043c4c0  8b4204               mov eax, dword ptr [edx + 4]
// 0043c4c3  8bcf                 mov ecx, edi
// 0043c4c5  ffd0                 call eax
// 0043c4c7  0fb6c8               movzx ecx, al
// 0043c4ca  51                   push ecx
// 0043c4cb  8bce                 mov ecx, esi
// 0043c4cd  e80e5c2d00           call 0x7120e0
// 0043c4d2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043c4d6  5f                   pop edi
// 0043c4d7  8bc6                 mov eax, esi
// 0043c4d9  5e                   pop esi
// 0043c4da  5b                   pop ebx
// 0043c4db  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c4e2  83c410               add esp, 0x10
// 0043c4e5  c20800               ret 8

struct Text {
    const char* c_str() const;
};

extern const char* (__thiscall* text_c_str)(const Text*);

inline const char* Text::c_str() const
{
    return text_c_str(this);
}

struct TextOwner {
    int padding;
    Text text;
};

struct Source {
    virtual ~Source();
    virtual bool value();
    TextOwner* text;
};

inline const char *NameText(const TextOwner *n, const TextOwner *) { return n->text.c_str(); }

struct Primary {
    virtual ~Primary();
    char padding[0x1c];
};

struct Secondary {
    virtual ~Secondary();
    char padding[0xcc];
    int state;
    char tail[0x14];
};

struct ItemBase : Primary, Secondary {
    ItemBase(const char*, int, int);
    virtual ~ItemBase();
    void OnValueChanged(int);
};

struct Attachment {
    Attachment(Source*, int);
    virtual ~Attachment();
    char padding[0x14];
};

struct Item : ItemBase, Attachment {
    Item(Source*, int);
    virtual ~Item();
    Source* source;
};

Item::Item(Source* object, int argument)
    : ItemBase(NameText(object->text, object->text), 0, 0),
      Attachment(object, argument)
{
    state = 1;
    source = object;
    OnValueChanged(object->value());
}