#pragma once
#include "v8tree/Instance.h"
#include "util/IRenderable.h"
namespace RBX {
extern char sForceField[];
// Allocation 005c1520 = 0x148; constructor 0062d6b0 proves members.
class ForceField : public DescribedCreatable<ForceField, Instance, sForceField>, public IRenderable {
public:
 bool field_140;
 int field_144;
 ForceField();
 virtual ~ForceField();
 virtual bool askAddChild(const Instance*) const { return false; }
 virtual bool askSetParent(const Instance*) const;
 virtual bool shouldRender3dAdorn() const { return true; }
 virtual void render3dAdorn(Adorn*);
};
}
