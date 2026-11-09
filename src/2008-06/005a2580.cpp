// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a34b51fb93b16b65.cpp

// Candidate translation unit (score above; library headers required).
#define _DLL
#include <boost/shared_ptr.hpp>
#include <G3D/Array.h>
namespace RBX {
class Primitive;
class PhysicsSettings {
public:
    char pad[0x13a];
    bool flag;
    static PhysicsSettings& singleton();
};
class World {
public:
    char pad[0x8c];
    G3D::Array<Primitive*> touch;
    G3D::Array<Primitive*> touchOther;
    float step(float timeInterval, int n, bool flag);
    const G3D::Array<Primitive*>& getTouch() const { return touch; }
    const G3D::Array<Primitive*>& getTouchOther() const { return touchOther; }
    void computeFallen(G3D::Array<Primitive*>& fallen);
};
class PartInstance {
public:
    static void primitivesToParts(const G3D::Array<Primitive*>& primitives, G3D::Array<boost::shared_ptr<PartInstance> >& parts);
    void onTouchThisStep(boost::shared_ptr<PartInstance> other);
};
struct DrawChanged {};
class DrawNotifier {
public:
    void raise(DrawChanged event);
};
class Workspace {
public:
    char pad[0x2e4];
    boost::shared_ptr<World> world;
    char pad2[0x344 - 0x2ec];
    DrawNotifier drawNotifier;
    float step(float timeInterval, int n);
    void handleFallenParts(G3D::Array<boost::shared_ptr<PartInstance> >& parts);
    void raiseDrawChanged() { drawNotifier.raise(DrawChanged()); }
};
float Workspace::step(float timeInterval, int n)
{
    timeInterval = world->step(timeInterval, n, PhysicsSettings::singleton().flag);

    G3D::Array<boost::shared_ptr<PartInstance> > touchParts;
    G3D::Array<boost::shared_ptr<PartInstance> > touchOtherParts;
    G3D::Array<Primitive*> fallen;
    G3D::Array<boost::shared_ptr<PartInstance> > fallenParts;

    PartInstance::primitivesToParts(world->getTouch(), touchParts);
    PartInstance::primitivesToParts(world->getTouchOther(), touchOtherParts);
    world->computeFallen(fallen);
    PartInstance::primitivesToParts(fallen, fallenParts);

    handleFallenParts(fallenParts);

    for (int i = 0; i < touchParts.size(); i++)
    {
        touchParts[i]->onTouchThisStep(touchOtherParts[i]);
    }

    raiseDrawChanged();
    return timeInterval;
}
}
