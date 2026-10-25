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
	Reflection::Property::Property(const Reflection::Property& other) : Reflection::ConstProperty(other) {}

	// rendering
	Render::SpecData::SpecData() : shaderModel(0), videoMemory(0), CPUSpeed(0), glVendor(), gfxcard(), cpu(), ram(0), resolution() {}

	// raknet logger moved outside namespace

	// signals moved outside namespace

	// textures
	G3D::ReferenceCountedPointer<G3D::Texture> Render::TextureProxy::getIfResolved() const { return G3D::ReferenceCountedPointer<G3D::Texture>(); }
	G3D::Vector2 Render::TextureProxy::getSize() { return G3D::Vector2(); }
	G3D::ReferenceCountedPointer<G3D::Texture> Render::TextureProxy::resolve(G3D::RenderDevice*) { return G3D::ReferenceCountedPointer<G3D::Texture>(); }

	// network bitstream helper
	// position then the rotation rows, as Replicator::deserializeValue reads a CoordinateFrame
	RakNet::BitStream& Network::operator<<(RakNet::BitStream& stream, const G3D::CoordinateFrame& cf)
	{
		stream << cf.translation;
		for (int r = 0; r < 3; ++r)
			for (int c = 0; c < 3; ++c)
				stream << cf.rotation[r][c];
		return stream;
	}

	// content id equality
	bool operator==(const ContentId& a, const ContentId& b) { return a.toString() == b.toString(); }

	// plugin receive (raknet adapter)
	// PluginInterfaceAdapter moved outside namespace
	PluginReceiveResult Network::Server::ClientProxy::OnReceive(RakPeerInterface*, Packet*) { return (PluginReceiveResult)0; }
	bool Network::Server::ClientProxy::canSendItems() { return false; }

	// instance tree
	bool VelocityMotor::askSetParent(const Instance*) const { return true; }

	// replication
	void Network::Replicator::connectToReplicationContainers() {}

	// assembly
	// the root clump's root primitive, as Assembly::getMainPrimitive
	Primitive* Assembly::getAssemblyPrimitive() const { return rootClump->getRootPrimitive(); }
	const Primitive* Assembly::getAssemblyPrimitiveConst() const { return rootClump->getRootPrimitive(); }

	// replication player state

	// gui
	const Name& ScriptMouseCommand::getName() const { return Name::getNullName(); }

	// controllers

	// debug
	std::string DebugSettings::gfxcard() const { return std::string(); }

	// dragging
	void RunDragger::init(Workspace*, boost::weak_ptr<PartInstance>, const G3D::Vector3&) {}
	bool RunDragger::snap(const G3D::Ray&) { return false; }

	// gui item rendering

	// serializer moved outside namespace

	// events
	void PlayerController::onEvent(const RunService*, Heartbeat) {}

	// service provider

	// tools
	static MouseCommand* DragTool_onMouseDown_stub(PartInstance*, const G3D::Vector3&, const std::vector<Instance*>&, const UIEvent&, Workspace*) { return NULL; }
	MouseCommand* DragTool::onMouseDown(PartInstance*, const G3D::Vector3&, const std::vector<Instance*>&, const UIEvent&, Workspace*) { return NULL; }
	void PartDragTool::onMouseMove(const UIEvent&) {}

	// widget

	// abuse reporter
	worker_thread::work_result Network::AbuseReporter::processRequests(boost::shared_ptr<Network::AbuseReporter::data>, std::string) { return (worker_thread::work_result)0; }

	// humanoid property
	Reflection::BoundProp<float, 1> Humanoid::propMaxHealth("MaxHealth", "Data", &Humanoid::maxHealth, Reflection::PropertyDescriptor::STANDARD);

	// events range
	void RaiseRange::removeIndex(unsigned int) {}

	// backpack rendering
	void BackpackItem::render2d(Adorn*) {}
	void LocalBackpackItem::render2d(Adorn*) {}

	// explosion

	// dragger search
	void Dragger::searchDownGross(const G3D::Array<Primitive*>&, G3D::Vector3&, ContactManager&) {}
	void Dragger::searchUpGross(const G3D::Array<Primitive*>&, G3D::Vector3&, ContactManager&) {}

	// box select
	void BoxSelectCommand::selectAnd(const std::set<Instance*, std::less<Instance*>, std::allocator<Instance*> >&) {}
	void BoxSelectCommand::selectReverse(const std::set<Instance*, std::less<Instance*>, std::allocator<Instance*> >&) {}

	// string sender
	void Network::StringSender::send(RakNet::BitStream& stream, const Name& name) { send(stream, name.toString()); }

	// character subject
	void ICharacterSubject::stepGoalAndFocus(G3D::CoordinateFrame&, G3D::CoordinateFrame&, bool) {}

	// instance xml
	// a place-file root holding this instance (as SerializerV2::newRootElement + Instance::write)
	XmlElement* Instance::toNewXmlRoot(Instance* instance)
	{
		XmlElement* root = SerializerV2::newRootElement();
		if (XmlElement* item = instance->write())
			root->addChild(item);
		return root;
	}

	// gui root

	// mouse
	void Mouse::update(const UIEvent&) {}

	// script context
	XmlElement* ScriptContext::write() { return NULL; }

	// server
	XmlElement* Network::Server::write() { return NULL; }

	// sound statics
	const char* Soundscape::sSoundChannel = "SoundChannel";
	const char* Soundscape::sSoundService = "SoundService";

	// value statics
	const char* sBoolValue = "BoolValue";
	const char* sBrickColorValue = "BrickColorValue";
	const char* sCFrameValue = "CFrameValue";
	const char* sColor3Value = "Color3Value";
	const char* sFloatValue = "FloatValue";
	const char* sIntValue = "IntValue";
	const char* sObjectValue = "ObjectValue";
	const char* sStringValue = "StringValue";
	const char* sVector3Value = "Vector3Value";

	// sim job stage template instance
}

// definitions for classes that are not in namespace RBX
RBX::Reflection::GenericSlotWrapper::~GenericSlotWrapper() {}
::FilePacketLogger::~FilePacketLogger() {}
void SerializerV2::load(std::istream&, RBX::DataModel*) {}
RBX::Render::TextureProxy::~TextureProxy() {}
