// from server: 100% by Yeetserama
// roc 2011-06 004490f0  unit: XBrickColorItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004490f0
//
// 004490f0  6aff                 push -1
// 004490f2  68395f9d00           push 0x9d5f39
// 004490f7  64a100000000         mov eax, dword ptr fs:[0]
// 004490fd  50                   push eax
// 004490fe  64892500000000       mov dword ptr fs:[0], esp
// 00449105  51                   push ecx
// 00449106  53                   push ebx
// 00449107  56                   push esi
// 00449108  8d442408             lea eax, [esp + 8]
// 0044910c  50                   push eax
// 0044910d  8bf1                 mov esi, ecx
// 0044910f  e8dc9fffff           call 0x4430f0
// 00449114  68cabea500           push 0xa5beca
// 00449119  8bc8                 mov ecx, eax
// 0044911b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00449123  ff15cc2da400         call dword ptr [0xa42dcc]
// 00449129  85c0                 test eax, eax
// 0044912b  8d4c2408             lea ecx, [esp + 8]
// 0044912f  0f94c3               sete bl
// 00449132  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0044913a  ff15082ea400         call dword ptr [0xa42e08]
// 00449140  84db                 test bl, bl
// 00449142  7415                 je 0x449159
// 00449144  33c0                 xor eax, eax
// 00449146  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0044914a  64890d00000000       mov dword ptr fs:[0], ecx
// 00449151  5e                   pop esi
// 00449152  5b                   pop ebx
// 00449153  83c410               add esp, 0x10
// 00449156  c21400               ret 0x14
// 00449159  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0044915d  8b542424             mov edx, dword ptr [esp + 0x24]
// 00449161  83ec10               sub esp, 0x10
// 00449164  8bc4                 mov eax, esp
// 00449166  8908                 mov dword ptr [eax], ecx
// 00449168  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0044916c  895004               mov dword ptr [eax + 4], edx
// 0044916f  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00449173  894808               mov dword ptr [eax + 8], ecx
// 00449176  89500c               mov dword ptr [eax + 0xc], edx
// 00449179  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0044917d  50                   push eax
// 0044917e  8bce                 mov ecx, esi
// 00449180  e81b294300           call 0x87baa0
// 00449185  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00449189  5e                   pop esi
// 0044918a  64890d00000000       mov dword ptr fs:[0], ecx
// 00449191  5b                   pop ebx
// 00449192  83c410               add esp, 0x10
// 00449195  c21400               ret 0x14
// copied from an identical function in another client (function ?action@XBrickColorItem@ns_ROCX000007@@QAEHPAXURect@2@@Z)

namespace ns_ROCX000007 {
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
