#pragma once
// Overlay for RBX::FilterStairs used by tests/record_native_geometry_service.py for the NATIVE_GEOMETRYSERVICE_PENDING
// build (copied as out/native-layouts/geometry-service-pending/v8datamodel/FilterStairs.h); not a shared header.
// Read from the 2008-06 binary: RTTI .?AVFilterStairs@RBX@@, vtable 0084c46c (one slot, filterResult 00660320, the
// HitTestFilter interface); the constructor 006604a0 takes an Instance*, stores the vtable, zeroes and then assigns
// the shared_ptr at +4/+8 from shared_from<Instance> (00618a40). GeometryService 0062dc10 destroys it inline (only
// the shared_ptr release, no vtable store).
#include "util/HitTestFilter.h"
#include "v8tree/Instance.h"
#include <boost/shared_ptr.hpp>

namespace RBX
{
	class FilterStairs : public HitTestFilter
	{
	private:
		boost::shared_ptr<Instance> model;   // +4 (px), +8 (pn)

	public:
		FilterStairs(Instance* model);       // 006604a0
		virtual HitTestFilter::Result filterResult(const Primitive* testMe) const;   // 00660320
	};
}
