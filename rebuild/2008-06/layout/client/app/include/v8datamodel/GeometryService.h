// =============================================================================
// GeometryService.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/GeometryService.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

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
