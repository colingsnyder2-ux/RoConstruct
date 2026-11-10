#pragma once
// Declaration-only overlay for RBX::Workspace used by tests/record_native_geometry_service.py for the
// NATIVE_GEOMETRYSERVICE_PENDING build (copied as out/native-layouts/geometry-service-pending/v8datamodel/Workspace.h);
// not a shared header. The donor Workspace.h does not compile against the 2008 reflection.h. GeometryService needs the
// World of a Workspace: the original loads it inline from Workspace +0x2e4 (0062db6d, 0062dc81), which only a native
// Workspace layout can provide, so this overlay declares getWorld() out of line (the pending rows stay non-exact).
// No member or layout is claimed here.
#include "v8tree/Instance.h"

namespace RBX
{
	class World;

	class Workspace : public Instance
	{
	private:
		Workspace();

	public:
		World* getWorld() const;   // proposal: inline `return world;` with World* world at +0x2e4
	};
}
