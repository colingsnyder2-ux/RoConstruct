// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043c270  unit: HVCXTPPropertyGridItem::?$XItem  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043c270
//
// 0043c270  6aff                 push -1
// 0043c272  68b6e97300           push 0x73e9b6
// 0043c277  64a100000000         mov eax, dword ptr fs:[0]
// 0043c27d  50                   push eax
// 0043c27e  51                   push ecx
// 0043c27f  53                   push ebx
// 0043c280  56                   push esi
// 0043c281  57                   push edi
// 0043c282  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043c287  33c4                 xor eax, esp
// 0043c289  50                   push eax
// 0043c28a  8d442414             lea eax, [esp + 0x14]
// 0043c28e  64a300000000         mov dword ptr fs:[0], eax
// 0043c294  8bf1                 mov esi, ecx
// 0043c296  89742410             mov dword ptr [esp + 0x10], esi
// 0043c29a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0043c29e  8b4704               mov eax, dword ptr [edi + 4]
// 0043c2a1  8d4804               lea ecx, [eax + 4]
// 0043c2a4  ff15a8e67700         call dword ptr [0x77e6a8]
// 0043c2aa  6a00                 push 0
// 0043c2ac  6a00                 push 0
// 0043c2ae  50                   push eax
// 0043c2af  8bce                 mov ecx, esi
// 0043c2b1  e83ae32500           call 0x69a5f0
// 0043c2b6  8b442428             mov eax, dword ptr [esp + 0x28]
// 0043c2ba  50                   push eax
// 0043c2bb  8d9e0c010000         lea ebx, [esi + 0x10c]
// 0043c2c1  57                   push edi
// 0043c2c2  8bcb                 mov ecx, ebx
// 0043c2c4  c744242400000000     mov dword ptr [esp + 0x24], 0
// 0043c2cc  e8fff2ffff           call 0x43b5d0
// 0043c2d1  b801000000           mov eax, 1
// 0043c2d6  8986f0000000         mov dword ptr [esi + 0xf0], eax
// 0043c2dc  c70624da7800         mov dword ptr [esi], 0x78da24
// 0043c2e2  c74620c4d97800       mov dword ptr [esi + 0x20], 0x78d9c4
// 0043c2e9  c703b8d97800         mov dword ptr [ebx], 0x78d9b8
// 0043c2ef  89be24010000         mov dword ptr [esi + 0x124], edi
// 0043c2f5  8b17                 mov edx, dword ptr [edi]
// 0043c2f7  8844241c             mov byte ptr [esp + 0x1c], al
// 0043c2fb  8b4204               mov eax, dword ptr [edx + 4]
// 0043c2fe  8bcf                 mov ecx, edi
// 0043c300  ffd0                 call eax
// 0043c302  0fb6c8               movzx ecx, al
// 0043c305  51                   push ecx
// 0043c306  8bce                 mov ecx, esi
// 0043c308  e8b3c92500           call 0x698cc0
// 0043c30d  8bc6                 mov eax, esi
// 0043c30f  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0043c313  64890d00000000       mov dword ptr fs:[0], ecx
// 0043c31a  59                   pop ecx
// 0043c31b  5f                   pop edi
// 0043c31c  5e                   pop esi
// 0043c31d  5b                   pop ebx
// 0043c31e  83c410               add esp, 0x10
// 0043c321  c20800               ret 8

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
    char padding[4];
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
    char padding[0xcc];
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
    char padding[0x14];
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