// from server: 100% by EspClaude
// from server: 46% by Intel
// roc 2007-08 00455c80  unit: CRobloxReportPaneView  size: 93 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00455c80
// 00455c80  6aff                 push -1
// 00455c82  6868197400           push 0x741968
// 00455c87  64a100000000         mov eax, dword ptr fs:[0]
// 00455c8d  50                   push eax
// 00455c8e  51                   push ecx
// 00455c8f  56                   push esi
// 00455c90  a188518b00           mov eax, dword ptr [0x8b5188]
// 00455c95  33c4                 xor eax, esp
// 00455c97  50                   push eax
// 00455c98  8d44240c             lea eax, [esp + 0xc]
// 00455c9c  64a300000000         mov dword ptr fs:[0], eax
// 00455ca2  8bf1                 mov esi, ecx
// 00455ca4  89742408             mov dword ptr [esp + 8], esi
// 00455ca8  33c9                 xor ecx, ecx
// 00455caa  3bf1                 cmp esi, ecx
// 00455cac  894c2414             mov dword ptr [esp + 0x14], ecx
// 00455cb0  7406                 je 0x455cb8
// 00455cb2  8d8e18030000         lea ecx, [esi + 0x318]
// 00455cb8  e83317fbff           call 0x4073f0
// 00455cbd  8bce                 mov ecx, esi
// 00455cbf  c7442414ffffffff     mov dword ptr [esp + 0x14], 0xffffffff
// 00455cc7  e8e4fdffff           call 0x455ab0
// 00455ccc  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00455cd0  64890d00000000       mov dword ptr fs:[0], ecx
// 00455cd7  59                   pop ecx
// 00455cd8  5e                   pop esi
// 00455cd9  83c410               add esp, 0x10
// 00455cdc  c3                   ret 

class Listener {
public:
    virtual void onChanged() = 0;
    ~Listener();
};

class PaneBase {
public:
    virtual ~PaneBase();
    char pad_4[0x314];
};

class CRobloxReportPaneView : public PaneBase, public Listener {
public:
    virtual void onChanged();
};

CRobloxReportPaneView* makePane() { return new CRobloxReportPaneView(); }
