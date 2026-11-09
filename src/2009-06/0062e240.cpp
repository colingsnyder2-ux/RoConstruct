// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class Instance {
public:
    char pad[0x48];
    Instance* parent;
    bool isDescendentOf2(const Instance* ancestor) const;
    inline bool isDescendentOf(const Instance* ancestor) const
    {
        if (ancestor == parent) return true;
        if (!parent) return false;
        return parent->isDescendentOf2(ancestor);
    }
};
class Workspace : public Instance {
public:
    char pad2[0x150 - sizeof(Instance)];
    void* world;
    static Workspace* findWorkspace(Instance* context);
};
void* getWorld(Instance* context)
{
    Workspace* w = Workspace::findWorkspace(context);
    if (w && (context == w || context->isDescendentOf(w)))
        return w->world;
    return 0;
}
