// from server: 98% by EspClaude
// roc-cl: 50727
// from server: 100% by king_originala
// roc 2008-06 0043ea20  unit: RBX::Soundscape::VSoundId::?$ContentItem  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043ea20
//
// 0043ea20  6aff                 push -1
// 0043ea22  6868087c00           push 0x7c0868
// 0043ea27  64a100000000         mov eax, dword ptr fs:[0]
// 0043ea2d  50                   push eax
// 0043ea2e  64892500000000       mov dword ptr fs:[0], esp
// 0043ea35  51                   push ecx
// 0043ea36  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043ea3a  56                   push esi
// 0043ea3b  8bf1                 mov esi, ecx
// 0043ea3d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043ea41  50                   push eax
// 0043ea42  51                   push ecx
// 0043ea43  8bce                 mov ecx, esi
// 0043ea45  8974240c             mov dword ptr [esp + 0xc], esi
// 0043ea49  e852e5ffff           call 0x43cfa0
// 0043ea4e  8bce                 mov ecx, esi
// 0043ea50  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043ea58  c70614528100         mov dword ptr [esi], 0x815214
// 0043ea5e  c74620b4518100       mov dword ptr [esi + 0x20], 0x8151b4
// 0043ea65  c7860c010000ac518100 mov dword ptr [esi + 0x10c], 0x8151ac
// 0043ea6f  e8bc232d00           call 0x710e30
// 0043ea74  83c804               or eax, 4
// 0043ea77  50                   push eax
// 0043ea78  8bce                 mov ecx, esi
// 0043ea7a  e851232d00           call 0x710dd0
// 0043ea7f  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0043ea85  8b11                 mov edx, dword ptr [ecx]
// 0043ea87  8b4258               mov eax, dword ptr [edx + 0x58]
// 0043ea8a  6801e10000           push 0xe101
// 0043ea8f  6a00                 push 0
// 0043ea91  6834508100           push 0x815034
// 0043ea96  ffd0                 call eax
// 0043ea98  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0043ea9e  8b11                 mov edx, dword ptr [ecx]
// 0043eaa0  8b4258               mov eax, dword ptr [edx + 0x58]
// 0043eaa3  6820e10000           push 0xe120
// 0043eaa8  6a01                 push 1
// 0043eaaa  682c508100           push 0x81502c
// 0043eaaf  ffd0                 call eax
// 0043eab1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043eab5  8bc6                 mov eax, esi
// 0043eab7  5e                   pop esi
// 0043eab8  64890d00000000       mov dword ptr fs:[0], ecx
// 0043eabf  83c410               add esp, 0x10
// 0043eac2  c20800               ret 8

struct Button;
typedef void (__thiscall *ButtonAction)(Button*, const char*, int, int);

struct Button {
    ButtonAction* table;
};

extern void* mainTable[];
extern void* secondaryTable[];
extern void* tertiaryTable[];
extern const char browseText[];
extern const char clearText[];

struct Base {
    void** table;
    char padding04[28];
    void** secondary;
    char padding24[160];
    Button* buttons;
    char paddingC8[68];
    void** tertiary;

    Base(const void*, const void*);
    ~Base();
    int getFlags();
    void setFlags(int);
};

struct S : Base {
    S(const void*, const void*);
};

S::S(const void* first, const void* second)
    : Base(first, second)
{
    table = mainTable;
    secondary = secondaryTable;
    tertiary = tertiaryTable;

    setFlags(getFlags() | 4);

    buttons->table[22](buttons, browseText, 0, 0xe101);
    buttons->table[22](buttons, clearText, 1, 0xe120);
}
