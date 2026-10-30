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
	bool PartInstance::showAnchoredParts = false;
	bool PartInstance::showPartCoord = false;
	bool PartInstance::showUnalignedParts = false;
	bool PartInstance::showSpanningTree = false;
	bool Debugable::validatingDebug = false;
	G3D::Vector3 MouseCommand::ignoreVector3;
	boost::recursive_mutex GlobalSettings::mutex;
	G3D::GFontRef Fonts::fontRef;
	bool Render::AggregateChunk::randomColors = false;
	boost::shared_ptr<boost::mutex> Lua::ThreadRef::syncSingleton(new boost::mutex);

	namespace Stats
	{
#ifndef ROC_ARRAY_CLASS_NAMES
		const char* sStatsItem = "StatsItem";
#endif
	}

	Reflection::SignalDesc<RunService, void(float, float)> RunService::event_Stepped("Stepped", "time", "step");
	Reflection::SignalDesc<Lighting, void(bool)> Lighting::event_LightingChanged("LightingChanged", "skyboxChanged");

	namespace Network
	{
		std::string API::version;

		Reflection::SignalDesc<Client, void(std::string, boost::shared_ptr<Instance>)> Client::event_ConnectionAccepted("ConnectionAccepted", "peer", "replicator");
		Reflection::SignalDesc<Client, void(std::string, int)> Client::event_ConnectionFailed("ConnectionFailed", "peer", "code");
		Reflection::SignalDesc<Client, void(std::string)> Client::event_ConnectionRejected("ConnectionRejected", "peer");
		Reflection::SignalDesc<Server, void(std::string, boost::shared_ptr<Instance>)> Server::event_IncommingConnection("IncommingConnection", "peer", "replicator");
		Reflection::SignalDesc<Marker, void(void)> Marker::event_Returned("Returned");

		Reflection::RefPropDescriptor<Players, Player> Players::propLocalPlayer("LocalPlayer", "Data", &Players::getLocalPlayer,
			static_cast<void (Players::*)(Player*)>(NULL), Reflection::PropertyDescriptor::UI);
	}
}

CrashReporter* CrashReporter::singleton = NULL;
