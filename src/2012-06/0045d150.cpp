// from server: 100% by Xemicl
// roc 2012-06 0045d150  unit: XBrickColorItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0045d150
//
// 0045d150  6aff                 push -1
// 0045d152  68d9aea900           push 0xa9aed9
// 0045d157  64a100000000         mov eax, dword ptr fs:[0]
// 0045d15d  50                   push eax
// 0045d15e  64892500000000       mov dword ptr fs:[0], esp
// 0045d165  51                   push ecx
// 0045d166  53                   push ebx
// 0045d167  56                   push esi
// 0045d168  8d442408             lea eax, [esp + 8]
// 0045d16c  50                   push eax
// 0045d16d  8bf1                 mov esi, ecx
// 0045d16f  e8cc74ffff           call 0x454640
// 0045d174  68e83bb400           push 0xb43be8
// 0045d179  8bc8                 mov ecx, eax
// 0045d17b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0045d183  ff159c47b200         call dword ptr [0xb2479c]
// 0045d189  85c0                 test eax, eax
// 0045d18b  8d4c2408             lea ecx, [esp + 8]
// 0045d18f  0f94c3               sete bl
// 0045d192  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0045d19a  ff15d047b200         call dword ptr [0xb247d0]
// 0045d1a0  84db                 test bl, bl
// 0045d1a2  7415                 je 0x45d1b9
// 0045d1a4  33c0                 xor eax, eax
// 0045d1a6  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045d1aa  64890d00000000       mov dword ptr fs:[0], ecx
// 0045d1b1  5e                   pop esi
// 0045d1b2  5b                   pop ebx
// 0045d1b3  83c410               add esp, 0x10
// 0045d1b6  c21400               ret 0x14
// 0045d1b9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0045d1bd  8b542424             mov edx, dword ptr [esp + 0x24]
// 0045d1c1  83ec10               sub esp, 0x10
// 0045d1c4  8bc4                 mov eax, esp
// 0045d1c6  8908                 mov dword ptr [eax], ecx
// 0045d1c8  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0045d1cc  895004               mov dword ptr [eax + 4], edx
// 0045d1cf  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0045d1d3  894808               mov dword ptr [eax + 8], ecx
// 0045d1d6  89500c               mov dword ptr [eax + 0xc], edx
// 0045d1d9  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0045d1dd  50                   push eax
// 0045d1de  8bce                 mov ecx, esi
// 0045d1e0  e85b6e5900           call 0x9f4040
// 0045d1e5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0045d1e9  5e                   pop esi
// 0045d1ea  64890d00000000       mov dword ptr fs:[0], ecx
// 0045d1f1  5b                   pop ebx
// 0045d1f2  83c410               add esp, 0x10
// 0045d1f5  c21400               ret 0x14
// copied from an identical function in another client (function ?action@XBrickColorItem@ns_ROCX000006@@QAEHPAXURect@2@@Z)

namespace ns_ROCX000006 {
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