#pragma once
#include "v8world/Joint.h"
#include "v8kernel/Connector.h"
#include "v8kernel/Point.h"
#include "v8kernel/Kernel.h"

namespace RBX
{
	class MultiJoint : public Joint
	{
	private:
		int numConnector;
		Point* point[8];
		Connector* connector[4];
		int numBreakingConnectors;
	  
	private:
		bool pointsAligned() const;
		void init(int);
	protected:
		virtual void putInKernel(Kernel*);
		virtual void removeFromKernel();
		virtual bool isBroken() const;
		void addToMultiJoint(Point*, Point*, Connector*);
		Point* getPoint(int);
		Connector* getConnector(int);
		float getJointK();
	public:
		//MultiJoint(const MultiJoint&);
	protected:
		MultiJoint(Primitive* p0, Primitive* p1, const G3D::CoordinateFrame& jointCoord0, const G3D::CoordinateFrame& jointCoord1, int numBreaking);
		MultiJoint(int numBreaking);
		virtual ~MultiJoint();
	public:
		//MultiJoint& operator=(const MultiJoint&);
	};
}