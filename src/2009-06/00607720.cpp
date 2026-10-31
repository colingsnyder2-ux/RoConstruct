// from server: 82% by EspClaude
// from server: 100% by atomic.potato
// roc 2008-06 00573570  unit: RBX::GuiTarget  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00573570
//
// 00573570  d90560f88200         fld dword ptr [0x82f860]
// 00573576  d9993c010000         fstp dword ptr [ecx + 0x13c]
// 0057357c  d9055cf88200         fld dword ptr [0x82f85c]
// 00573582  d99940010000         fstp dword ptr [ecx + 0x140]
// 00573588  c7814401000000000000 mov dword ptr [ecx + 0x144], 0
// 00573592  c3                   ret 

struct GuiTarget
{
    char padding[316];
    float field13c;
    float field140;
    volatile int field144;
    void f();
};

extern float global_82f860;
extern float global_82f85c;

void GuiTarget::f()
{
    field13c = global_82f860;
    field140 = global_82f85c;
    field144 = 0;
}
