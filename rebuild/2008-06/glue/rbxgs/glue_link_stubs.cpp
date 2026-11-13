// winsock2 must precede windows.h (RakNet requirement)
#include <winsock2.h>

// Link-closure stubs: temporary, tracked. These are symbols rbxgs declares but no authentic source defines.
// They are not byte-verified and must be replaced with real implementations in Phase 5/8.
// Empty bodies below are stubs; the rest are small behavioural reconstructions.
#include "v8world/SimJobStage.h"
#include "reflection/property.h"
#include "RenderLib/Profiler.h"
#include "PacketFileLogger.h"
#include "reflection/signal.h"
#include "v8datamodel/Feature.h"
#include "gui/Gui.h"
#include "RbxGraphics/TextureProxyBase.h"
#include "RenderLib/TextureProxy.h"
#include "v8datamodel/ScriptMouseCommand.h"
#include "v8datamodel/UserController.h"
#include "v8datamodel/DebugSettings.h"
#include "tool/RunDragger.h"
#include "v8datamodel/Selection.h"
#include "v8xml/SerializerV2.h"
#include "v8datamodel/Explosion.h"
#include "v8datamodel/Seat.h"
#include "v8datamodel/SpawnLocation.h"
#include "v8datamodel/Flag.h"
#include "v8datamodel/FlagStand.h"
#include "PluginInterface.h"
#include "tool/DragTool.h"
#include "tool/PartDragTool.h"
#include "gui/Widget.h"
#include "Network/Players.h"
#include "humanoid/Humanoid.h"
#include "util/Events.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/LocalBackpack.h"
#include "tool/Dragger.h"
#include "tool/ToolsArrow.h"
#include "Streaming.h"
#include "util/ICameraSubject.h"
#include "v8tree/Instance.h"
#include "v8datamodel/Mouse.h"
#include "script/ScriptContext.h"
#include "Server.h"
#include "util/Sound.h"
#include "v8datamodel/Value.h"
#include "Replicator.h"
#include "v8world/Assembly.h"
#include "v8world/Clump.h"

namespace RBX
{
	// reflection
	// rendering

	// raknet logger moved outside namespace

	// signals moved outside namespace

	// textures

	// network bitstream helper
	// position then the rotation rows, as Replicator::deserializeValue reads a CoordinateFrame

	// content id equality

	// plugin receive (raknet adapter)
	// PluginInterfaceAdapter moved outside namespace

	// instance tree
	// replication

	// replication player state

	// gui

	// controllers

	// debug

	// dragging

	// gui item rendering

	// serializer moved outside namespace

	// events

	// service provider

	// tools

	// widget

	// abuse reporter

	// humanoid property

	// events range
	// Original 00420740: adjust every active dispatch after a listener is removed.
	// backpack rendering

	// explosion

	// dragger search

	// box select

	// string sender
	void Network::StringSender::send(RakNet::BitStream& stream, const Name& name) { send(stream, name.toString()); }

	// character subject

	// instance xml
	// a place-file root holding this instance (as SerializerV2::newRootElement + Instance::write)

	// gui root

	// mouse

	// script context
	// server
	// sound statics

	// value statics

	// sim job stage template instance
}

// definitions for classes that are not in namespace RBX
// a place file stream: parse and load as SerializerV2::loadXML does (DataModel::loadContent calls this)
