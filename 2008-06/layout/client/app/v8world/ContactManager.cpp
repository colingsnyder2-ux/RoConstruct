#include <algorithm>
#include "v8world/ContactManager2008.h"
#include "v8world/Contact2008.h"
#include "leaves2008/BlockBlockContact2008.h"
#include "v8world/Geometry2008.h"
#include "v8world/Primitive2008.h"

#include "v8world/World2008.h"

#include "v8world/SpatialHash2008.h"

template void G3D::Array<RBX::Contact*>::resize(int, bool);
template void G3D::Array<RBX::Contact*>::append(RBX::Contact* const&);

namespace RBX
{
	void ContactManager::onPrimitiveExtentsChanged(Primitive* p)
	{
		spatialHash->onPrimitiveExtentsChanged(p);
	}

	bool ContactManager::intersectingOthers(Primitive* check, const std::set<Primitive*>& checkSet, float overlapIgnored)
	{
		for (Contact* cur = check->getFirstContact(); cur != NULL; cur = check->getNextContact(cur))
		{
			if (checkSet.find(cur->otherPrimitive(check)) == checkSet.end() && cur->computeIsColliding(overlapIgnored))
				return true;
		}
		return false;
	}

	Contact* ContactManager::createContact(Primitive* p0, Primitive* p1)
	{
		Geometry::GeometryType type0 = p0->getGeometry()->getGeometryType();
		Geometry::GeometryType type1 = p1->getGeometry()->getGeometryType();

		if (type0 > type1)
			std::swap(p0, p1);

		type0 = p0->getGeometry()->getGeometryType();
		type1 = p1->getGeometry()->getGeometryType();

		switch (type0)
		{
		case Geometry::GEOMETRY_BALL:
			switch (type1)
			{
			case Geometry::GEOMETRY_BALL:
				return new BallBallContact(p0, p1);
			case Geometry::GEOMETRY_BLOCK:
				return new BallBlockContact(p0, p1);
			}
		case Geometry::GEOMETRY_BLOCK:
			return new BlockBlockContact(p0, p1);
		default:
			return NULL;
		}
	}

	Primitive* ContactManager::getHit(const G3D::Ray& worldRay, const G3D::Array<const Primitive*>* ignorePrim,
		const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const
	{
		world->update();

		bool stopped;
		Primitive* fastHit = getFastHit(worldRay, ignorePrim, filter, hitPoint, inside, stopped);

		if (stopped)
			fastHit = NULL;

		if (!fastHit)
		{
			hitPoint = G3D::Vector3::zero();
			inside = false;
		}
		return fastHit;
	}

	void ContactManager::onNewPair(Primitive* p0, Primitive* p1)
	{
		Contact* contact = createContact(p0, p1);
		world->insertContact(contact);
	}

	void ContactManager::onPrimitiveGeometryTypeChanged(Primitive* p)
	{
		G3D::Array<Contact*> newContacts;

		for (Contact* cur = p->getFirstContact(); cur != NULL; cur = p->getFirstContact())
		{
			newContacts.push_back(createContact(cur->getPrimitive(0), cur->getPrimitive(1)));
			world->destroyContact(cur);
		}

		for (int i = 0; i < newContacts.size(); i++)
			world->insertContact(newContacts[i]);
	}

	Primitive* ContactManager::getHit(const G3D::Ray& worldRay, const std::vector<const Primitive*>* ignorePrim,
		const HitTestFilter* filter, G3D::Vector3& hitPoint, bool& inside) const
	{
		G3D::Array<const Primitive*> tempIgnore;
		tempIgnore = *ignorePrim;
		return getHit(worldRay, &tempIgnore, filter, hitPoint, inside);
	}

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

	bool ContactManager::intersectingOthers(Primitive* check, float overlapIgnored)
	{
		std::set<Primitive*> checkSet;
		checkSet.insert(check);
		return intersectingOthers(check, checkSet, overlapIgnored);
	}
}

template class G3D::Array<RBX::Contact *>;
template class G3D::Array<RBX::Primitive const *>;
template class std::_Tree<std::_Tset_traits<RBX::Primitive *,std::less<RBX::Primitive *>,std::allocator<RBX::Primitive *>,0> >;
template class std::allocator<RBX::Primitive *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::Primitive *,std::less<RBX::Primitive *>,std::allocator<RBX::Primitive *>,0> >::_Node *>;
