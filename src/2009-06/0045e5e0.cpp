// from server: 94% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0045eff0  unit: RBX::Stats::H::?$TypedStatsItem  size: 34 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045eff0
//
// 0045eff0  51                   push ecx
// 0045eff1  56                   push esi
// 0045eff2  8bf1                 mov esi, ecx
// 0045eff4  8d8e58010000         lea ecx, [esi + 0x158]
// 0045effa  e8c1bffcff           call 0x42afc0
// 0045efff  89442404             mov dword ptr [esp + 4], eax
// 0045f003  8d442404             lea eax, [esp + 4]
// 0045f007  50                   push eax
// 0045f008  8bce                 mov ecx, esi
// 0045f00a  e801a11600           call 0x5c9110
// 0045f00f  5e                   pop esi
// 0045f010  59                   pop ecx
// 0045f011  c3                   ret 

struct EventHandler
{
    int get();
};

struct StatsItem
{
    char storage[0x158];
    EventHandler handler;

    void update(const int* value);
    void f();
};

void StatsItem::f()
{
    int value = handler.get();
    update(&value);
}
