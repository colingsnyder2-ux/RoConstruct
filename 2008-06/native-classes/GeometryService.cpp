// 2008-06 native RBX::GeometryService (inactive); evidence in native-headers/v8datamodel/GeometryService.h.
// Verified by tests/record_native_geometry_service.py. Unit 0062d8f0..0062e070 plus class descriptor 005c0470 and
// doDeclare 005bfa30 / callDoDeclare 005bffc0. getPartsTouchingExtents 0062db60 and getHitLocationFilterStairs
// 0062dc10 read the Workspace world (+0x2e4), which no native header declares yet, so they compile only under
// NATIVE_GEOMETRYSERVICE_PENDING against the generated overlay of tests/NativeGeometryServicePendingWorkspace.h
// (proposal in the recorder). 0062dc10 also constructs RBX::FilterStairs, declared by the native
// v8datamodel/Filters2008.h (tests/record_native_hit_filters.py).
// >>> native-status (generated) -- do not edit >>>
// GeometryService | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src f1ef3c80 | roc native-status --write
#include "v8datamodel/GeometryService.h"
#ifdef NATIVE_GEOMETRYSERVICE_PENDING
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Filters2008.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include <vector>
#endif

namespace RBX
{
	char sGeometryService[] = "Geometry"; // 0095c530 (.data; doDeclare 005bfa30, classDescriptor 005c0470, ctor 0062def7)

	// Template members the shared headers only declare (same definitions as DebrisService.cpp).
	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	template<typename Arg0Type>
	DescribedCreatable<C, D, N>::DescribedCreatable(Arg0Type arg0)   // 0062ddc0
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >(arg0) {}

	// 0062dee0: the class-name array itself is the Instance name (push 0095c530), passed as const char*
	// (DescribedCreatable<..>::DescribedCreatable<const char*> 0062ddc0).
	GeometryService::GeometryService()
		: Base(static_cast<const char*>(sGeometryService)),
		  workspace(NULL)
	{
	}

	// 0062dda0: no Instance::onServiceProvider call; workspace is kept when newProvider is NULL.
	void GeometryService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
	{
		if (newProvider)
			workspace = newProvider->create<Workspace>();
	}

#ifdef NATIVE_GEOMETRYSERVICE_PENDING
	// 0062db60
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

	// 0062dc10
	G3D::Vector3 GeometryService::getHitLocationFilterStairs(Instance* filterModel, G3D::Ray ray)
	{
		if (!workspace)
			return G3D::Vector3::ZERO;

		FilterStairs filter(filterModel);
		ContactManager& contactManager = workspace->getWorld()->getContactManager();
		G3D::Vector3 hitPoint(0.0f, 0.0f, 0.0f);
		std::vector<const Primitive*> ignore;
		if (!contactManager.getHit(ray, &ignore, &filter, hitPoint))
			hitPoint = ray.unit().origin + ray.direction;

		return hitPoint;
	}
#endif
}
