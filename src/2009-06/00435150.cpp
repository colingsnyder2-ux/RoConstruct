// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 0043af00  unit: HVCXTPPropertyGridItem::?$XItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043af00
//
// 0043af00  6aff                 push -1
// 0043af02  6846057c00           push 0x7c0546
// 0043af07  64a100000000         mov eax, dword ptr fs:[0]
// 0043af0d  50                   push eax
// 0043af0e  64892500000000       mov dword ptr fs:[0], esp
// 0043af15  51                   push ecx
// 0043af16  53                   push ebx
// 0043af17  56                   push esi
// 0043af18  57                   push edi
// 0043af19  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043af1d  8b4704               mov eax, dword ptr [edi + 4]
// 0043af20  8bf1                 mov esi, ecx
// 0043af22  8d4804               lea ecx, [eax + 4]
// 0043af25  8974240c             mov dword ptr [esp + 0xc], esi
// 0043af29  ff1564248000         call dword ptr [0x802464]
// 0043af2f  6a00                 push 0
// 0043af31  6a00                 push 0
// 0043af33  50                   push eax
// 0043af34  8bce                 mov ecx, esi
// 0043af36  e8458c2d00           call 0x713b80
// 0043af3b  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043af3f  50                   push eax
// 0043af40  8d9e18010000         lea ebx, [esi + 0x118]
// 0043af46  57                   push edi
// 0043af47  8bcb                 mov ecx, ebx
// 0043af49  c744242000000000     mov dword ptr [esp + 0x20], 0
// 0043af51  e81af1ffff           call 0x43a070
// 0043af56  b801000000           mov eax, 1
// 0043af5b  8986fc000000         mov dword ptr [esi + 0xfc], eax
// 0043af61  c706543c8100         mov dword ptr [esi], 0x813c54
// 0043af67  c74620f43b8100       mov dword ptr [esi + 0x20], 0x813bf4
// 0043af6e  c703e83b8100         mov dword ptr [ebx], 0x813be8
// 0043af74  89be38010000         mov dword ptr [esi + 0x138], edi
// 0043af7a  8b17                 mov edx, dword ptr [edi]
// 0043af7c  88442418             mov byte ptr [esp + 0x18], al
// 0043af80  8b4204               mov eax, dword ptr [edx + 4]
// 0043af83  8bcf                 mov ecx, edi
// 0043af85  ffd0                 call eax
// 0043af87  0fb6c8               movzx ecx, al
// 0043af8a  51                   push ecx
// 0043af8b  8bce                 mov ecx, esi
// 0043af8d  e84e712d00           call 0x7120e0
// 0043af92  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043af96  5f                   pop edi
// 0043af97  8bc6                 mov eax, esi
// 0043af99  5e                   pop esi
// 0043af9a  5b                   pop ebx
// 0043af9b  64890d00000000       mov dword ptr fs:[0], ecx
// 0043afa2  83c410               add esp, 0x10
// 0043afa5  c20800               ret 8

struct String {
    const char* c_str() const;
};

extern const char* (__thiscall *string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct TextData
{
    String text;
};

struct Record
{
    virtual void slot0();
    virtual bool value();
    TextData* data;
};

struct PrimaryInterface
{
    virtual ~PrimaryInterface();
    char padding[0x1c];
};

struct SecondaryInterface
{
    virtual ~SecondaryInterface();
    char padding[0xd8];
    int flag;
    char tail[0x18];
};

struct PropertyItem : PrimaryInterface, SecondaryInterface
{
    PropertyItem(const char*, int, int);
    virtual ~PropertyItem();
    void OnValueChanged(int);
};

struct ItemInterface
{
    ItemInterface(Record*, int);
    virtual ~ItemInterface();
    char padding[0x1c];
};

struct XItem : PropertyItem, ItemInterface
{
    Record* record;

    XItem(Record*, int);
    virtual ~XItem();
};

static TextData* dataOf(Record* source)
{
    return source->data;
}

XItem::XItem(Record* source, int argument)
    : PropertyItem(dataOf(source)->text.c_str(), 0, 0),
      ItemInterface(source, argument),
      record(source)
{
    flag = 1;
    OnValueChanged(source->value());
}
