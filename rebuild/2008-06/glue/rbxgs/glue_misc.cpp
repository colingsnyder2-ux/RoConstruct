// Rebuild glue: small members rbxgs declares but never defines. Behavioural reconstructions, not
// byte-verified; each follows the neighbouring rbxgs code it names.
#include "v8datamodel/Feature.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Team.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Value.h"
#include "v8world/RotateJoint.h"
#include "v8world/World.h"
#include "script/Script.h"
#include "gui/GuiDraw.h"
#include "util/Sound.h"
#include "Streaming.h"
#include "BitStream.h"

namespace RBX
{
	void registerRecoveredValues();

	// as the other RotateJoint constructor: a two-breaking multi joint with no connector yet

	// features sit on a part's face
	// a feature's frame points out of its face; a hole's points into it
	WorkspaceStatsItem::WorkspaceStatsItem(const Workspace* workspace, const World* world, const RunService* runService)
	{
		setName("Workspace");
	}

	namespace Network
	{
		// rbxgs Streaming.cpp defines operator<< for long& where the header declares this reader
		RakNet::BitStream& operator>>(RakNet::BitStream& stream, long& value)
		{
			stream.Read(value);
			return stream;
		}
	}

	// declare the reflected classes so the factory can create them by name

}
