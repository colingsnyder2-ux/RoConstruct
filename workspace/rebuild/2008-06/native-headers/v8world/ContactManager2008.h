#pragma once
// >>> native-status (generated) -- do not edit >>>
// ContactManager2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 2bfd55aa | roc native-status --write
// 2008-06 native RBX::ContactManager (inactive), declared by members whose evidence is a call or an evidence name and by
// its two leading fields; the members after +0x8 are not declared, so this class must not be used for new or sizeof. Declared under a
// non-colliding name: the original path v8world/ContactManager.h is the donor header (reached by World.h, Dragger.h,
// MouseCommand.h ...); a unit must not include both this header and the donor v8world/ContactManager.h.
// Evidence (2008-06 binary, ContactManager unit 0060cae0..0060dd5f):
//   names    getHit(Ray, const Array<const Primitive*>*, ...) 0060d6e0, getHit(Ray, const vector<const Primitive*>*, ...)
//            0060db10, intersectingOthers(Primitive*, const set<Primitive*>&, float) 0060d630, intersectingOthers(const
//            Array<Primitive*>&, float) 0060dc10, intersectingOthers(Primitive*, float) 0060dcd0, createContact 0060d770,
//            onNewPair 0060d8b0, onPrimitiveGeometryTypeChanged 0060d8e0 (evidence names of offline/evidence.json).
//   getHit   0060db10 copies *ignorePrim into a local G3D::Array<const Primitive*> (operator=(vector) 0060d200) and
//            calls getHit 0060d6e0 with it (`ret 0x14`: the bool& argument is explicit).
//   create   createContact 0060d770 (private: `?createContact@ContactManager@RBX@@AAEPAVContact@2@PAVPrimitive@2@0@Z`) orders
//            the pair by Geometry::getGeometryType (slot 2 of the geometry at Primitive +0x9c) and news BallBallContact
//            (0x38, 0060cae0), BallBlockContact (0x38, 0060cb90) or BlockBlockContact (0x7c, 0060d500).
//   fields   spatialHash +0x0: ~ContactManager 0060ccf0 deletes it (~SpatialHash 0065b1b0, then operator delete).
//            world +0x4: onNewPair 0060d8c4 / onPrimitiveGeometryTypeChanged 0060d991 pass it to World::insertContact
//            005e9260 / destroyContact 005e9280, getHit 0060d6e4 to World 005e9520. World::getContactManager 005e6110
//            returns the ContactManager pointer at World +0x40.
//            +0x8: a G3D::Array that ~ContactManager 0060ccf0 frees (alignedFree 00507d20, then +0x8 / +0xc / +0x10 = 0);
//            its element type and the size of ContactManager are not proven here, so nothing after +0x8 is declared.
//   pending  onNewPair 0060d8b0, onPrimitiveGeometryTypeChanged 0060d8e0 and getHit(Array) 0060d6e0 call World members
//            that no native header declares; they are built by tests/record_native_contact_unit2008.py against a
//            generated World declaration only (pending-build-only rows, see its proposals).
#include <set>
#include <vector>
#include <G3D/Vector3.h>
#include <G3D/Ray.h>
#include <G3D/Array.h>
#include "util/HitTestFilter.h"

struct NativeContactUnit2008Layout;

namespace RBX
{
	class Contact;
	class Primitive;
	class SpatialHash;
	class World;

	class ContactManager
	{
		friend struct ::NativeContactUnit2008Layout;

	private:
		SpatialHash* spatialHash;                                                              // +0x0
		World* world;                                                                          // +0x4

	private:
		Contact* createContact(Primitive* p0, Primitive* p1);                                  // 0060d770 (evidence name)
		Primitive* getFastHit(const G3D::Ray& worldRay, const G3D::Array<const Primitive*>* ignorePrim,
			const HitTestFilter* filter, G3D::Vector3& hitPointWorld, bool& inside, bool& stopped) const;   // 0060d2d0

	public:
		Primitive* getHit(const G3D::Ray& worldRay, const std::vector<const Primitive*>* ignorePrim,
			const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const;          // 0060db10
		Primitive* getHit(const G3D::Ray& worldRay, const G3D::Array<const Primitive*>* ignorePrim,
			const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const;          // 0060d6e0
		bool intersectingOthers(Primitive* check, const std::set<Primitive*>& checkSet, float overlapIgnored);   // 0060d630
		bool intersectingOthers(const G3D::Array<Primitive*>& check, float overlapIgnored);   // 0060dc10
		bool intersectingOthers(Primitive* check, float overlapIgnored);                      // 0060dcd0
		void onNewPair(Primitive* p0, Primitive* p1);                                         // 0060d8b0 (evidence name)
		void onPrimitiveGeometryTypeChanged(Primitive* p);                                    // 0060d8e0 (evidence name)
	};
}
