// from server: 38% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad[40];
    int state;
    void f();
};

struct Local
{
    void g(int);
};

void Local::g(int)
{
}

void VCRenderSettingsItem_EnumPropDescriptor::f()
{
    Local *p = (Local *)(this);
    p->g(0);
    state = 4;
}
