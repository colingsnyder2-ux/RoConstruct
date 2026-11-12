// 2008-06 native RBX::Cofm (inactive): the Cofm unit rows 0065fef0..0066017c against native-headers/v8kernel/Body2008.h.
// Verified by tests/record_native_body_primitive2008.py.
#include "v8kernel/Body2008.h"

namespace RBX
{
	// 0065fef0
	Cofm::Cofm(Body* body)
		: body(body),
		  dirty(true),
		  cofmInBody(G3D::Vector3(0.0f, 0.0f, 0.0f))
	{
	}

	// 0065ff10
	const float Cofm::getMass() const
	{
		updateIfDirty();
		return mass;
	}

	// 0065ff20
	void Cofm::updateIfDirty() const
	{
		if (dirty)
		{
			mass = body->getMass();
			float bodyMass = body->getMass();
			G3D::Vector3 point = body->getPV().position.translation * bodyMass;
			for (int i = 0; i < body->numChildren(); i++)
			{
				Body* child = body->getChild(i);
				mass = mass + child->getBranchMass();
				point += child->getBranchCofmPos() * child->getBranchMass();
			}
			point = point / mass;
			const PV& bodyPV = body->getPV();
			cofmInBody = (point - bodyPV.position.translation) * bodyPV.position.rotation;
			G3D::Matrix3 IWorld = body->getIWorldAtPoint(point);
			for (int i = 0; i < body->numChildren(); i++)
				IWorld = IWorld + body->getChild(i)->getBranchIWorldAtPoint(point);
			moment = Math::momentToObjectSpace(IWorld, body->getPV().position.rotation);
			dirty = false;
		}
	}

	// 00660160
	const G3D::Vector3& Cofm::getCofmInBody() const
	{
		updateIfDirty();
		return cofmInBody;
	}

	// 00660170
	const G3D::Matrix3& Cofm::getMoment() const
	{
		updateIfDirty();
		return moment;
	}
}
