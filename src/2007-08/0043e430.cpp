// from server: 100% by Yeetserama
// roc 2007-08 0043e430  unit: XBrickColorItem  size: 181 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043e430
//
// 0043e430  6aff                 push -1
// 0043e432  6849d87300           push 0x73d849
// 0043e437  64a100000000         mov eax, dword ptr fs:[0]
// 0043e43d  50                   push eax
// 0043e43e  51                   push ecx
// 0043e43f  53                   push ebx
// 0043e440  56                   push esi
// 0043e441  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043e446  33c4                 xor eax, esp
// 0043e448  50                   push eax
// 0043e449  8d442410             lea eax, [esp + 0x10]
// 0043e44d  64a300000000         mov dword ptr fs:[0], eax
// 0043e453  8bf1                 mov esi, ecx
// 0043e455  8d44240c             lea eax, [esp + 0xc]
// 0043e459  50                   push eax
// 0043e45a  e8f1a9ffff           call 0x438e50
// 0043e45f  6854597800           push 0x785954
// 0043e464  8bc8                 mov ecx, eax
// 0043e466  c744241c00000000     mov dword ptr [esp + 0x1c], 0
// 0043e46e  ff15b8dc7700         call dword ptr [0x77dcb8]
// 0043e474  85c0                 test eax, eax
// 0043e476  8d4c240c             lea ecx, [esp + 0xc]
// 0043e47a  0f94c3               sete bl
// 0043e47d  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 0043e485  ff15bcdd7700         call dword ptr [0x77ddbc]
// 0043e48b  84db                 test bl, bl
// 0043e48d  7416                 je 0x43e4a5
// 0043e48f  33c0                 xor eax, eax
// 0043e491  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043e495  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e49c  59                   pop ecx
// 0043e49d  5e                   pop esi
// 0043e49e  5b                   pop ebx
// 0043e49f  83c410               add esp, 0x10
// 0043e4a2  c21400               ret 0x14
// 0043e4a5  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0043e4a9  8b542428             mov edx, dword ptr [esp + 0x28]
// 0043e4ad  83ec10               sub esp, 0x10
// 0043e4b0  8bc4                 mov eax, esp
// 0043e4b2  8908                 mov dword ptr [eax], ecx
// 0043e4b4  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0043e4b8  895004               mov dword ptr [eax + 4], edx
// 0043e4bb  8b542440             mov edx, dword ptr [esp + 0x40]
// 0043e4bf  894808               mov dword ptr [eax + 8], ecx
// 0043e4c2  89500c               mov dword ptr [eax + 0xc], edx
// 0043e4c5  8b442430             mov eax, dword ptr [esp + 0x30]
// 0043e4c9  50                   push eax
// 0043e4ca  8bce                 mov ecx, esi
// 0043e4cc  e8bfc12500           call 0x69a690
// 0043e4d1  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043e4d5  64890d00000000       mov dword ptr fs:[0], ecx
// 0043e4dc  59                   pop ecx
// 0043e4dd  5e                   pop esi
// 0043e4de  5b                   pop ebx
// 0043e4df  83c410               add esp, 0x10
// 0043e4e2  c21400               ret 0x14
// copied from an identical function in another client (function ?action@XBrickColorItem@ns_ROCX000001@@QAEHPAXURect@2@@Z)

namespace ns_ROCX000001 {
// from server: 100% by king_originala
struct Text;

extern const char authoring[];
extern int (__thiscall* compareText)(const Text*, const char*);
extern void (__thiscall* destroyText)(Text*);

struct Text {
    void* data;
    int compare(const char* s) const;
    ~Text();
};

inline int Text::compare(const char* s) const
{
    return compareText(this, s);
}

inline Text::~Text()
{
    destroyText(this);
}

struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct XBrickColorItem {
    Text getText();
    int baseAction(void* context, Rect bounds);
    int action(void* context, Rect bounds);
};

int XBrickColorItem::action(void* context, Rect bounds)
{
    if (getText().compare(authoring) == 0)
        return 0;
    return baseAction(context, bounds);
}
}
