// Rebuild glue: the Explosion members rbxgs declares but never defines (its Explosion.cpp has
// signalBlast/doBlast). On its first step an explosion gathers the primitives in its blast radius,
// signals hits, kills characters in the kill radius and pushes everything in the blast radius; it is
// drawn for renderTime() seconds and then removed. Radii and timing are behavioural choices, not yet
// read from the binary. Not byte-verified.
#include "v8datamodel/Explosion.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8world/Primitive.h"
#include "humanoid/Humanoid.h"
#include "util/Extents.h"
#include <G3D/Sphere.h>

namespace RBX
{
	float Explosion::renderTime() const { return 0.5f; }
	float Explosion::visualRadius() const { return blastRadius * G3D::min(age / renderTime(), 1.0f); }
	float Explosion::killRadius() const { return blastRadius; }
	float Explosion::blastMaxObjectRadius() const { return blastRadius * 2.0f; }
	float Explosion::killMaxObjectRadius() const { return blastRadius * 2.0f; }

	void Explosion::setVisualOnly()
	{
		blastPressure = 0.0f;
		blastRadius = 0.0f;
	}

	// characters with a part inside the kill radius die
	void Explosion::doKill()
	{
		World* world = Workspace::getMyWorldFast(this);
		if (!world || killRadius() <= 0.0f)
			return;
		G3D::Array<Primitive*> found;
		G3D::Vector3 corner(killRadius(), killRadius(), killRadius());
		world->getContactManager().getPrimitivesTouchingExtents(Extents::fromCenterCorner(position, corner), NULL, found);
		for (int i = 0; i < found.size(); ++i)
		{
			PartInstance* part = PartInstance::fromPrimitive(found[i]);
			if (part && part->getParent())
				if (Humanoid* humanoid = Humanoid::modelIsCharacter(part->getParent()))
					humanoid->setHealth(0.0f);
		}
	}

	void Explosion::onEvent(const RunService*, Stepped event)
	{
		if (age == 0.0f)
		{
			if (World* world = Workspace::getMyWorldFast(this))
			{
				G3D::Array<Primitive*> found;
				G3D::Vector3 corner(blastRadius, blastRadius, blastRadius);
				world->getContactManager().getPrimitivesTouchingExtents(Extents::fromCenterCorner(position, corner), NULL, found);
				signalBlast(found);
				doKill();
				doBlast(found);
			}
		}
		age += event.step;
		if (age > renderTime())
			setParent(NULL);
	}

	void Explosion::render3dAdorn(Adorn* adorn)
	{
		adorn->explosion(G3D::Sphere(position, visualRadius()), G3D::Color4(1.0f, 0.5f, 0.0f, 0.5f), G3D::Color4(1.0f, 1.0f, 0.0f, 1.0f));
	}
}
