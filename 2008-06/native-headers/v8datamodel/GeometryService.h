#pragma once
// >>> native-status (generated) -- do not edit >>>
// GeometryService | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 7190b78f | roc native-status --write
// 2008-06 native RBX::GeometryService (inactive). No donor header (tools/rbxgs has no GeometryService); every base,
// field and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 00846a84 .?AVGeometryService@RBX@@ -> DescribedCreatable<GeometryService, Instance,
//              sGeometryService> (name mangled $1?sGeometryService@2@3PADA, a non-const char array in .data at 0095c530
//              holding "Geometry": doDeclare 005bfa30, classDescriptor 005c0470) and the empty Service (mdisp 0x130).
//   size       0x140: Creatable<Instance>::create<GeometryService> 005c1790 mallocs 0x140 and calls the constructor
//              0062dee0.
//   ctor       0062dee0 passes the class-name array itself to DescribedCreatable<..>::DescribedCreatable<const char*>
//              0062ddc0 (-> FactoryProduct<const char*> 0062d950 -> Instance(const char*) 0055b960), stores
//              workspace = 0 (+0x130), the ten vtables, then the empty G3D::Array (+0x138 num, +0x13c numAllocated,
//              +0x134 data).
//   dtor       0062e000: System::alignedFree(+0x134) and +0x134/+0x138/+0x13c = 0 (~G3D::Array of a trivially
//              destructible element), then ~FactoryProduct 0062d8f0 (deleting 0062e070).
//   vtable     slot 12 onServiceProvider 0062dda0: when newProvider is set, workspace =
//              newProvider->create<Workspace>() (00490af0); no Instance::onServiceProvider call.
//   workspace  0062db60 and 0062dc10 read workspace (+0x130) -> Workspace +0x2e4 (World*) -> World +0x84
//              (ContactManager*); both return early when workspace is NULL.
//   array      0062db60 resizes the +0x134 G3D::Array<Primitive*> (Array<Primitive*>::resize 00599a70), passes it to
//              ContactManager::getPrimitivesTouchingExtents 0060d140 and appends PartInstance::fromPrimitive 00599f80
//              of each element to the caller's G3D::Array<PartInstance*> (append 0062daf0, resize 0062d9e0).
// Method names are analog names (no donor): the caller HUMAN::Climbing 00644a30 / 00644c80 reaches the service through
// 006449e0.
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <G3D/Array.h>
#include <G3D/Vector3.h>
#include <G3D/Ray.h>

struct NativeGeometryServiceLayout;

namespace RBX
{
	class Workspace;
	class Primitive;
	class PartInstance;
	class Extents;

	extern char sGeometryService[];

	class GeometryService : public DescribedCreatable<GeometryService, Instance, sGeometryService>,
							public Service
	{
		friend struct ::NativeGeometryServiceLayout; // tests/NativeGeometryServiceLayout.cpp offset asserts

	private:
		Workspace* workspace;                           // +0x130
		G3D::Array<Primitive*> primitives;              // +0x134 (data +0x134, num +0x138, numAllocated +0x13c)

	public:
		GeometryService();                              // 0062dee0
		// ~GeometryService 0062e000 is implicit (deleting 0062e070).

		// 0062db60 (needs the Workspace world at +0x2e4: NATIVE_GEOMETRYSERVICE_PENDING in the unit)
		void getPartsTouchingExtents(const Extents& extents, const Primitive* ignore, G3D::Array<PartInstance*>& result);
		// 0062dc10 (needs the Workspace world at +0x2e4 and RBX::FilterStairs: NATIVE_GEOMETRYSERVICE_PENDING)
		G3D::Vector3 getHitLocationFilterStairs(Instance* filterModel, G3D::Ray ray);

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 0062dda0
	};
}
