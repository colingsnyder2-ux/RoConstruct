// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    T* operator->() const { return px; }
};
}
namespace RBX {
class UIEvent;
class Tool { public: void activate(); void deactivate(); };
class MouseCommand {
public:
    virtual ~MouseCommand();
    virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
    virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
};
class ScriptMouseCommand : public MouseCommand {
public:
    char pad[0x24 - 4];
    virtual MouseCommand* onMouseDown(const UIEvent& uiEvent);
    virtual MouseCommand* onMouseUp(const UIEvent& uiEvent);
};
class ToolMouseCommand : public ScriptMouseCommand {
    boost::shared_ptr<Tool> tool;
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
