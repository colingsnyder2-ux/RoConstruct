// from server: 100% by EspClaude
// roc 2009-06 00438350  unit: Vector3Item  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00438350
//
// 00438350  6aff                 push -1
// 00438352  68a8fc8400           push 0x84fca8
// 00438357  64a100000000         mov eax, dword ptr fs:[0]
// 0043835d  50                   push eax
// 0043835e  64892500000000       mov dword ptr fs:[0], esp
// 00438365  51                   push ecx
// 00438366  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043836a  56                   push esi
// 0043836b  57                   push edi
// 0043836c  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00438370  50                   push eax
// 00438371  8bf1                 mov esi, ecx
// 00438373  57                   push edi
// 00438374  89742410             mov dword ptr [esp + 0x10], esi
// 00438378  e843d6ffff           call 0x4359c0
// 0043837d  6a01                 push 1
// 0043837f  8bce                 mov ecx, esi
// 00438381  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00438389  c70634528b00         mov dword ptr [esi], 0x8b5234
// 0043838f  c74620d4518b00       mov dword ptr [esi + 0x20], 0x8b51d4
// 00438396  c7860c010000c8518b00 mov dword ptr [esi + 0x10c], 0x8b51c8
// 004383a0  89be30010000         mov dword ptr [esi + 0x130], edi
// 004383a6  e825253500           call 0x78a8d0
// 004383ab  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004383af  5f                   pop edi
// 004383b0  8bc6                 mov eax, esi
// 004383b2  5e                   pop esi
// 004383b3  64890d00000000       mov dword ptr fs:[0], ecx
// 004383ba  83c410               add esp, 0x10
// 004383bd  c20800               ret 8
// copied from an identical function in another client (function ??0Vector3Item@ns_ROCX00000e@@QAE@PAXH@Z)

namespace ns_ROCX00000e {
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
