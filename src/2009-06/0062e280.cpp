// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x48 - 4];
    Instance* parent;
    bool isDescendentOf(const Instance* ancestor) const
    {
        Instance* thisParent = this->parent;
        if (ancestor == thisParent)
            return true;
        if (thisParent)
            return thisParent->isDescendentOf(ancestor);
        else
            return false;
    }
};
class Workspace : public Instance {
public:
    static Workspace* getWorkspaceIfInWorkspace(const Instance* context);
    static bool contextInWorkspace(const Instance* context);
};
class ServiceProvider { public: template<class T> static T* find(const Instance*); };
inline Workspace* Workspace::getWorkspaceIfInWorkspace(const Instance* context)
{
    Workspace* workspace = ServiceProvider::find<Workspace>(context);
    if (workspace && (context == workspace || context->isDescendentOf(workspace)))
        return workspace;
    else
        return 0;
}
bool Workspace::contextInWorkspace(const Instance* context)
{
    return getWorkspaceIfInWorkspace(context) != 0;
}
}
