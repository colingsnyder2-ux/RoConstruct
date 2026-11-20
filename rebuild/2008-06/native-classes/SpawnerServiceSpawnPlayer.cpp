// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /fp:fast /DNDEBUG /D_MBCS /I{headers}/part-embedded
// 2008-06 native RBX::SpawnerService::SpawnPlayer 005d2b80 (inactive). The original body lives in the
// SpawnLocation/SpawnerService unit (005d1ba0..005d39f0, native-classes/SpawnLocation.cpp), where getTeamColor
// 005d1ba0 is defined and inlined into this routine (the original reads SpawnLocation +0x3e8 directly). This unit
// is a staging copy until that file's owner moves the body there (proposal in the batch 26 dm05 result).
// Trial evidence (batch 26): with SpawnLocation::getTeamColor defined in the same unit this body compiles to 1084
// bytes IDENTICAL to 005d2b80 (relocs masked); here getTeamColor 005d1ba0 stays an out-of-line call (near miss).
// /fp:fast is required: without it y + 7 is stored, reloaded and added as a double constant.
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/SpawnerService.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/ForceField.h"
#include "v8datamodel/DebrisService.h"
#include "Network/Player.h"
#include <stdexcept>
#include <vector>
#include <stdlib.h>

namespace RBX
{
	// 005d2b80 (1084 bytes, ret 0xc). Identity: string 0083bda0 "SpawnPlayer couldn't get the workspace"; donor
	// tools/openrbx Client/App/v8datamodel/SpawnLocation.cpp SpawnerService::SpawnPlayer; caller
	// Player::loadCharacter 004957a0. Callees: find<Workspace> 00491e50, RootInstance::moveToPoint 005909e0
	// (Vector3(0, 100 [008163a4], 0)), PartInstance::getCoordinateFrame 00598cb0 (+7 [00831db4] on y),
	// create<ForceField> 005c1520, Instance::setParent 0055a8f0, ServiceProvider::create<DebrisService>(const
	// Instance*) 005d2b30, DebrisService::addItem 0063bbc0 (fild of duration +0x404 to double).
	void SpawnerService::SpawnPlayer(boost::shared_ptr<ModelInstance> model, Network::Player* p)
	{
		Workspace* workspace = ServiceProvider::find<Workspace>(this);
		if (!workspace)
			throw std::runtime_error("SpawnPlayer couldn't get the workspace");

		if (spawners.size() == 0)
		{
			workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 100.0f, 0.0f));
			return;
		}

		std::vector<SpawnLocation*> possibleLocations;

		std::list<SpawnLocation*>::iterator it;
		for (it = spawners.begin(); it != spawners.end(); ++it)
		{
			if ((*it)->neutral)
				possibleLocations.push_back(*it);
			else if (!p->getNeutral() && p->getTeamColor() == (*it)->getTeamColor())
				possibleLocations.push_back(*it);
		}

		if (possibleLocations.size() == 0)
		{
			workspace->moveToPoint(model.get(), G3D::Vector3(0.0f, 100.0f, 0.0f));
			return;
		}

		SpawnLocation* location = possibleLocations[rand() % possibleLocations.size()];

		G3D::Vector3 dropPoint = location->getCoordinateFrame().translation;
		dropPoint.y += 7.0f;

		int duration = location->duration;
		if (duration > 0)
		{
			boost::shared_ptr<ForceField> f = Creatable<Instance>::create<ForceField>();
			f->setParent(model.get());
			DebrisService* debris = ServiceProvider::create<DebrisService>(this);
			debris->addItem(f, location->duration);
		}

		workspace->moveToPoint(model.get(), dropPoint);
	}
}
