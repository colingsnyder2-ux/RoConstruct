// =============================================================================
// Kernel.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8kernel/Kernel.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include <g3d/array.h>
#include <boost/serialization/scoped_ptr.hpp>
#include <boost/noncopyable.hpp>
#include "v8kernel/IStage.h"
#include "v8kernel/KernelData.h"
#include "util/Profiling.h"

namespace RBX
{
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
