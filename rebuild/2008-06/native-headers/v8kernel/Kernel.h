#pragma once
#include <g3d/array.h>
#include <boost/serialization/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>
#include "v8kernel/IStage.h"
#include "v8kernel/KernelData.h"
#include "util/Profiling.h"

namespace RBX {
class Kernel : public IStage {
	private:
		void matchDummy(); //hack, not in original src
		bool inStepCode;
		KernelData *kernelData;
		G3D::Array<RBX::Connector *> realTimeConnectors;
		int maxBodies;
		int maxPoints;
		int maxConnectors;
		static int numKernels;
	public:
		boost::scoped_ptr<RBX::Profiling::CodeProfiler> profilingKernel;
		Kernel(RBX::IStage* upstream);
		virtual ~Kernel();
		virtual StageType getStageType(){return KERNEL_STAGE;}
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);
		virtual Kernel* getKernel(){return this;};
		void insertBody(RBX::Body *b);
		inline void insertPoint(RBX::Point *p); //inlined out
		void insertConnector(RBX::Connector *c);
		void insertConnector2ndPass(RBX::Connector *c);
		void removeBody(Body *b);
		inline void removePoint(RBX::Point *p); //inlined out
		void removeConnector(RBX::Connector *c);
		void removeConnector2ndPass(RBX::Connector *c);
		Point* newPoint(Body* _body, const G3D::Vector3& worldPos);
		void deletePoint(RBX::Point* _point);
		void report(); //inlined or optimized out
		float connectorSpringEnergy() const;
		float bodyPotentialEnergy() const; //inlined or optimized out
		float bodyKineticEnergy() const;
		float totalKineticEnergy() const;
		int numBodies() const;
		int numPoints() const;
		int numConnectors() const;
};
}