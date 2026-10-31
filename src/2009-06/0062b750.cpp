// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <memory>
namespace RBX {
class MouseCommand { public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual ~MouseCommand(); };
class Workspace {
public:
    void setNullMouseCommand();
    char pad[0x1d8];
    std::auto_ptr<MouseCommand> currentCommand;
    std::auto_ptr<MouseCommand> stickyCommand;
};
MouseCommand* newNullTool(Workspace* workspace);
void Workspace::setNullMouseCommand()
{
    stickyCommand.reset();
    currentCommand.reset(newNullTool(this));
}
}
