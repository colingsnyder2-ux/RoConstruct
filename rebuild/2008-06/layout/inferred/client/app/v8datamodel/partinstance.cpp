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

}
}

#undef _RELEASEASSERT
#include "v8datamodel/PartInstance.h"
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
