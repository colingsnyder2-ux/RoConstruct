// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Workspace;
class INamed { public: virtual void named(); };
class IAdornable { public: virtual void adorn(); };
class MouseCommand : public INamed, public IAdornable {
public:
    MouseCommand(Workspace* workspace);
    char pad[0x60 - 8];
};
class WeldTool : public MouseCommand {
public:
    WeldTool(Workspace* workspace) : MouseCommand(workspace) {}
    virtual void named();
    virtual void adorn();
};
class ToolVerb {
public:
    char pad[0x20];
    Workspace* workspace;
    MouseCommand* create();
};
MouseCommand* ToolVerb::create()
{
    return new WeldTool(workspace);
}
}
