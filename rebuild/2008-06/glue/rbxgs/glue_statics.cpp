// Rebuild glue: static members rbxgs declares but never defines. Event and property names (with their
// argument names) are the 2008-06 Roblox.exe strings: "ConnectionAccepted" (peer, replicator),
// "ConnectionRejected" (peer), "ConnectionFailed" (peer, code), "IncommingConnection", "Stepped" (step),
// "LightingChanged" (skyboxChanged), "LocalPlayer", "StatsItem". Debug switches default off.
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Lighting.h"
#include "v8datamodel/MouseCommand.h"
#include "v8datamodel/GlobalSettings.h"
#include "v8datamodel/Stats.h"
#include "util/RunStateOwner.h"
#include "util/Debug.h"
#include "script/ThreadRef.h"
#include "AppDraw/Fonts.h"
#include "RenderLib/Chunk.h"
#include "Network/API.h"
#include "Network/Players.h"
#include "Network/CrashReporter.h"
#include "Client.h"
#include "Server.h"
#include "Replicator.h"

namespace RBX
{
	G3D::GFontRef Fonts::fontRef;
	// Render::AggregateChunk::randomColors: defined by the OpenRBX renderer layer (Chunk.cpp)

	namespace Stats
	{
	}


	namespace Network
	{


	}
}

CrashReporter* CrashReporter::singleton = NULL;
