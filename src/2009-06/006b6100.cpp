// from server: 100% by EspClaude
// roc 2009-06 006b6100  unit: RBX::MouseCommand::getUnitMouseRay
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; Vector3() {} };
class Ray { public: Vector3 origin; Vector3 direction; virtual ~Ray() {} };
}
namespace RBX {
class UIEvent;
class ICameraOwner { public: virtual void* getGCamera() = 0; };
class WorkspacePad { public: virtual ~WorkspacePad(); char pad[0x114]; };
class Workspace : public WorkspacePad, public ICameraOwner { public: virtual void* getGCamera(); };
class MouseCommand {
public:
    virtual ~MouseCommand();
    char pad[0x14];
    Workspace* workspace;  // 0x18
    static G3D::Ray getUnitMouseRay(const UIEvent& uiEvent, ICameraOwner* _workspace);
    G3D::Ray getUnitMouseRay(const UIEvent& uiEvent) const;
};
G3D::Ray MouseCommand::getUnitMouseRay(const UIEvent& uiEvent) const
{
    return getUnitMouseRay(uiEvent, workspace);
}
}
