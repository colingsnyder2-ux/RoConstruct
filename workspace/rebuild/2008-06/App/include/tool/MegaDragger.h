#pragma once
#include <boost/weak_ptr.hpp>
#include <vector>
#include <G3D/Vector3.h>
#include <G3D/Matrix3.h>
#include "util/UIEvent.h"

namespace RBX
{
	class ContactManager;
	class PVInstance;
	class PartInstance;
	class RootInstance;

	class MegaDragger
	{
	private:
		boost::weak_ptr<PartInstance> mousePart;
		std::vector<boost::weak_ptr<PartInstance> > dragParts;
		bool joined;
		RootInstance* rootInstance;
		ContactManager& contactManager;
	public:
		MegaDragger(PartInstance*, const std::vector<boost::weak_ptr<PartInstance> >&, RootInstance*);
		MegaDragger(PartInstance*, const std::vector<PVInstance*>&, RootInstance*);
		~MegaDragger();
		void startDragging();
		void continueDragging();
		void finishDragging();
		bool mousePartAlive();
		bool anyDragPartAlive();
		void alignAndCleanParts();
		G3D::Vector3 hitObjectOrPlane(const UIEvent&);
		G3D::Vector3 safeMoveYDrop(const G3D::Vector3&);
		G3D::Vector3 safeMoveAlongLine(const G3D::Vector3&);
		G3D::Vector3 safeMoveNoDrop(const G3D::Vector3&);
		void safeRotate(const G3D::Matrix3&);
	};
}
