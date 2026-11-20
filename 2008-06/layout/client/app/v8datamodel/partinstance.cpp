#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "AppDraw/Draw.h"
#include "AppDraw/HitTest.h"
#include "tool/Dragger.h"
#include "util/Math.h"

// INFERRED: the shared native util/SurfaceType.h currently stops at GLUE = 4 (proposal sent to its owner: add
namespace
{
	const RBX::SurfaceType ROTATE = static_cast<RBX::SurfaceType>(6);
	const RBX::SurfaceType ROTATE_V = static_cast<RBX::SurfaceType>(7);
	const RBX::SurfaceType ROTATE_P = static_cast<RBX::SurfaceType>(8);
}

namespace RBX
{
	PartInstance::~PartInstance()
	{
	}

	Surfaces& PartInstance::getSurfaces()
	{
		return surfaces;
	}

	bool PartInstance::nonNullInWorkspace(boost::shared_ptr<PartInstance> part)
	{
		return part.get() && part->myWorld;
	}

	void PartInstance::destroyJoints()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world)
			world->destroyJoints(&primitive);
	}

	void PartInstance::join()
	{
		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world)
			world->createJoints(&primitive);
	}

	bool PartInstance::computeSurfacesNeedAdorn() const
	{
		for (int i = 0; i < 6; i++)
		{
			Surface& current = surfaces[(NormalId)i];
			if (current.getSurfaceType() == ROTATE || current.getSurfaceType() == ROTATE_P || current.getSurfaceType() == ROTATE_V)
				return true;
		}
		return false;
	}

	void PartInstance::legacyTraverseState(const G3D::CoordinateFrame& parentState)
	{
		G3D::CoordinateFrame myState = parentState * *legacyOffset;
		primitive.setGridCorner(myState);
	}

	bool PartInstance::isControllable() const
	{
		for (int i = 0; i < 6; i++)
		{
			Surface& current = surfaces[(NormalId)i];
			if ((current.getSurfaceType() == ROTATE_P || current.getSurfaceType() == ROTATE_V) && current.isControllable())
				return true;
		}
		return false;
	}

	void PartInstance::onSurfaceChanged(RBX::NormalId surfId)
	{
		PersistentPart.setDirty();
		IsControllable.setDirty();
		SurfacesNeedAdorn.setDirty();
		shouldRenderSetDirty();
	}

	void PartInstance::setPhysics(const G3D::CoordinateFrame& value)
	{
		if (value != getCoordinateFrame())
		{
			primitive.setCoordinateFrame(value);
			PersistentPart.setDirty();
			onExtentsChanged();
		}
	}

	const G3D::CoordinateFrame& PartInstance::getCoordinateFrame() const
	{
		return primitive.getCoordinateFrame();
	}

	const G3D::Vector3& PartInstance::getPartSizeXml() const
	{
		return primitive.getGeometry()->getGridSize();
	}

	G3D::Vector3 PartInstance::getPartSizeUi() const
	{
		return getPartSizeXml();
	}

	bool PartInstance::getDragging() const
	{
		return primitive.getDragging();
	}

	bool PartInstance::getAnchored() const
	{
		return primitive.getAnchor();
	}

	float PartInstance::getFriction() const
	{
		return primitive.getFriction();
	}

	float PartInstance::getElasticity() const
	{
		return primitive.getElasticity();
	}

	G3D::CoordinateFrame PartInstance::worldSnapLocation() const
	{
		G3D::Vector3 halfSize = getPartSizeXml() * 0.5f;

		G3D::Vector3 snapInPart;
		snapInPart.y = -halfSize.y;
		snapInPart.x = halfSize.x - G3D::iRound(floorf(halfSize.x));
		snapInPart.z = halfSize.z - G3D::iRound(floorf(halfSize.z));

		G3D::CoordinateFrame localSnapLocation(snapInPart);
		return primitive.getCoordinateFrame() * localSnapLocation;
	}

	bool PartInstance::aligned() const
	{
		G3D::CoordinateFrame myCoord = worldSnapLocation();
		G3D::CoordinateFrame myCoordSnapped = Math::snapToGrid(myCoord, Dragger::dragSnap());

		return Math::fuzzyEq(myCoord, myCoordSnapped, 0.00001, 0.00001);
	}

	Vector6<SurfaceType> Surfaces::surf6() const
	{
		Vector6<SurfaceType> answer;
		for (int i = 0; i < 6; i++)
			answer[i] = (*const_cast<Surfaces*>(this))[(NormalId)i].getSurfaceType();
		return answer;
	}

	Part PartInstance::computePersistentPart() const
	{
		const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
		float transparency = 1.0f - alpha();

		return Part(partType, getPartSizeXml(), G3D::Color4(getColor3(), transparency), surfaces.surf6(), cframe);
	}

	G3D::Vector3 PartInstance::uiToXmlSize(const G3D::Vector3& uiSize) const
	{
		G3D::Vector3 gridUiSize = Math::iRoundVector3(uiSize.max(G3D::Vector3(1.0f, 1.0f, 1.0f)));
		G3D::Vector3 xmlSize = gridUiSize;

		switch (formFactor)
		{
		case BRICK:
			xmlSize.y *= 1.2f;
			break;
		case PLATE:
			xmlSize.y *= 0.4f;
			break;
		}

		return xmlSize;
	}

	const Part& PartInstance::getPart() const
	{
		const Part& part = PersistentPart.getValueRef();
		part.coordinateFrame = primitive.getCoordinateFrame();
		return part;
	}

	const RBX::PartInstance* PartInstance::fromPrimitiveConst(const Primitive* p)
	{
		if (p)
			return static_cast<const PartInstance*>(p->getOwner());
		else
			return NULL;
	}

	bool PartInstance::getLocked(Instance* instance)
	{
		PartInstance* thisPart = dynamic_cast<PartInstance*>(instance);

		if (thisPart)
		{
			return thisPart->locked;
		}
		else
		{
			for (size_t i = 0; i < instance->numChildren(); i++)
			{
				if (getLocked(instance->getChild(i)))
					return true;
			}
			return false;
		}
	}

	void PartInstance::onParentControllerChanged()
	{
		PVInstance::onParentControllerChanged();
		PersistentPart.setDirty();
		primitive.setController(getTopPVController());
	}

	void PartInstance::onCanAggregateChanged(bool canAggregate)
	{
		Notifier<PartInstance, CanAggregateChanged>::raise(canAggregate);
		shouldRenderSetDirty();
	}

	void PartInstance::onAncestorChanged(const AncestorChanged& event)
	{
		Instance::onAncestorChanged(event);

		World* world = Workspace::getWorldIfInWorkspace(this);
		if (world != myWorld)
		{
			if (myWorld)
			{
				setMovingManager(NULL);
				myWorld->removePrimitive(&primitive);
			}

			myWorld = world;

			if (world)
			{
				world->insertPrimitive(&primitive);
				setMovingManager(Workspace::getMyWorkspaceFast(this));
				primitive.setController(getTopPVController());
			}
		}
	}

	void PartInstance::onChildAdded(Instance* child)
	{
		PVInstance::onChildAdded(child);
	}

	void PartInstance::render3dSelect(Adorn* adorn, SelectState selectState)
	{
		Draw::selectionBox(getPart(), adorn, selectState);
	}

	bool PartInstance::hitTest(const G3D::Ray& worldRay, G3D::Vector3& worldHitPoint)
	{
		const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
		G3D::Ray rayInPartCoords = cframe.toObjectSpace(worldRay);
		G3D::Vector3 hitPointInPartCoords;

		if (HitTest::hitTest(getPart(), rayInPartCoords, hitPointInPartCoords, 1.0f))
		{
			const G3D::CoordinateFrame& cframe = primitive.getCoordinateFrame();
			worldHitPoint = cframe.pointToWorldSpace(hitPointInPartCoords);
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PartInstance::reportTouches() const
	{
		return !event_Touched.empty(this);
	}
}

#include "Network/PhysicsSenders2008.h"
#include <boost/bind.hpp>

namespace
{
	typedef RBX::Network::PhysicsSender::PartItem SenderItem;
	typedef RBX::Network::PhysicsSender::PartItems SenderItems;
	typedef SenderItems::nth_index<1>::type SenderPriorityIndex;
	typedef boost::_bi::bind_t<void, void (*)(SenderItem&), boost::_bi::list1<boost::arg<1> > > SenderItemModifier;
}

template std::pair<SenderItems::final_node_type*, bool> SenderItems::insert_(const SenderItem& v);
template bool SenderItems::modify_<SenderItemModifier>(SenderItemModifier mod, SenderItems::final_node_type* x);
template SenderPriorityIndex::iterator SenderPriorityIndex::erase(SenderPriorityIndex::iterator position);

#include "reflection/property.h"
#include "G3D/CoordinateFrame.h"
#include "v8xml/XmlElement.h"

// INFERRED: 0059aeb0 builds each child in place (tag at +0x10, FLOAT 7 at +0x14, float at +0x18) with no call and no
inline XmlNameValuePair::XmlNameValuePair(const RBX::Name& tag, float value)
	: tag(tag),
	  valueType(FLOAT),
	  floatValue(value)
{
}

namespace RBX {
namespace Reflection {

template<>
void TypedPropertyDescriptor<G3D::CoordinateFrame>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
	if (!element->isXsiNil())
	{
		G3D::CoordinateFrame frame;
		float value;
		element->findFirstChildByTag(tag_X)->getValue(value);
		frame.translation.x = value;
		element->findFirstChildByTag(tag_Y)->getValue(value);
		frame.translation.y = value;
		element->findFirstChildByTag(tag_Z)->getValue(value);
		frame.translation.z = value;
		element->findFirstChildByTag(tag_R00)->getValue(value);
		frame.rotation[0][0] = value;
		element->findFirstChildByTag(tag_R01)->getValue(value);
		frame.rotation[0][1] = value;
		element->findFirstChildByTag(tag_R02)->getValue(value);
		frame.rotation[0][2] = value;
		element->findFirstChildByTag(tag_R10)->getValue(value);
		frame.rotation[1][0] = value;
		element->findFirstChildByTag(tag_R11)->getValue(value);
		frame.rotation[1][1] = value;
		element->findFirstChildByTag(tag_R12)->getValue(value);
		frame.rotation[1][2] = value;
		element->findFirstChildByTag(tag_R20)->getValue(value);
		frame.rotation[2][0] = value;
		element->findFirstChildByTag(tag_R21)->getValue(value);
		frame.rotation[2][1] = value;
		element->findFirstChildByTag(tag_R22)->getValue(value);
		frame.rotation[2][2] = value;
		getset->setValue(instance, frame);
	}
}

template<>
void TypedPropertyDescriptor<G3D::CoordinateFrame>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
	G3D::CoordinateFrame frame = getValue(instance);
	element->addChild(new XmlElement(tag_X, frame.translation.x));
	element->addChild(new XmlElement(tag_Y, frame.translation.y));
	element->addChild(new XmlElement(tag_Z, frame.translation.z));
	element->addChild(new XmlElement(tag_R00, frame.rotation[0][0]));
	element->addChild(new XmlElement(tag_R01, frame.rotation[0][1]));
	element->addChild(new XmlElement(tag_R02, frame.rotation[0][2]));
	element->addChild(new XmlElement(tag_R10, frame.rotation[1][0]));
	element->addChild(new XmlElement(tag_R11, frame.rotation[1][1]));
	element->addChild(new XmlElement(tag_R12, frame.rotation[1][2]));
	element->addChild(new XmlElement(tag_R20, frame.rotation[2][0]));
	element->addChild(new XmlElement(tag_R21, frame.rotation[2][1]));
	element->addChild(new XmlElement(tag_R22, frame.rotation[2][2]));
}

}
}

#undef _RELEASEASSERT
#include <G3D/AABox.h>
#include <G3D/CollisionDetection.h>

namespace RBX {
Surface* PartInstance::getSurface(const G3D::Ray& source, int& faceIndex)
{
    const G3D::CoordinateFrame& frame = primitive.getCoordinateFrame();
    G3D::Ray ray = frame.toObjectSpace(source);
    const G3D::Vector3& size = primitive.getGridSize();
    float x = size.x * 0.5f;
    float y = size.y * 0.5f;
    float z = size.z * 0.5f;
    Extents bounds(G3D::Vector3(-x, -y, -z), G3D::Vector3(x, y, z));
    const G3D::Vector3& low = bounds.min();
    const G3D::Vector3& high = bounds.max();
    G3D::Vector3 point(0.0f, 0.0f, 0.0f);
    G3D::CollisionDetection::collisionLocationForMovingPointFixedAABox(
        ray.origin, ray.direction, G3D::AABox(low, high), point);
    for (int i = 0; i < 3; ++i) {
        if (point[i] == high[i]) {
            faceIndex = i;
            return &surfaces[static_cast<NormalId>(i)];
        }
        if (point[i] == low[i]) {
            faceIndex = i + 3;
            return &surfaces[static_cast<NormalId>(i + 3)];
        }
    }
    return NULL;
}
}

namespace RBX {

void PartInstance::setLocked(Instance* object, bool value) {
	if (PartInstance* part = dynamic_cast<PartInstance*>(object)) {
		if (value != part->locked) {
			part->locked = value;
			part->raisePropertyChanged(prop_Locked);
		}
	} else {
		for (unsigned int i = 0; i < object->numChildren(); ++i)
			setLocked(object->getChild(i), value);
	}
}

}

#undef _RELEASEASSERT

namespace RBX {
bool PartInstance::lockedInPlace() const
{
    bool above = false, below = false;
    const Primitive* p = &primitive;
    Joint* joint = p->getFirstJoint();
    while (joint) {
        Edge* edge = joint;
        int type;
        if ((edge->getEdgeType() == Edge::JOINT &&
             ((type = joint->getJointType()) == Joint::WELD_JOINT || type == Joint::SNAP_JOINT)) ||
            (edge->getEdgeType() == Edge::JOINT && joint->getJointType() == Joint::MOTOR_JOINT)) {
            NormalId normal = p == edge->getPrimitive(0)
                ? Matrix3ToNormalId(joint->getJointCoord(0).rotation)
                : normalIdOpposite(Matrix3ToNormalId(joint->getJointCoord(1).rotation));
            if (normal == NORM_Y) above = true;
            else if (normal == NORM_Y_NEG) below = true;
        }
        joint = p->getNextJoint(joint);
    }
    return above && below;
}
}
