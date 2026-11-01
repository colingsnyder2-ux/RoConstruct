// from server: 100% by atomic.potato
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
