// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Instance
{
    char padding[0x104];
    Instance* parent;
    const Instance* getParent() const { return parent; }
    Instance* getParent() { return parent; }
};
struct Workspace : Instance
{
    static Workspace* getMyWorkspaceFast(const Instance* context)
    {
        const Instance* workspace = context->getParent();
        const Instance* dataModel = workspace->getParent();
        while (dataModel->getParent() != 0) {
            workspace = dataModel;
            dataModel = dataModel->getParent();
        }
        return (Workspace*) workspace;
    }
};

Instance* __cdecl f(Instance* context)
{
    Workspace* workspace = Workspace::getMyWorkspaceFast(context);
    while (context->getParent() != workspace)
        context = context->getParent();
    return context;
}
