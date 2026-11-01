// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_aug2007_network_replicator_item_readiness_1d9dd49282a2cc8e.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "../App/roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "../App/roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "../App/roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_character_state_f342eee04d017582.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_character_state_f342eee04d017582.cpp>)
#pragma include_alias("humanoid/Humanoid.h", "../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp")
#pragma include_alias(<humanoid/Humanoid.h>, <../roc_espeon_aug2007_humanoid_state_f78ef0aa0660622a.cpp>)
#pragma include_alias("humanoid/Running.h", "../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp")
#pragma include_alias(<humanoid/Running.h>, <../roc_espeon_aug2007_running_balance_hook_875f0bb95aec50f5.cpp>)
#pragma include_alias("humanoid/Balancing.h", "../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp")
#pragma include_alias(<humanoid/Balancing.h>, <../roc_espeon_aug2007_balancing_balance_hook_37ced1d1de755090.cpp>)
#pragma include_alias("humanoid/FallingDown.h", "../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp")
#pragma include_alias(<humanoid/FallingDown.h>, <../roc_espeon_aug2007_fallingdown_state_7499778b68c8dff0.cpp>)
#pragma include_alias("humanoid/Flying.h", "../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp")
#pragma include_alias(<humanoid/Flying.h>, <../roc_espeon_aug2007_flying_balance_hook_a9eee8e762225c01.cpp>)
#pragma include_alias("humanoid/Freefall.h", "../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp")
#pragma include_alias(<humanoid/Freefall.h>, <../roc_espeon_aug2007_freefall_state_671ebe3411c8030d.cpp>)
#pragma include_alias("humanoid/GettingUp.h", "../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp")
#pragma include_alias(<humanoid/GettingUp.h>, <../roc_espeon_aug2007_gettingup_balance_hook_972ad7ec2ed27c84.cpp>)
#pragma include_alias("humanoid/Jumping.h", "../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp")
#pragma include_alias(<humanoid/Jumping.h>, <../roc_espeon_aug2007_jumping_state_9af9b1e45a772018.cpp>)
#pragma include_alias("humanoid/Seated.h", "../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp")
#pragma include_alias(<humanoid/Seated.h>, <../roc_espeon_aug2007_seated_state_df5e271a3b8e21cd.cpp>)
#pragma include_alias("RbxGraphics/Adorn.h", "../roc_espeon_aug2007_adorn_header_6887d8bb2eb92360.cpp")
#pragma include_alias(<RbxGraphics/Adorn.h>, <../roc_espeon_aug2007_adorn_header_6887d8bb2eb92360.cpp>)
#pragma include_alias("AppDraw/AdornG3D.h", "../roc_espeon_aug2007_adorng3d_header_62d495574bf52995.cpp")
#pragma include_alias(<AppDraw/AdornG3D.h>, <../roc_espeon_aug2007_adorng3d_header_62d495574bf52995.cpp>)
#pragma include_alias("v8kernel/Kernel.h", "../roc_espeon_aug2007_kernel_inline_header_359388a626d15479.cpp")
#pragma include_alias(<v8kernel/Kernel.h>, <../roc_espeon_aug2007_kernel_inline_header_359388a626d15479.cpp>)
#pragma include_alias("v8kernel/Point.h", "../roc_espeon_aug2007_point_inline_header_aac7baa3a10948cb.cpp")
#pragma include_alias(<v8kernel/Point.h>, <../roc_espeon_aug2007_point_inline_header_aac7baa3a10948cb.cpp>)
#pragma include_alias("Streaming.h","roc_espeon_aug2007_idserializer_historical_header_2be9fefd82935a8e.cpp")
#pragma include_alias("Replicator.h","roc_espeon_aug2007_replicator_idserializer_header_1dbd04cea7efec99.cpp")
#pragma include_alias("PacketIds.h","roc_espeon_aug2007_packet_ids_historical_header_55a9a42b18a3ae51.cpp")

#include "roc_espeon_aug2007_idmanager_historical_header_bf92b6db84c275bf.cpp"
#include "v8datamodel/Camera.h"
#include "Replicator.h"
namespace RBX {namespace Network {Replicator::Item::~Item(){}}}
#include <RakPeer.h>
#include <PacketLogger.h>
#include <GetTime.h>
#include "Replicator.h"
#include "NetworkSettings.h"
#include "PacketIds.h"
#include "security/SecurityContext.h"
#include "v8datamodel/Stats.h"
#include "v8datamodel/PartInstance.h"
#include "v8world/SimJobStage.h"
#include "util/Log.h"
#include "util/standardout.h"
#include <g3d/system.h>

static RBX::Reflection::BoundFuncDesc<RBX::Network::Replicator, boost::shared_ptr<RBX::Reflection::DescribedBase>(void), 0> func_SendMarker(&RBX::Network::Replicator::sendMarker, "SendMarker", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Network::Replicator, void(void), 0> func_requestCharacter(&RBX::Network::Replicator::requestCharacter, "RequestCharacter", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Network::Replicator, void(void), 0> func_closeConnection(&RBX::Network::Replicator::closeConnection, "CloseConnection", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

static RBX::Reflection::BoundFuncDesc<RBX::Network::Replicator, boost::shared_ptr<RBX::Instance>(void), 0> prop_RemotePlayer(&RBX::Network::Replicator::getPlayer, "GetPlayer", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

enum ValueType // NOTE: may not be intended for this file
{
	ValueType_nil,
	ValueType_string,
	ValueType_bool,
	ValueType_int,
	ValueType_float,
	ValueType_BrickColor,
	ValueType_Color3,
	ValueType_Vector3,
	ValueType_BrickVector,
	ValueType_CoordinateFrame,
	ValueType_Enum,
	ValueType_Ref,
	ValueType_ContentId
};

class ExtractorHack : public RakPeer
{
public:
	HANDLE getProcessPacketsThreadHandle() // the lengths you have to go through to get a protected member
	{
		return processPacketsThreadHandle;
	}
};

static void checkDisconnect(RBX::Instance* instance)
{
	RBX::Network::Replicator* repl = dynamic_cast<RBX::Network::Replicator*>(instance);

	if (repl && repl->disconnected)
	{
		repl->setParent(NULL);
	}
}

void writeValueType(bool includeLength, ValueType vt, RakNet::BitStream& outBitStream)
{
	if (includeLength)
	{
		unsigned char c = (unsigned char)vt;
		outBitStream.WriteBits(&c, 4, true);
	}
}

FilePacketLogger::FilePacketLogger(RBX::Network::Peer* peer)
	: packetLogFile(NULL)
{
	char filename[256];

	std::string pathName = RBX::Log::current()->logFile;
	pathName.erase(pathName.rfind('\\') + 1);

	sprintf(filename, "PacketLog%i.csv", RakNet::GetTime());
	pathName += filename;

	packetLogFile = fopen(pathName.c_str(), "wt");

	if (packetLogFile)
	{
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_INFO, "Logging packets to %s", pathName.c_str());
	}
	else
	{
		RBX::StandardOut::singleton()->print(RBX::MESSAGE_WARNING, "Failed to create log file %s", pathName.c_str());
	}
}
	
void FilePacketLogger::OnAttach(RakPeerInterface* peer)
{
	PacketLogger::OnAttach(peer);
	LogHeader();
}

void FilePacketLogger::WriteLog(const char* str)
{
	if (packetLogFile)
		fputs(str, packetLogFile);
}

namespace RBX
{
	namespace Network
	{
		Peer::Peer()
			: profilePacketsThread(new Profiling::ThreadProfiler("Packets Thread")),
			  rakPeer(new RakPeer)
		{
			rakPeer->AttachPlugin(this);
		}

		Peer::~Peer() 
		{
			rakPeer->DetachPlugin(this);
		}

		void Peer::onEvent(const RunService* source, Heartbeat event)
		{
			double tick = G3D::System::getTick() + event.step / 5.0;

			do
			{
				Packet* receivedPacket = rakPeer->Receive();
				if (receivedPacket)
					rakPeer->DeallocatePacket(receivedPacket);
				else
					break;
			}
			while (G3D::System::getTick() < tick);

			for_eachChild(&checkDisconnect);
		}

		RakPeerInterface* Peer::peerInterface()
		{
			return rakPeer.get();
		}

		void Peer::Update(RakPeerInterface* peer)
		{
			RBXASSERT(peer == rakPeer.get());

			profilePacketsThread->sample(static_cast<ExtractorHack*>(peer)->getProcessPacketsThreadHandle());
			PluginInterface::Update(peer); // TODO: blank function shared by multiple symbols. is this the correct one?
		}

		void Peer::updateLogger()
		{
			if (!NetworkSettings::singleton().logPackets)
			{
				logger.reset();
			}
			else if (!logger)
			{
				logger.reset(new FilePacketLogger(this));
				rakPeer->AttachPlugin(logger.get());
			}
		}

		void Peer::updateNetworkSimulator()
		{
			rakPeer->ApplyNetworkSimulator(
				NetworkSettings::singleton().maxSendBPS, 
				NetworkSettings::singleton().minExtraPing,
				NetworkSettings::singleton().extraPingVariance
			);
		}

		IdSerializer::IdSerializer(RBX::IdManager* manager):idManager(manager){}
 Replicator::Replicator(SystemAddress remotePlayerId, RakPeerInterface* peer, RBX::IdManager* manager)
			: IdSerializer(manager), lastSendTime(G3D::System::getLocalTime()),
			  lastCharacterSendTime(G3D::System::getLocalTime()),
			  profileReplication(new Profiling::CodeProfiler("Replication")),
			  profileDataListening(new Profiling::CodeProfiler("Data Listening")),
			  profileDataIn(new Profiling::CodeProfiler("Data In")),
			  profileDataOut(new Profiling::CodeProfiler("Data Out")),
			  profilePhysicsIn(new Profiling::CodeProfiler("Physics In")),
			  profilePhysicsOut(new Profiling::CodeProfiler("Physics Out")),
			  remotePlayerId(remotePlayerId),
			  peer(peer),
			  disconnected(false),
			  
			  sendPhysicsEnabled(false),
			  players(NULL),
			  deserializeProperty(NULL),
			  removingInstance(NULL)
		{
			peer->AttachPlugin(this);
			setName(remotePlayerId.ToString(true));

			profileDataListening->parent = profileReplication.get();
			profileDataIn->parent = profileReplication.get();
			profileDataOut->parent = profileReplication.get();
			profilePhysicsIn->parent = profileReplication.get();
			profilePhysicsOut->parent = profileReplication.get();
		}

		Replicator::~Replicator()
		{
			if (peer)
				peer->DetachPlugin(this);
		}

		bool Replicator::wantReplicate(const Instance* source) const
		{
			return dynamic_cast<const Camera*>(source) == NULL ? true : false;
		}

		

		void Replicator::closeConnection()
		{
			peer->CloseConnection(remotePlayerId, true);
			setParent(NULL);
		}

		Player* Replicator::findTargetPlayer()
		{
			return players ? players->getLocalPlayer() : NULL;
		}

		Mechanism* Replicator::findTargetPlayerCharacterMechanism()
		{
			Player* player = findTargetPlayer();

			if (player && player->getCharacter())
			{
				PartInstance* part = player->getCharacter()->getPrimaryPart();

				if (part)
					return Mechanism::getMechanismFromPrimitive(part->getPrimitive());
			}
			
			return NULL;
		}

		bool Replicator::isSerializePending(const Instance* instance) const
		{
			return pendingNewInstances.find(instance) != pendingNewInstances.end();
		}

		void Replicator::disconnectAllPropertyChangedConnections()
		{
			while (propertyChangedConnections.size() > 0)
			{
				propertyChangedConnections.begin()->second.disconnect();
				propertyChangedConnections.erase(propertyChangedConnections.begin());
			}
		}

		

		void Replicator::disconnectPropertyChanged(boost::shared_ptr<Instance> instance)
		{
			std::map<boost::shared_ptr<Instance>, boost::signals::connection>::iterator iter = propertyChangedConnections.find(instance);

			if (iter != propertyChangedConnections.end())
			{
				iter->second.disconnect();
				propertyChangedConnections.erase(iter);
			}
		}

		void Replicator::deleteDisconnectInstances()
		{
			std::set<boost::weak_ptr<Instance>>::iterator iter = deleteOnDisconnectInstances.begin();
			std::set<boost::weak_ptr<Instance>>::iterator end = deleteOnDisconnectInstances.end();

			for (; iter != end; iter++)
			{
				boost::shared_ptr<Instance> instance = iter->lock();
				if (instance)
					instance->setParent(NULL);
			}

			deleteOnDisconnectInstances.clear();
		}

		bool Replicator::isInReplicationScope(const Instance* instance) const
		{
			std::vector<Instance*>::const_iterator begin = replicationContainers.begin();
			std::vector<Instance*>::const_iterator end = replicationContainers.end();

			if (std::find_if(begin, end, boost::bind(&Instance::isDescendentOf, instance, _1)) != end)
			{
				return true;
			}
			else
			{
				return std::find(begin, end, instance) != end ? true : false;
			}
		}

		void Replicator::readMarker(RakNet::BitStream& inBitstream)
		{
			long markerId;
			inBitstream >> markerId;

			if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Received marker %d from %s", (int)markerId, remotePlayerId.ToString());
			}

			RBXASSERT(reinterpret_cast<Marker*>(markerId) == incomingMarkers.front().get());

			Marker::event_Returned.fire(incomingMarkers.front().get());
			incomingMarkers.pop();
		}

		boost::shared_ptr<Reflection::DescribedBase> Replicator::sendMarker()
		{
			boost::shared_ptr<Marker> marker = Marker::newMarker();

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)ID_REQUEST_MARKER;
			bitStream << (int)marker->id();

			if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replicator: Requesting Marker %d of %s", (int)marker->id(), remotePlayerId.ToString());
			}

			incomingMarkers.push(marker);
			peer->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 0, remotePlayerId, false);

			return marker;
		}

		bool Replicator::sendPhysicsPacket()
		{
			if (!sendPhysicsEnabled)
			{
				return false;
			}
			else if (!peer->GetStatistics(remotePlayerId)) // TODO: vtable offset does not match due to missing function in RakPeerInterface
			{
				return false;
			}
			else
			{
				Profiling::Mark mark(*profilePhysicsOut, false);
				JobSender jobSender(*this, peer);

				Workspace* workspace = ServiceProvider::find<Workspace>(this);
				if (workspace)
				{
					SimJobStage& sim = workspace->getWorld()->getSimJobStage();
					Mechanism* mech = findTargetPlayerCharacterMechanism();
					if (mech)
					{
						G3D::RealTime t = G3D::System::getLocalTime();
						if (t > lastCharacterSendTime + 0.1)
						{
							jobSender.setPacketPriority(MEDIUM_PRIORITY);
							jobSender.report(*mech);
							jobSender.setPacketPriority(MEDIUM_PRIORITY);

							lastCharacterSendTime = t;
						}
						else
						{
							mech = NULL;
						}
					}

					sim.reportMechanisms(jobSender, jobStagePos, mech);
				}

				return jobSender.sentPacket;
			}
		}

		

		const Instance* Replicator::getDefault(const Name& className)
		{
			Security::Impersonator impersonate(Security::Replicator);

			std::map<const Name*, boost::shared_ptr<Instance>>::iterator iter = defaultObjects.find(&className);

			if (iter == defaultObjects.end())
			{
				boost::shared_ptr<Instance> instance = AbstractFactoryProduct::create(className);

				if (!instance)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Replication: Can\'t create default object of type %s", className.c_str());
				}

				defaultObjects[&className] = instance;
				return instance.get();
			}
			else
			{
				return iter->second.get();
			}
		}

		SharedStringDictionary& Replicator::getSharedDictionary(const Reflection::PropertyDescriptor& descriptor)
		{
			std::map<const Reflection::PropertyDescriptor*, boost::shared_ptr<SharedStringDictionary>>::iterator iter = strings.find(&descriptor);

			if (iter == strings.end())
			{
				boost::shared_ptr<SharedStringDictionary> result(new SharedStringDictionary);

				strings[&descriptor] = result;
				return *result;
			}
			else
			{
				return *iter->second;
			}
		}

		void Replicator::receiveData(Packet* packet)
		{
			Profiling::Mark mark(*profileDataIn, false);

			RakNet::BitStream inBitstream(packet->data, packet->length, false);
			inBitstream.IgnoreBits(8);

			Security::Impersonator impersonate(Security::Replicator);

			while (true)
			{
				Item::ItemType itemType;
				Item::readItemType(inBitstream, itemType);
				
				switch (itemType)
				{
				case Item::ItemTypeDelete:
					readInstanceDelete(inBitstream);
					break;
				case Item::ItemTypeNew:
					readInstanceNew(inBitstream);
					break;
				case Item::ItemTypeChangeProperty:
					readChangedProperty(inBitstream);
					break;
				case Item::ItemTypeMarker:
					readMarker(inBitstream);
					break;
				case Item::ItemTypeEnd:
					return;
				}
			}
		}

		//99% match
		void Replicator::Update(RakPeerInterface* peer)
		{
			PluginInterface::Update(peer);

			if (getParent())
			{
				Profiling::Mark mark(*profileReplication, false);

				RakNetStatistics* statistics = peer->GetStatistics(remotePlayerId);

				if (statistics)
				{
					G3D::RealTime t = G3D::System::getLocalTime();

					if (1.0f / NetworkSettings::singleton().sendRate + lastSendTime < t)
					{
						int maxBuffer = NetworkSettings::singleton().maxDataModelSendBuffer;
						int sendBuffer = statistics->messageSendBuffer[MEDIUM_PRIORITY] + statistics->messageSendBuffer[HIGH_PRIORITY];

						if (maxBuffer - sendBuffer >= 2 && !statistics->bandwidthExceeded)
						{
							sendPhysicsPacket();
							sendItems();
							lastSendTime = t;
						}
					}

					if (NetworkSettings::singleton().printPacketBuffer)
					{
						size_t sendBuffer = statistics->messageSendBuffer[MEDIUM_PRIORITY] + statistics->messageSendBuffer[HIGH_PRIORITY] * 2;
						size_t maxBuffer = NetworkSettings::singleton().maxDataModelSendBuffer;

						if (sendBuffer > maxBuffer)
						{
							StandardOut::singleton()->print(MESSAGE_WARNING, "SendBuffer = %d", sendBuffer);
						}
						else if (sendBuffer > 0)
						{
							StandardOut::singleton()->print(MESSAGE_INFO, "SendBuffer = %d", sendBuffer);
						}
					}
				}
			}
		}

		void Replicator::createStatsItems(Stats::StatsService* stats)
		{
			if (statsItem)
			{
				statsItem->setParent(NULL);
				statsItem.reset();
			}

			if (stats)
			{
				boost::shared_ptr<Stats::Item> network = shared_from_polymorphic_downcast<Stats::Item>(stats->findFirstChildByName("Network"));

				if (network)
				{
					statsItem = Creatable::create<ReplicatorStatsItem>(shared_from(this), peer->GetStatistics(remotePlayerId));
					statsItem->setName(getName());
					statsItem->setParent2(network);
				}
			}
		}

		//95.65% match
		//functionally accurate, *slightly* different instruction ordering
		bool Replicator::isChildOfPendingDeleteInstance(const Instance* instance) const
		{
			for (const Instance* current = instance->getParent(); current != NULL; current = current->getParent())
			{
				if (pendingDeleteInstances.find(current) != pendingDeleteInstances.end())
					return true;
			}

			return false;
		}

		void Replicator::onPropertyChanged(boost::shared_ptr<Instance> instance, const Reflection::PropertyDescriptor* descriptor)
		{
			Profiling::Mark mark(*profileReplication, false);
			Profiling::Mark mark2(*profileDataListening, false);

			if (instance.get() != removingInstance)
			{
				bool isDeserializeProperty = false;

				if (deserializeProperty)
				{
					const DescribedBase* inst = static_cast<DescribedBase*>(instance.get()); // force static cast outside of the RBXASSERT block
					RBXASSERT(descriptor->isMemberOf(inst));

					if (descriptor == &deserializeProperty->getDescriptor() && inst == deserializeProperty->getInstance())
						isDeserializeProperty = true;
				}
				
				if (!isDeserializeProperty && (descriptor->canStreamWrite() || descriptor == &Instance::propParent) && !isSerializePending(instance.get()))
				{
					const DescribedBase* inst = static_cast<DescribedBase*>(instance.get());
					RBXASSERT(descriptor->isMemberOf(inst));

					Player* targetPlayer = findTargetPlayer();

					if (targetPlayer && targetPlayer->getCharacter() && instance->isDescendentOf(targetPlayer->getCharacter()))
					{
						pendingItems.push_front(boost::shared_ptr<Item>(new ChangePropertyItem(*this, instance, *descriptor)));
					}
					else
					{
						pendingItems.push_back(boost::shared_ptr<Item>(new ChangePropertyItem(*this, instance, *descriptor)));
					}
				}
			}
		}

		void Replicator::Item::readItemType(RakNet::BitStream& stream, ItemType& value)
		{
			value = ItemTypeEnd;

			stream.ReadBits((unsigned char*)&value, 2, true);

			if (value < 1 || value > 3) // neither of Delete, New, ChangeProperty
			{
				stream.Read(value);
			}
		}

		void Replicator::Item::writeItemType(RakNet::BitStream& stream, ItemType value)
		{
			if (value >= 1 && value <= 3) // Delete, New, ChangeProperty
			{
				stream.WriteBits((unsigned char*)&value, 2, true);
			}
			else
			{
				unsigned char zeroes = 0;
				stream.WriteBits(&zeroes, 2, true);
				stream.Write(value);
			}
		}

		Replicator::ItemSender::ItemSender(Replicator& replicator, RakPeerInterface* peer)
			: replicator(replicator),
			  peer(peer),
			  maxStreamSize(G3D::iRound(NetworkSettings::singleton().dataPacketSize * (peer->GetMTUSize(replicator.remotePlayerId) - 128))),
			  sentItems(false)
		{
		}

		Replicator::ItemSender::~ItemSender()
		{
			if (bitStream.GetNumberOfBitsUsed() > 0)
			{
				Item::writeItemType(bitStream, Item::ItemTypeEnd);
				peer->Send(&bitStream, MEDIUM_PRIORITY, RELIABLE_ORDERED, 0, replicator.remotePlayerId, false);
				bitStream.Reset();
			}
		}

		bool Replicator::ItemSender::send(Item& item)
		{
 if(!item.isReadyToSend())return false;
			if (bitStream.GetNumberOfBytesUsed() < maxStreamSize)
			{
				if (bitStream.GetNumberOfBitsUsed() == 0)
				{
					bitStream << (unsigned char)0x49;
				}

				item.write(bitStream);
				sentItems = true;

				return true;
			}
			else
			{
				return false;
			}
		}

		Replicator::JobSender::JobSender(Replicator& replicator, RakPeerInterface* peer)
			: replicator(replicator),
			  peer(peer),
			  firstA(NULL),
			  firstM(NULL),
			  packetPriority(MEDIUM_PRIORITY),
			  sentPacket(false),
			  hasOpenPacket(false),
			  bitStream(1364) // what
		{
		}

		Replicator::JobSender::~JobSender()
		{
			if (hasOpenPacket)
			{
				closePacket();
			}
		}

		void Replicator::JobSender::setPacketPriority(PacketPriority packetPriority)
		{
			if (this->packetPriority != packetPriority)
			{
				closePacket();
				this->packetPriority = packetPriority;
			}
		}

		void Replicator::JobSender::closePacket()
		{
			replicator.serializeId(bitStream, NULL);
			peer->Send(&bitStream, packetPriority, UNRELIABLE, 0, replicator.remotePlayerId, false);
			hasOpenPacket = false;
		}

		bool Replicator::JobSender::report(const Mechanism& m)
		{
			if (!hasOpenPacket)
			{
				bitStream.Reset();

				bitStream << (unsigned char)ID_TIMESTAMP;
				bitStream << RakNet::GetTime();
				bitStream << (unsigned char)ID_PHYSICS;

				hasOpenPacket = true;
				sentPacket = true;
			}

			replicator.sendPhysicsData(bitStream, m);
			replicator.serializeId(bitStream, NULL);

			return bitStream.GetNumberOfBytesUsed() < 1364u;
		}

		void Replicator::MarkerItem::write(RakNet::BitStream& bitStream)
		{
			writeItemType(bitStream, ItemTypeMarker);
			bitStream << (int)id;

			if (NetworkSettings::singleton().printInstances)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replication: Sending marker %d to %s", id, replicator.remotePlayerId.ToString());
			}

			replicator.onSentMarker(id);
		}

		Replicator::ReplicatorStatsItem::ReplicatorStatsItem(const boost::shared_ptr<Replicator>& replicator, const RakNetStatistics* statistics)
			: replicator(replicator),
			  statistics(statistics),
			  instanceCount(0),
			  instanceBits(0)
		{
			bps = createChildItem("Bytes/s");
			bps->createBoundChildItem<bool>("Bandwidth Exceeded", statistics->bandwidthExceeded);

			packetLoss = bps->createChildItem("Packet Loss");
			ping = createChildItem("Ping");

			Item* rep = createBoundChildItem(*replicator->profileReplication);

			rep->createBoundChildItem(*replicator->profileDataListening);
			rep->createBoundChildItem(*replicator->profileDataOut);
			rep->createBoundChildItem(*replicator->profilePhysicsOut);
			rep->createBoundChildItem(*replicator->profileDataIn);
			rep->createBoundChildItem(*replicator->profilePhysicsIn);

			instanceSize = rep->createChildItem("Instance size (In)");
			waitingRefs = createChildItem("Waiting Refs");
		}

		void Replicator::ReplicatorStatsItem::update()
		{
			if (replicator->peer)
			{
				bps->formatMem((size_t)statistics->bitsPerSecond / 8);

				ping->formatValue(
					replicator->peer->GetLastPing(replicator->remotePlayerId),
					"%d avg:%d best:%d",
					replicator->peer->GetLastPing(replicator->remotePlayerId),
					replicator->peer->GetAveragePing(replicator->remotePlayerId),
					replicator->peer->GetLowestPing(replicator->remotePlayerId)
				);

				waitingRefs->formatValue(replicator->numWaitingRefs());

				float ratio = (float)statistics->messagesTotalBitsResent / statistics->totalBitsSent;
				packetLoss->formatValue(ratio, "%.1g%%", ratio * 100.0);

				instanceSize->formatMem(instanceCount != 0 ? instanceBits / (instanceCount * 8) : 0);
			}
		}

		Replicator::ChangePropertyItem::ChangePropertyItem(Replicator& replicator, const boost::shared_ptr<const Instance>& instance, const Reflection::PropertyDescriptor& desc)
			: Item(replicator),
			  instance(instance),
			  desc(desc)
		{
		}

		

		
	}
}

namespace RBX { namespace Network { bool Replicator::sendItems(){Profiling::Mark mark(*profileDataOut,false); ItemSender sender(*this,peer); while(pendingItems.size()>0){boost::shared_ptr<Item> item=pendingItems.front(); if(item){if(!sender.send(*item))break;}pendingItems.pop_front();}return sender.sentItems;} }}

namespace RBX {namespace Network {bool Replicator::NewInstanceItem::isReadyToSend(){return replicator.idManager->requestIds(replicator.pendingNewInstances.size());}}}

namespace RBX {namespace Network {Replicator::NewInstanceItem::NewInstanceItem(Replicator& r,const boost::shared_ptr<Instance>& value):Item(r),instance(value){r.pendingNewInstances.insert(value.get());r.idManager->requestIds(r.pendingNewInstances.size());} Replicator::DeleteInstanceItem::DeleteInstanceItem(Replicator& r,const boost::shared_ptr<const Instance>& value):Item(r),instance(value){r.pendingDeleteInstances.insert(value.get());}}}

namespace RBX {namespace Network {bool Replicator::remoteDeleteOnDisconnect(const Instance* value)const{return value->isDescendentOf(players)||value==Players::findLocalCharacter(value);}}}
