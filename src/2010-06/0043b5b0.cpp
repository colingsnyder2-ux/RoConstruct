// from server: 100% by Yeetserama
// roc 2010-06 0043b5b0  unit: XBrickColorItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043b5b0
//
// 0043b5b0  6aff                 push -1
// 0043b5b2  68a9fe9700           push 0x97fea9
// 0043b5b7  64a100000000         mov eax, dword ptr fs:[0]
// 0043b5bd  50                   push eax
// 0043b5be  64892500000000       mov dword ptr fs:[0], esp
// 0043b5c5  51                   push ecx
// 0043b5c6  53                   push ebx
// 0043b5c7  56                   push esi
// 0043b5c8  8d442408             lea eax, [esp + 8]
// 0043b5cc  50                   push eax
// 0043b5cd  8bf1                 mov esi, ecx
// 0043b5cf  e86c84ffff           call 0x433a40
// 0043b5d4  68fe08a000           push 0xa008fe
// 0043b5d9  8bc8                 mov ecx, eax
// 0043b5db  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043b5e3  ff15b4ce9e00         call dword ptr [0x9eceb4]
// 0043b5e9  85c0                 test eax, eax
// 0043b5eb  8d4c2408             lea ecx, [esp + 8]
// 0043b5ef  0f94c3               sete bl
// 0043b5f2  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 0043b5fa  ff15f0ce9e00         call dword ptr [0x9ecef0]
// 0043b600  84db                 test bl, bl
// 0043b602  7415                 je 0x43b619
// 0043b604  33c0                 xor eax, eax
// 0043b606  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043b60a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b611  5e                   pop esi
// 0043b612  5b                   pop ebx
// 0043b613  83c410               add esp, 0x10
// 0043b616  c21400               ret 0x14
// 0043b619  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0043b61d  8b542424             mov edx, dword ptr [esp + 0x24]
// 0043b621  83ec10               sub esp, 0x10
// 0043b624  8bc4                 mov eax, esp
// 0043b626  8908                 mov dword ptr [eax], ecx
// 0043b628  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0043b62c  895004               mov dword ptr [eax + 4], edx
// 0043b62f  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 0043b633  894808               mov dword ptr [eax + 8], ecx
// 0043b636  89500c               mov dword ptr [eax + 0xc], edx
// 0043b639  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0043b63d  50                   push eax
// 0043b63e  8bce                 mov ecx, esi
// 0043b640  e8bbfd3d00           call 0x81b400
// 0043b645  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0043b649  5e                   pop esi
// 0043b64a  64890d00000000       mov dword ptr fs:[0], ecx
// 0043b651  5b                   pop ebx
// 0043b652  83c410               add esp, 0x10
// 0043b655  c21400               ret 0x14
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
