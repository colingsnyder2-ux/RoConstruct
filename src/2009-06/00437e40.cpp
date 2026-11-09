// from server: 100% by EspClaude
// roc 2009-06 00437e40  unit: XBrickColorItem  size: 168 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00437e40
//
// 00437e40  6aff                 push -1
// 00437e42  6839068500           push 0x850639
// 00437e47  64a100000000         mov eax, dword ptr fs:[0]
// 00437e4d  50                   push eax
// 00437e4e  64892500000000       mov dword ptr fs:[0], esp
// 00437e55  51                   push ecx
// 00437e56  53                   push ebx
// 00437e57  56                   push esi
// 00437e58  8d442408             lea eax, [esp + 8]
// 00437e5c  50                   push eax
// 00437e5d  8bf1                 mov esi, ecx
// 00437e5f  e8ec97ffff           call 0x431650
// 00437e64  6816d28a00           push 0x8ad216
// 00437e69  8bc8                 mov ecx, eax
// 00437e6b  c744241800000000     mov dword ptr [esp + 0x18], 0
// 00437e73  ff15d4fc8900         call dword ptr [0x89fcd4]
// 00437e79  85c0                 test eax, eax
// 00437e7b  8d4c2408             lea ecx, [esp + 8]
// 00437e7f  0f94c3               sete bl
// 00437e82  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00437e8a  ff1510fd8900         call dword ptr [0x89fd10]
// 00437e90  84db                 test bl, bl
// 00437e92  7415                 je 0x437ea9
// 00437e94  33c0                 xor eax, eax
// 00437e96  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00437e9a  64890d00000000       mov dword ptr fs:[0], ecx
// 00437ea1  5e                   pop esi
// 00437ea2  5b                   pop ebx
// 00437ea3  83c410               add esp, 0x10
// 00437ea6  c21400               ret 0x14
// 00437ea9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00437ead  8b542424             mov edx, dword ptr [esp + 0x24]
// 00437eb1  83ec10               sub esp, 0x10
// 00437eb4  8bc4                 mov eax, esp
// 00437eb6  8908                 mov dword ptr [eax], ecx
// 00437eb8  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00437ebc  895004               mov dword ptr [eax + 4], edx
// 00437ebf  8b54243c             mov edx, dword ptr [esp + 0x3c]
// 00437ec3  894808               mov dword ptr [eax + 8], ecx
// 00437ec6  89500c               mov dword ptr [eax + 0xc], edx
// 00437ec9  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00437ecd  50                   push eax
// 00437ece  8bce                 mov ecx, esi
// 00437ed0  e86b453500           call 0x78c440
// 00437ed5  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00437ed9  5e                   pop esi
// 00437eda  64890d00000000       mov dword ptr fs:[0], ecx
// 00437ee1  5b                   pop ebx
// 00437ee2  83c410               add esp, 0x10
// 00437ee5  c21400               ret 0x14
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
