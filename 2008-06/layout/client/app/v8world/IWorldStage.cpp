// =============================================================================
// IWorldStage.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8world/IWorldStage.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8world/IWorldStage.h"

namespace RBX
{
	int IWorldStage::getMetric(MetricType metricType)
	{
		return getDownstreamWS()->getMetric(metricType);
	}
}

#include "v8world/ClumpStage2008.h"
#include "v8world/Joints2008.h"

namespace RBX
{
	void ClumpStage::onEdgeAdded(Edge* e)
	{
		IWorldStage::onEdgeAdded(e);
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* joint = static_cast<Joint*>(e);
			Edge* entry = e;
			if (joint->canStepUi())
				set10.insert(entry);
		}
	}

	void ClumpStage::onEdgeRemoving(Edge* e)
	{
		if (e->getEdgeType() == Edge::JOINT)
		{
			Joint* joint = static_cast<Joint*>(e);
			Edge* entry = e;
			if (joint->canStepUi())
				set10.erase(entry);
		}
		IWorldStage::onEdgeRemoving(e);
	}
}
