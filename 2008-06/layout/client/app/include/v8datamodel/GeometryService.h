#pragma once
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

		void getPartsTouchingExtents(const Extents& extents, const Primitive* ignore, G3D::Array<PartInstance*>& result);
		G3D::Vector3 getHitLocationFilterStairs(Instance* filterModel, G3D::Ray ray);

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 0062dda0
	};
}
