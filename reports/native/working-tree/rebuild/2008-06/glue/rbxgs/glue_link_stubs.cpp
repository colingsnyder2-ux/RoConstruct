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

	// instance tree
	bool VelocityMotor::askSetParent(const Instance*) const { return true; }

	// replication

	// assembly
	// the root clump's root primitive, as Assembly::getMainPrimitive
	Primitive* Assembly::getAssemblyPrimitive() const { return rootClump->getRootPrimitive(); }
	const Primitive* Assembly::getAssemblyPrimitiveConst() const { return rootClump->getRootPrimitive(); }

	// replication player state

	// gui
	const Name& ScriptMouseCommand::getName() const { return Name::getNullName(); }  // STUB

	// controllers

	// debug
	std::string DebugSettings::gfxcard() const { return std::string(); }  // STUB

	// dragging
	void RunDragger::init(Workspace*, boost::weak_ptr<PartInstance>, const G3D::Vector3&) {}  // STUB
	bool RunDragger::snap(const G3D::Ray&) { return false; }  // STUB

	// gui item rendering

	// serializer moved outside namespace

	// events

	// service provider

	// tools
	MouseCommand* DragTool::onMouseDown(PartInstance*, const G3D::Vector3&, const std::vector<Instance*>&, const UIEvent&, Workspace*) { return NULL; }  // STUB
	void PartDragTool::onMouseMove(const UIEvent&) {}  // STUB

	// widget

	// abuse reporter
	worker_thread::work_result Network::AbuseReporter::processRequests(boost::shared_ptr<Network::AbuseReporter::data>, std::string) { return (worker_thread::work_result)0; }  // STUB

	// humanoid property
	Reflection::BoundProp<float, 1> Humanoid::propMaxHealth("MaxHealth", "Data", &Humanoid::maxHealth, Reflection::PropertyDescriptor::STANDARD);

	// events range
	void RaiseRange::removeIndex(unsigned int) {}  // STUB

	// backpack rendering
	void BackpackItem::render2d(Adorn*) {}  // STUB
	void LocalBackpackItem::render2d(Adorn*) {}  // STUB

	// explosion

	// dragger search
	void Dragger::searchDownGross(const G3D::Array<Primitive*>&, G3D::Vector3&, ContactManager&) {}  // STUB
	void Dragger::searchUpGross(const G3D::Array<Primitive*>&, G3D::Vector3&, ContactManager&) {}  // STUB

	// box select
	void BoxSelectCommand::selectAnd(const std::set<Instance*, std::less<Instance*>, std::allocator<Instance*> >&) {}  // STUB
	void BoxSelectCommand::selectReverse(const std::set<Instance*, std::less<Instance*>, std::allocator<Instance*> >&) {}  // STUB

	// string sender
	void Network::StringSender::send(RakNet::BitStream& stream, const Name& name) { send(stream, name.toString()); }

	// character subject

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

	// script context
	XmlElement* ScriptContext::write() { return NULL; }  // STUB

	// server
	XmlElement* Network::Server::write() { return NULL; }  // STUB

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
// a place file stream: parse and load as SerializerV2::loadXML does (DataModel::loadContent calls this)
void SerializerV2::load(std::istream& stream, RBX::DataModel* dataModel) { loadXML(stream, dataModel); }
