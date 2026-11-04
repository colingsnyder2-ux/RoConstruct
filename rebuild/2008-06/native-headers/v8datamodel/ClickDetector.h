#pragma once
#include "v8tree/Instance.h"
#include "util/IRenderable.h"
namespace RBX {
extern char sClickDetector[];
// First draft: 005c0b7f allocation 0x14c; 006297e0 constructor.
class ClickDetector : public DescribedCreatable<ClickDetector, Instance, sClickDetector>, public IRenderable {
public:
 int field_140;
 float maxActivationDistance;
 static Reflection::BoundProp<float, 1> prop_MaxActivationDistance;
 // Allocation proves four remaining bytes; member identity/lifetime unresolved.
 unsigned char field_148[4];
 ClickDetector();
 virtual ~ClickDetector();
 virtual bool askSetParent(const Instance*) const;
 virtual bool shouldRender2d() const;
 virtual bool shouldRender3dAdorn() const;
};
}
