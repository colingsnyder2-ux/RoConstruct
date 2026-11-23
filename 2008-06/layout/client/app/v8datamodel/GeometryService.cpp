// =============================================================================
// GeometryService.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/GeometryService.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/GeometryService.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8datamodel/Filters2008.h"
#include <vector>

namespace RBX
{
	char sGeometryService[] = "Geometry"; // 0095c530 (.data; doDeclare 005bfa30, classDescriptor 005c0470, ctor 0062def7)

	// Template members the shared headers only declare (same definitions as DebrisService.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	GeometryService::GeometryService()
		: Base(static_cast<const char*>(sGeometryService)),
		  workspace(NULL)
	{
	}

	void GeometryService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (newProvider)
			workspace = newProvider->create<Workspace>();
	}

	void GeometryService::getPartsTouchingExtents(const Extents& extents, const Primitive* ignore, G3D::Array<PartInstance*>& result)
	{
		if (workspace)
		{
			ContactManager& contactManager = workspace->getWorld()->getContactManager();
			primitives.fastClear();
			contactManager.getPrimitivesTouchingExtents(extents, ignore, primitives);
			for (int i = 0; i < primitives.size(); ++i)
				result.append(PartInstance::fromPrimitive(primitives[i]));
		}
	}

	G3D::Vector3 GeometryService::getHitLocationFilterStairs(Instance* filterModel, G3D::Ray ray)
	{
		if (!workspace)
			return G3D::Vector3::ZERO;

		FilterStairs filter(filterModel);
		ContactManager& contactManager = workspace->getWorld()->getContactManager();
		G3D::Vector3 hitPoint(0.0f, 0.0f, 0.0f);
		std::vector<const Primitive*> ignore;
		Primitive* hit = contactManager.getHit(ray, &ignore, &filter, hitPoint);
		if (!hit)
			hitPoint = ray.unit().origin + ray.direction;

		return hitPoint;
	}
}

template void RBX::Name::callDoDeclare<RBX::sGeometryService>();
