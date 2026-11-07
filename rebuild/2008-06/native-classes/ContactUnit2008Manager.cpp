// 2008-06 native rows of the original ContactManager unit (0060cae0..0060dd5f) that need no ContactManager, Primitive
// or World layout (inactive): getHit(Ray, vector*, ...) 0060db10, intersectingOthers(Array, float) 0060dc10 and
// intersectingOthers(Primitive*, float) 0060dcd0, plus the G3D::Array<Contact*> resize / append instances 0060cfd0 /
// 0060d0d0 (used there by onPrimitiveGeometryTypeChanged 0060d8e0, which needs the Primitive contact list and is
// not built), against native-headers/v8world/ContactManager2008.h. Verified by tests/record_native_contact_unit2008.py.
#include "v8world/ContactManager2008.h"

// G3D vendor template members the original emits in this unit (evidence names 0060cfd0 / 0060d0d0).
template void G3D::Array<RBX::Contact*>::resize(int, bool);
template void G3D::Array<RBX::Contact*>::append(RBX::Contact* const&);

namespace RBX
{
	// 0060db10
	Primitive* ContactManager::getHit(const G3D::Ray& worldRay, const std::vector<const Primitive*>* ignorePrim,
		const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const
	{
		G3D::Array<const Primitive*> tempIgnore;
		tempIgnore = *ignorePrim;
		return getHit(worldRay, &tempIgnore, filter, hitPoint, inside);
	}

	// 0060dc10
	bool ContactManager::intersectingOthers(const G3D::Array<Primitive*>& check, float overlapIgnored)
	{
		std::set<Primitive*> checkSet(check.begin(), check.end());
		for (int i = 0; i < check.size(); i++)
		{
			if (intersectingOthers(check[i], checkSet, overlapIgnored))
				return true;
		}
		return false;
	}

	// 0060dcd0
	bool ContactManager::intersectingOthers(Primitive* check, float overlapIgnored)
	{
		std::set<Primitive*> checkSet;
		checkSet.insert(check);
		return intersectingOthers(check, checkSet, overlapIgnored);
	}
}
