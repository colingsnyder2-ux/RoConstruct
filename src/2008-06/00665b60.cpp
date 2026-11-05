// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; };
class Ray {
public:
    Vector3 origin;
    Vector3 direction;
    virtual ~Ray() {}
};
}
namespace RBX {
class UIEvent;
class MegaDragger {
public:
    bool mousePartAlive();
    void continueDragging();
};
class RunDragger {
public:
    void snap(const G3D::Ray& ray);
};
class MouseCommand {
public:
    virtual ~MouseCommand();
    char pad04[0x10];
    bool isCaptured;            // 0x14
    char pad15[0x7];
    RunDragger* runDragger;     // 0x1c
    MegaDragger* megaDragger;   // 0x20
    char pad24[0x10];
    bool dragging;              // 0x34
    bool captured() const { return isCaptured; }
    G3D::Ray getUnitMouseRay(const UIEvent& uiEvent);
};
class PartDragTool : public MouseCommand {
public:
    virtual void onMouseIdle(const UIEvent& uiEvent);
};
void PartDragTool::onMouseIdle(const UIEvent& uiEvent)
{
    if (captured() && dragging && megaDragger->mousePartAlive())
    {
        megaDragger->continueDragging();
        runDragger->snap(getUnitMouseRay(uiEvent));
    }
}
}
