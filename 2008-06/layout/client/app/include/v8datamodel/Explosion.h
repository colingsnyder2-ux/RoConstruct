// =============================================================================
// Explosion.h
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/include/v8datamodel/Explosion.h
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#pragma once
#include "util/RunStateOwner.h"
#include "util/IRenderable.h"

namespace RBX
{
	class Primitive;

	extern char sExplosion[];

	class Explosion : public DescribedCreatable<Explosion, Instance, sExplosion>,
					  public Listener<RunService, Stepped>,
					  public IRenderable
	{
	private:
		float age;
		G3D::Vector3 position;
		float blastRadius;
		float blastPressure;
	public:
		static Reflection::BoundProp<G3D::Vector3, 1> propPosition;
		static Reflection::BoundProp<float, 1> propBlastPressure;

	private:
		float renderTime() const;
		float visualRadius() const;
		float killRadius() const;
		float blastMaxObjectRadius() const;
		float killMaxObjectRadius() const;
		void doKill();
		void doBlast(const G3D::Array<Primitive*>& primitives);
		void signalBlast(const G3D::Array<Primitive*>& primitives);
		virtual void onEvent(const RunService*, Stepped);
		virtual bool askSetParent(const Instance* instance) const;
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);

		virtual bool shouldRender3dAdorn() const
		{
			return true;
		}

		virtual void render3dAdorn(Adorn* adorn);
	public:
		Explosion();

		virtual ~Explosion()
		{
		}

		void setVisualOnly();
		void setBlastRadius(float _blastRadius);

		float getBlastRadius() const
		{
			return blastRadius;
		}
	};
}
