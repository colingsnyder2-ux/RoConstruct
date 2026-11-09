// from server: 65% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Instance;
struct Clothing;
bool isA(const Instance* i, const void* tag);
Clothing* asClothing(Instance* i);
struct Instance {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16();
    virtual void onParent(Clothing* c);
    int pad[17];
    Instance* parent;
    void onAncestorChanged(int e);
};
void Instance::onAncestorChanged(int)
{
    if (isA(this, 0)) {
        if (Clothing* c = asClothing(parent))
            onParent(c);
    }
}
struct Name;
const Name* declareName(const char* s);
const Name* clothingName()
{
    static const Name* n = declareName("Clothing");
    return n;
}
