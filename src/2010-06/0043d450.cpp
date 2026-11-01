// from server: 100% by Yeetserama
// roc 2010-06 0043d450  unit: AxesItem  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043d450
//
// 0043d450  6aff                 push -1
// 0043d452  68780d9800           push 0x980d78
// 0043d457  64a100000000         mov eax, dword ptr fs:[0]
// 0043d45d  50                   push eax
// 0043d45e  64892500000000       mov dword ptr fs:[0], esp
// 0043d465  51                   push ecx
// 0043d466  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043d46a  56                   push esi
// 0043d46b  57                   push edi
// 0043d46c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0043d470  50                   push eax
// 0043d471  8bf1                 mov esi, ecx
// 0043d473  57                   push edi
// 0043d474  89742410             mov dword ptr [esp + 0x10], esi
// 0043d478  e8d3afffff           call 0x438450
// 0043d47d  6a01                 push 1
// 0043d47f  8bce                 mov ecx, esi
// 0043d481  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043d489  c706cc9fa000         mov dword ptr [esi], 0xa09fcc
// 0043d48f  c746206c9fa000       mov dword ptr [esi + 0x20], 0xa09f6c
// 0043d496  c7860c010000609fa000 mov dword ptr [esi + 0x10c], 0xa09f60
// 0043d4a0  89be30010000         mov dword ptr [esi + 0x130], edi
// 0043d4a6  e8f5c33d00           call 0x8198a0
// 0043d4ab  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043d4af  5f                   pop edi
// 0043d4b0  8bc6                 mov eax, esi
// 0043d4b2  5e                   pop esi
// 0043d4b3  64890d00000000       mov dword ptr fs:[0], ecx
// 0043d4ba  83c410               add esp, 0x10
// 0043d4bd  c20800               ret 8
// copied from an identical function in another client (function ??0Vector3Item@ns_ROCX000007@@QAE@PAXH@Z)

namespace ns_ROCX000007 {
// from server: 100% by king_originala
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
}
