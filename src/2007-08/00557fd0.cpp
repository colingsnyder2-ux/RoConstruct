// from server: 100% by EspClaude
// roc 2007-08 00557fd0  RBX::DataModel::processGui (2007 layout, self-contained stand-ins)
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
namespace G3D {
class Vector2int16 { public: short x, y; };
class Vector2 { public: float x, y;
  Vector2(const Vector2int16& v) : x(v.x), y(v.y) {}
  Vector2& operator=(const Vector2& o) { x = o.x; y = o.y; return *this; } };
}

namespace RBX {
class UIEvent {
public:
    int eventType;
    int a;
    int b;
    G3D::Vector2int16 mousePosition;
    bool isMouseEvent() const
    {
        return eventType == 1 || eventType == 2 || eventType == 3
            || eventType == 4 || eventType == 5 || eventType == 6;
    }
};
class GuiRoot;
class GuiEvent : public UIEvent {
public:
    GuiRoot* root;
    GuiEvent(const UIEvent& e, GuiRoot* r) : UIEvent(e), root(r) {}
};
class GuiTarget;
class GuiResponse {
public:
    int used;
    GuiTarget* target;
    GuiResponse() : used(0), target(0) {}
    bool wasUsed() const { return used != 0; }
};
class GuiTarget {
public:
    virtual GuiResponse process(const GuiEvent& event) = 0;
};
class GuiPad { public: virtual ~GuiPad(); char pad[0xe4]; };
class GuiItem : public GuiPad, public GuiTarget {};
class WorkspacePad { public: virtual ~WorkspacePad(); char pad[0x27c]; };
class Workspace : public WorkspacePad, public GuiTarget {};
class RootPad { public: virtual ~RootPad(); };
class GuiRoot { public: int x; };
class DataModelPad { public: char pad[0x160]; };

extern G3D::Vector2 lastMousePosition;
void updateMouse(class DataModel* dataModel);

class DataModel : public DataModelPad, public GuiRoot {
public:
    char pad1[0x1c];
    GuiItem* gui3;
    char pad2[4];
    Workspace* workspace;
    char pad3[0x14];
    GuiItem* gui2;
    char pad4[4];
    GuiItem* gui1;
    char pad5[4];
    GuiTarget* guiTarget;
    bool guiTargetNotWorkspace;
    GuiResponse processAccelerators(const GuiEvent& event);
    void processGui(const UIEvent& event);
};

void DataModel::processGui(const UIEvent& event)
{
    if (event.isMouseEvent()) {
        lastMousePosition = G3D::Vector2(event.mousePosition);
    }
    GuiEvent guiEvent(event, this);
    GuiResponse response = guiTarget ? guiTarget->process(guiEvent) : GuiResponse();
    if (!response.wasUsed())
        response = gui1->process(guiEvent);
    if (!response.wasUsed())
        response = gui2->process(guiEvent);
    if (!response.wasUsed())
        response = gui3->process(guiEvent);
    if (!response.wasUsed())
        response = processAccelerators(guiEvent);
    guiTargetNotWorkspace = response.wasUsed() && guiTarget != workspace;
    if (!response.wasUsed())
        response = workspace->process(guiEvent);
    if (event.isMouseEvent() || event.eventType == 9)
        updateMouse(this);
    guiTarget = response.target;
}
}
