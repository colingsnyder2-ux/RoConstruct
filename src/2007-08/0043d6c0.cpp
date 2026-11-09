// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043d6c0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043d6c0
//
// 0043d6c0  6aff                 push -1
// 0043d6c2  6836ea7300           push 0x73ea36
// 0043d6c7  64a100000000         mov eax, dword ptr fs:[0]
// 0043d6cd  50                   push eax
// 0043d6ce  51                   push ecx
// 0043d6cf  53                   push ebx
// 0043d6d0  56                   push esi
// 0043d6d1  57                   push edi
// 0043d6d2  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043d6d7  33c4                 xor eax, esp
// 0043d6d9  50                   push eax
// 0043d6da  8d442414             lea eax, [esp + 0x14]
// 0043d6de  64a300000000         mov dword ptr fs:[0], eax
// 0043d6e4  8bf1                 mov esi, ecx
// 0043d6e6  89742410             mov dword ptr [esp + 0x10], esi
// 0043d6ea  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043d6ee  8b4704               mov eax, dword ptr [edi + 4]
// 0043d6f1  8d4804               lea ecx, [eax + 4]
// 0043d6f4  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043d6fa  6a00                 push 0
// 0043d6fc  6a00                 push 0
// 0043d6fe  50                   push eax
// 0043d6ff  8bce                 mov ecx, esi
// 0043d701  e83ac92500           call 0x69a040
// 0043d706  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043d70a  50                   push eax
// 0043d70b  8d9e00010000         lea ebx, [esi + 0x100]
// 0043d711  57                   push edi
// 0043d712  8bcb                 mov ecx, ebx
// 0043d714  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043d71c  e8afdeffff           call 0x43b5d0
// 0043d721  b801000000           mov eax, 1
// 0043d726  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0043d72c  c7064ce17800         mov dword ptr [esi], 0x78e14c
// 0043d732  c74620ece07800       mov dword ptr [esi + 0x20], 0x78e0ec
// 0043d739  c703e0e07800         mov dword ptr [ebx], 0x78e0e0
// 0043d73f  89be18010000         mov dword ptr [esi + 0x118], edi
// 0043d745  8b17                 mov edx, dword ptr [edi]
// 0043d747  8844241c             mov byte ptr [esp + 0x1c], al
// 0043d74b  8b4204               mov eax, dword ptr [edx + 4]
// 0043d74e  8bcf                 mov ecx, edi
// 0043d750  ffd0                 call eax
// 0043d752  0fb6c8               movzx ecx, al
// 0043d755  51                   push ecx
// 0043d756  8bce                 mov ecx, esi
// 0043d758  e863b52500           call 0x698cc0
// 0043d75d  8bc6                 mov eax, esi
// 0043d75f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043d763  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d76a  59                   pop ecx
// 0043d76b  5f                   pop edi
// 0043d76c  5e                   pop esi
// 0043d76d  5b                   pop ebx
// 0043d76e  83c410               add esp, 0x10
// 0043d771  c20800               ret 8

// from server: 100% by colin
// roc 2008-06 0043c9b0  unit: HVCXTPPropertyGridItemEnum::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043c9b0
//
// 0043c9b0  6aff                 push -1
// 0043c9b2  6826057c00           push 0x7c0526
// 0043c9b7  64a100000000         mov eax, dword ptr fs:[0]
// 0043c9bd  50                   push eax
// 0043c9be  64892500000000       mov dword ptr fs:[0], esp
// 0043c9c5  51                   push ecx
// 0043c9c6  53                   push ebx
// 0043c9c7  56                   push esi
// 0043c9c8  57                   push edi
// 0043c9c9  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043c9cd  8b4704               mov eax, dword ptr [edi + 4]
// 0043c9d0  8bf1                 mov esi, ecx
// 0043c9d2  8d4804               lea ecx, [eax + 4]
// 0043c9d5  8974240c             mov dword ptr [esp + 0xc], esi
// 0043c9d9  ff1564248000         call dword ptr [0x802464]
// 0043c9df  6a00                 push 0
// 0043c9e1  6a00                 push 0
// 0043c9e3  50                   push eax
// 0043c9e4  8bce                 mov ecx, esi
// 0043c9e6  e8256b2d00           call 0x713510
// 0043c9eb  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043c9ef  50                   push eax
// 0043c9f0  8d9e0c010000         lea ebx, [esi + 0x10c]
// 0043c9f6  57                   push edi
// 0043c9f7  8bcb                 mov ecx, ebx
// 0043c9f9  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043ca01  e86ad6ffff           call 0x43a070
// 0043ca06  b801000000           mov eax, 1
// 0043ca0b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043ca11  c7067c438100         mov dword ptr [esi], 0x81437c
// 0043ca17  c746201c438100       mov dword ptr [esi + 0x20], 0x81431c
// 0043ca1e  c70310438100         mov dword ptr [ebx], 0x814310
// 0043ca24  89be2c010000         mov dword ptr [esi + 0x12c], edi
// 0043ca2a  8b17                 mov edx, dword ptr [edi]
// 0043ca2c  88442418             mov byte ptr [esp + 0x18], al
// 0043ca30  8b4204               mov eax, dword ptr [edx + 4]
// 0043ca33  8bcf                 mov ecx, edi
// 0043ca35  ffd0                 call eax
// 0043ca37  0fb6c8               movzx ecx, al
// 0043ca3a  51                   push ecx
// 0043ca3b  8bce                 mov ecx, esi
// 0043ca3d  e89e562d00           call 0x7120e0
// 0043ca42  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043ca46  5f                   pop edi
// 0043ca47  8bc6                 mov eax, esi
// 0043ca49  5e                   pop esi
// 0043ca4a  5b                   pop ebx
// 0043ca4b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043ca52  83c410               add esp, 0x10
// 0043ca55  c20800               ret 8

struct String {
    const char *c_str() const;
};

extern const char *(__thiscall *string_c_str)(const String *);

inline const char *String::c_str() const {
    return string_c_str(this);
}

struct PropertyData {
    unsigned long reserved;
    String text;
};

struct Property {
    virtual ~Property();
    virtual bool getValue();
    PropertyData *data;
};

inline const char *NameText(const PropertyData *n, const PropertyData *) { return n->text.c_str(); }

struct Primary {
    virtual ~Primary();
    char padding[0x1c];
};

struct Secondary {
    virtual ~Secondary();
};

struct GridItem : Primary, Secondary {
    char padding[0xcc];
    int flag;
    char tail[0x0c];

    GridItem(const char *, int, int);
    virtual ~GridItem();
    void SetValue(int);
};

struct Item {
    virtual ~Item();
    char padding[0x14];

    Item(Property *, int);
};

struct EnumItem : GridItem, Item {
    Property *property;

    EnumItem(Property *, int);
    virtual ~EnumItem();
};

EnumItem::EnumItem(Property *value, int argument)
    : GridItem(NameText(value->data, value->data), 0, 0),
      Item(value, argument)
{
    flag = 1;
    property = value;
    SetValue(value->getValue());
}