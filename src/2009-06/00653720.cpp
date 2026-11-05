// from server: 100% by EspClaude
// roc 2009-06 00653720
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Workspace;
class MouseCommand { public: virtual ~MouseCommand(); };
class ArrowCommand : public MouseCommand {
public:
    ArrowCommand(Workspace* workspace);
    char data[0x4c - 4];
};
class ArrowTool {
public:
    virtual MouseCommand* newMouseCommand();
    char pad[0x14];
    Workspace* workspace;
};
MouseCommand* ArrowTool::newMouseCommand()
{
    return new ArrowCommand(workspace);
}
}
