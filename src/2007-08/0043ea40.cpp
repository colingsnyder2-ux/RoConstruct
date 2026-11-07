// from server: 100% by Intel
// from server: 98% by EspClaude
// roc 2007-08 0043ea40  unit: Vector3Item  size: 124 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043ea40
//
// 0043ea40  6aff                 push -1
// 0043ea42  68f8ec7300           push 0x73ecf8
// 0043ea47  64a100000000         mov eax, dword ptr fs:[0]
// 0043ea4d  50                   push eax
// 0043ea4e  51                   push ecx
// 0043ea4f  56                   push esi
// 0043ea50  57                   push edi
// 0043ea51  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043ea56  33c4                 xor eax, esp
// 0043ea58  50                   push eax
// 0043ea59  8d442410             lea eax, [esp + 0x10]
// 0043ea5d  64a300000000         mov dword ptr fs:[0], eax
// 0043ea63  8bf1                 mov esi, ecx
// 0043ea65  8974240c             mov dword ptr [esp + 0xc], esi
// 0043ea69  8b442424             mov eax, dword ptr [esp + 0x24]
// 0043ea6d  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0043ea71  50                   push eax
// 0043ea72  57                   push edi
// 0043ea73  e858dfffff           call 0x43c9d0
// 0043ea78  6a01                 push 1
// 0043ea7a  8bce                 mov ecx, esi
// 0043ea7c  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043ea84  c70654ea7800         mov dword ptr [esi], 0x78ea54
// 0043ea8a  c74620f4e97800       mov dword ptr [esi + 0x20], 0x78e9f4
// 0043ea91  c78600010000e8e97800 mov dword ptr [esi + 0x100], 0x78e9e8
// 0043ea9b  89be1c010000         mov dword ptr [esi + 0x11c], edi
// 0043eaa1  e81aa22500           call 0x698cc0
// 0043eaa6  8bc6                 mov eax, esi
// 0043eaa8  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043eaac  64890d00000000       mov dword ptr fs:[0], ecx
// 0043eab3  59                   pop ecx
// 0043eab4  5f                   pop edi
// 0043eab5  5e                   pop esi
// 0043eab6  83c410               add esp, 0x10
// 0043eab9  c20800               ret 8

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
    char reserved24[0xDC];
    const unsigned int* tertiary;
    char reserved110[0x18];

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
