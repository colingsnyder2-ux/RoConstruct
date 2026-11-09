// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0043e840  unit: ScriptItem  size: 165 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043e840
//
// 0043e840  6aff                 push -1
// 0043e842  6868087c00           push 0x7c0868
// 0043e847  64a100000000         mov eax, dword ptr fs:[0]
// 0043e84d  50                   push eax
// 0043e84e  64892500000000       mov dword ptr fs:[0], esp
// 0043e855  51                   push ecx
// 0043e856  8b442418             mov eax, dword ptr [esp + 0x18]
// 0043e85a  56                   push esi
// 0043e85b  8bf1                 mov esi, ecx
// 0043e85d  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0043e861  50                   push eax
// 0043e862  51                   push ecx
// 0043e863  8bce                 mov ecx, esi
// 0043e865  8974240c             mov dword ptr [esp + 0xc], esi
// 0043e869  e842e1ffff           call 0x43c9b0
// 0043e86e  8bce                 mov ecx, esi
// 0043e870  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0043e878  c706ac508100         mov dword ptr [esi], 0x8150ac
// 0043e87e  c746204c508100       mov dword ptr [esi + 0x20], 0x81504c
// 0043e885  c7860c01000044508100 mov dword ptr [esi + 0x10c], 0x815044
// 0043e88f  e89c252d00           call 0x710e30
// 0043e894  83c804               or eax, 4
// 0043e897  50                   push eax
// 0043e898  8bce                 mov ecx, esi
// 0043e89a  e831252d00           call 0x710dd0
// 0043e89f  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0043e8a5  8b11                 mov edx, dword ptr [ecx]
// 0043e8a7  8b4258               mov eax, dword ptr [edx + 0x58]
// 0043e8aa  6801e10000           push 0xe101
// 0043e8af  6a00                 push 0
// 0043e8b1  6834508100           push 0x815034
// 0043e8b6  ffd0                 call eax
// 0043e8b8  8b8ec4000000         mov ecx, dword ptr [esi + 0xc4]
// 0043e8be  8b11                 mov edx, dword ptr [ecx]
// 0043e8c0  8b4258               mov eax, dword ptr [edx + 0x58]
// 0043e8c3  6820e10000           push 0xe120
// 0043e8c8  6a01                 push 1
// 0043e8ca  682c508100           push 0x81502c
// 0043e8cf  ffd0                 call eax
// 0043e8d1  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0043e8d5  8bc6                 mov eax, esi
// 0043e8d7  5e                   pop esi
// 0043e8d8  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e8df  83c410               add esp, 0x10
// 0043e8e2  c20800               ret 8

struct Buttons;
typedef void (__thiscall *ButtonMethod)(Buttons *, const char *, int, int);

struct Buttons {
    ButtonMethod *table;
};

struct Primary {
    virtual ~Primary();
    char padding[28];
};

struct Secondary {
    virtual ~Secondary();
    char padding0[160];
    Buttons *buttons;
    char padding1[68];
};

struct Tertiary {
    virtual ~Tertiary();
};

struct Base : Primary, Secondary, Tertiary {
    Base(int, int);
    virtual ~Base();
    int getFlags();
    void setFlags(int);
};

struct ScriptItem : Base {
    ScriptItem(int, int);
    virtual ~ScriptItem();
};

ScriptItem::ScriptItem(int a, int b) : Base(a, b)
{
    setFlags(getFlags() | 4);
    buttons->table[22](buttons, "Clear", 1, 0xe120);
}
