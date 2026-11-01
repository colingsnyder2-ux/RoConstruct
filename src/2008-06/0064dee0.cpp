// from server: 100% by tester
namespace RBX {
class UIEvent;
class MouseCommand;

class Tool
{
public:
    void activate();
    void deactivate();
};

class ScriptMouseCommand
{
    char data[0x20];
public:
    virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
    virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
};

class ToolMouseCommand : public ScriptMouseCommand
{
    Tool* tool;
    void updateTargetPoint(const UIEvent& uiEvent);
public:
    virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
};

MouseCommand* ToolMouseCommand::onMouseDown(const UIEvent& uiEvent)
{
    updateTargetPoint(uiEvent);
    tool->activate();
    return ScriptMouseCommand::onMouseDown(uiEvent);
}
}
