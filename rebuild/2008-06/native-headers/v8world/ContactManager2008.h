#pragma once
// 2008-06 native RBX::ContactManager (inactive), declared only by members whose evidence is a call or an evidence
// name: no field is declared, so this class must not be used for new, sizeof or member access. Declared under a
// non-colliding name: the original path v8world/ContactManager.h is the donor header (reached by World.h, Dragger.h,
// MouseCommand.h ...); a unit must not include both this header and the donor v8world/ContactManager.h.
// Evidence (2008-06 binary, ContactManager unit 0060cae0..0060dd5f):
//   names    getHit(Ray, const Array<const Primitive*>*, ...) 0060d6e0, getHit(Ray, const vector<const Primitive*>*, ...)
//            0060db10, intersectingOthers(Primitive*, const set<Primitive*>&, float) 0060d630, intersectingOthers(const
//            Array<Primitive*>&, float) 0060dc10, intersectingOthers(Primitive*, float) 0060dcd0, createContact 0060d770,
//            onNewPair 0060d8b0, onPrimitiveGeometryTypeChanged 0060d8e0 (evidence names of offline/evidence.json).
//   getHit   0060db10 copies *ignorePrim into a local G3D::Array<const Primitive*> (operator=(vector) 0060d200) and
//            calls getHit 0060d6e0 with it (`ret 0x14`: the bool& argument is explicit).
//   fields   onNewPair 0060d8c4 reads a World* at +0x4 (World::insertContact 005e9260) and World::getContactManager
//            005e6110 returns the ContactManager at World +0x40; the size of ContactManager is not proven here, so no
//            field is declared.
#include <set>
#include <vector>
#include <G3D/Vector3.h>
#include <G3D/Ray.h>
#include <G3D/Array.h>
#include "util/HitTestFilter.h"

namespace RBX
{
	class Contact;
	class Primitive;

	class ContactManager
	{
	public:
		Primitive* getHit(const G3D::Ray& worldRay, const std::vector<const Primitive*>* ignorePrim,
			const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const;          // 0060db10
		Primitive* getHit(const G3D::Ray& worldRay, const G3D::Array<const Primitive*>* ignorePrim,
			const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const;          // 0060d6e0
		bool intersectingOthers(Primitive* check, const std::set<Primitive*>& checkSet, float overlapIgnored);   // 0060d630
		bool intersectingOthers(const G3D::Array<Primitive*>& check, float overlapIgnored);   // 0060dc10
		bool intersectingOthers(Primitive* check, float overlapIgnored);                      // 0060dcd0
	};
}
