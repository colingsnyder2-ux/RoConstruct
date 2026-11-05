// from server: 98% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0043db80  unit: Vector3Item  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043db80
//
// 0043db80  6aff                 push -1
// 0043db82  6868087c00           push 0x7c0868
// 0043db87  64a100000000         mov eax, dword ptr fs:[0]
// 0043db8d  50                   push eax
// 0043db8e  64892500000000       mov dword ptr fs:[0], esp
// 0043db95  51                   push ecx
// 0043db96  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043db9a  56                   push esi
// 0043db9b  57                   push edi
// 0043db9c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0043dba0  50                   push eax
// 0043dba1  8bf1                 mov esi, ecx
// 0043dba3  57                   push edi
// 0043dba4  89742410             mov dword ptr [esp + 0x10], esi
// 0043dba8  e8b3dcffff           call 0x43b860
// 0043dbad  6a01                 push 1
// 0043dbaf  8bce                 mov ecx, esi
// 0043dbb1  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043dbb9  c7064c4c8100         mov dword ptr [esi], 0x814c4c
// 0043dbbf  c74620ec4b8100       mov dword ptr [esi + 0x20], 0x814bec
// 0043dbc6  c7860c010000e04b8100 mov dword ptr [esi + 0x10c], 0x814be0
// 0043dbd0  89be30010000         mov dword ptr [esi + 0x130], edi
// 0043dbd6  e805452d00           call 0x7120e0
// 0043dbdb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043dbdf  5f                   pop edi
// 0043dbe0  8bc6                 mov eax, esi
// 0043dbe2  5e                   pop esi
// 0043dbe3  64890d00000000       mov dword ptr fs:[0], ecx
// 0043dbea  83c410               add esp, 0x10
// 0043dbed  c20800               ret 8

extern const unsigned int primaryTable[];
extern const unsigned int secondaryTable[];
extern const unsigned int tertiaryTable[];

struct CXTPPropertyGridItem {
    const unsigned int* primary;
    char reserved04[0x1C];
    const unsigned int* secondary;
    char reserved24[0xE8];
    const unsigned int* tertiary;
    char reserved110[0x20];

    CXTPPropertyGridItem(void* value, int argument);
    ~CXTPPropertyGridItem();
    void OnValueChanged(int value);
};

struct Vector3Item : CXTPPropertyGridItem {
    void* value;

    Vector3Item(void* value, int argument);
};

Vector3Item::Vector3Item(void* initialValue, int argument)
    : CXTPPropertyGridItem(initialValue, argument)
{
    primary = primaryTable;
    secondary = secondaryTable;
    tertiary = tertiaryTable;
    value = initialValue;
    OnValueChanged(1);
}
