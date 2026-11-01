// from server: 100% by EspClaude
// from server: 82% by EspClaude
// roc 2009-06 00607720  unit: RBX::GuiTarget  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00607720
//

// from server: 100% by atomic.potato
// roc 2008-06 00573570  unit: RBX::GuiTarget  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00573570
//

struct GuiTarget
{
    char padding[0x98];
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
