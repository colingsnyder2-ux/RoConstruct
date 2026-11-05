// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espclaude_d38dadd676b0cd16.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Vector3.h"
#include "G3D/Ray.h"
#include "G3D/Array.h"
#include <vector>
#include <boost/weak_ptr.hpp>
namespace RBX {
class PartInstance;
class Primitive;
class ContactManager;
class UIEvent;
class ICameraOwner { public: virtual ~ICameraOwner(); };
class ExePad118 { public: virtual void exeV(); char pad[0x114]; };
class RootInstance : public ExePad118, public ICameraOwner { };
class World;
class DragUtilities {
public:
    static World* partsToPrimitives(const std::vector<boost::weak_ptr<PartInstance> >& parts, G3D::Array<Primitive*>& primitives);
    static bool hitObjectOrPlane(const ContactManager& contactManager, const G3D::Ray& unitSearchRay, const G3D::Array<Primitive*>* ignorePrims, G3D::Vector3& hit);
};
class MouseCommand {
public:
    static G3D::Ray getUnitMouseRay(const UIEvent& uiEvent, ICameraOwner* _workspace);
};
class MegaDragger {
public:
    G3D::Vector3 hitObjectOrPlane(const UIEvent& uiEvent);
    boost::weak_ptr<PartInstance> mousePart;
    std::vector<boost::weak_ptr<PartInstance> > dragParts;
    char pad18[0x8];
    RootInstance* rootInstance;
    ContactManager& contactManager;
};
G3D::Vector3 MegaDragger::hitObjectOrPlane(const UIEvent& uiEvent)
{
    G3D::Vector3 result;
    G3D::Array<Primitive*> primitives;
    DragUtilities::partsToPrimitives(dragParts, primitives);
    DragUtilities::hitObjectOrPlane(contactManager, MouseCommand::getUnitMouseRay(uiEvent, rootInstance), &primitives, result);
    return result;
}
}
