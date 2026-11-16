// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// Isolated World-dependent Humanoid provider using the existing 2008 pointer accessor.
#define NATIVE_HUMANOID2008_DONOR_CONNECTOR
#include "engine-world/v8world/World.h"
#include "humanoid/Humanoid2008.h"
namespace RBX {
ContactManager* Humanoid::getContactManager()
{
    return world ? &world->getContactManager() : NULL;
}
}
