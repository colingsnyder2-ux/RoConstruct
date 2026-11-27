// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
struct Primitive;
struct PartInstance;
struct World { void g(Primitive *, bool); };
World *getWorld(PartInstance *);
struct PartInstance
{
    char pad[0x198];
    Primitive *primitive;
    void f();
};
void PartInstance::f()
{
    World *w = getWorld(this);
    if (w)
        w->g(primitive, true);
}