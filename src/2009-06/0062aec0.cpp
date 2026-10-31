// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Workspace;
class MouseCommand {
public:
    virtual ~MouseCommand();
    char pad[0x44];
};
class NullTool : public MouseCommand {
public:
    NullTool(Workspace* workspace);
};
MouseCommand* newNullTool(Workspace* workspace)
{
    return new NullTool(workspace);
}
}
