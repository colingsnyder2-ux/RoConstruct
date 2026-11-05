// from server: 100% by EspClaude
// roc 2008-06 006444f0  unit: RBX::HUMAN::Climbing
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
#include <set>

namespace RBX {
class Primitive;
class ContactManager {
public:
    bool intersectingOthers(Primitive* p, const std::set<Primitive*>& ignore, float overlap);
};
class World {
public:
    char pad[0x84];
    ContactManager* contactManager;
    ContactManager* getContactManager() const { return contactManager; }
};
class Humanoid {
public:
    char pad[0x21c];
    World* world;
    World* getWorld() const { return world; }
    void getPrimitives(std::vector<Primitive*>& primitives);
    Primitive* getLeftArm();
    Primitive* getRightArm();
};
namespace HUMAN {
class Climbing {
public:
    void* vtbl;
    void* pad;
    Humanoid* humanoid;
    bool armsTouching();
};

bool Climbing::armsTouching()
{
    World* world = humanoid->getWorld();
    if (world)
    {
        std::vector<Primitive*> primitives;
        humanoid->getPrimitives(primitives);
        std::set<Primitive*> ignore(primitives.begin(), primitives.end());

        if (humanoid->getLeftArm() && world->getContactManager()->intersectingOthers(humanoid->getLeftArm(), ignore, 0.0f))
            return true;
        if (humanoid->getRightArm() && world->getContactManager()->intersectingOthers(humanoid->getRightArm(), ignore, 0.0f))
            return true;
    }
    return false;
}
}
}
