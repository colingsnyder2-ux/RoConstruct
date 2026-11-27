// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace RBX {
class Workspace;
class MouseCommand {
public:
    char data[0x68];
    MouseCommand(Workspace* workspace);
};
class NewNullTool : public MouseCommand {
public:
    NewNullTool(Workspace* workspace);
};
MouseCommand* newNullTool(Workspace* workspace)
{
    return new NewNullTool(workspace);
}
}