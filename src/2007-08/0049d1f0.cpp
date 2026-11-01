// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs-net roc_espeon_aug2007_network_server_historical_send_top_b201551b22d5e5e1.cpp

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
#pragma include_alias("Streaming.h","roc_espeon_aug2007_idserializer_historical_header_f589f1aef1ff8179.cpp")
#pragma include_alias("Replicator.h","roc_espeon_aug2007_replicator_idserializer_header_6884f13180394e4c.cpp")
#pragma include_alias("Server.h","roc_espeon_aug2007_server_idmanager_header_18c2cbea4e856def.cpp")
#pragma include_alias("IdManager.h","roc_espeon_aug2007_idmanager_historical_header_bf92b6db84c275bf.cpp")

#include "v8datamodel/PartInstance.h"
#include <RakPeer.h>
#include "Server.h"
#include "IdManager.h"
#include "NetworkSettings.h"
#include "PacketIds.h"
#include "API.h"
#include "util/Http.h"
#include "util/standardout.h"
#include <boost/thread.hpp>

static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int, int), 2> server_startFunction(&RBX::Network::Server::start, "Start", "port", "threadSleepTime", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(int), 1>  f_disconnect(&RBX::Network::Server::stop, "Stop", "blockDuration", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);
static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, int(void), 0> f_GetClientCount(&RBX::Network::Server::getClientCount, "GetClientCount", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

static RBX::Reflection::BoundFuncDesc<RBX::Network::Server, void(std::string, std::string, int), 3> server_setServerManagerPingFunction(&RBX::Network::Server::setServerManagerPing, "SetServerManagerPing", "pingUrl", "publicIP", "thumbnailId", RBX::Reflection::FunctionDescriptor::NeedTrustedCaller);

static bool isReplicator(boost::shared_ptr<RBX::Instance> instance)
{
	return dynamic_cast<const RBX::Network::Replicator*>(instance.get()) != NULL;
}

namespace RBX
{
	namespace Network
	{
		Server::Server()
			: outgoingPort(0)
		{
			setName("NetworkServer");
			rakPeer->SetMaximumIncomingConnections(32);
			rakPeer->SetIncomingPassword(API::version.c_str(), (int)API::version.size());
			updateLogger();
		}

		Server::~Server() {}

		void Server::stop(int blockDuration)
		{
			if (rakPeer->IsActive())
				rakPeer->Shutdown(blockDuration);

			removeAllChildren();
		}

		void Server::start(int port, int threadSleepTime)
		{
			SocketDescriptor d(port, "");

			if (!rakPeer->Startup(32, threadSleepTime, &d, 1))
				throw std::runtime_error("Failed to start network server");

			outgoingPort = port;
			StandardOut::singleton()->print(MESSAGE_INFO, "Starting network server on port %d", port);

			unsigned numAddresses = rakPeer->GetNumberOfAddresses();

			StandardOut::singleton()->print(MESSAGE_INFO, "IP addresses:");

			for (unsigned i = 0; i < numAddresses; i++)
			{
				StandardOut::singleton()->print(MESSAGE_INFO, "%s", rakPeer->GetLocalIP(i));
			}

			updateNetworkSimulator();
		}

		int Server::getClientCount()
		{
			if (getChildren())
			{
				return std::count_if(getChildren()->begin(), getChildren()->end(), &isReplicator);
			}
			else
			{
				return 0;
			}
		}

		void Server::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
		{
			if (oldProvider)
			{
				players->setConnection(NULL);

				if (rakPeer->IsActive())
					rakPeer->Shutdown(1000);

				removeAllChildren();

				players.reset();
			}

			Peer::onServiceProvider(oldProvider, newProvider);

			if (newProvider)
			{
				players = shared_from(newProvider->create<Players>());

				players->setConnection(peerInterface());
			}
		}

		void Server::setServerManagerPing(std::string pingUrl, std::string publicIP, int thumbnailId)
		{
			pingThread.reset(new worker_thread(boost::bind(&Server::ping, boost::weak_ptr<Server>(shared_from(this)), publicIP, thumbnailId, pingUrl), "rbx_serverping"));
		}

		bool Server::serverIsPresent(const Instance* context, bool testInDatamodel)
		{
			const ServiceProvider* sp = ServiceProvider::findServiceProvider(context);
			RBXASSERT(!testInDatamodel || sp);

			return ServiceProvider::find<Server>(sp) != NULL;
		}

		PluginReceiveResult Server::OnReceive(RakPeerInterface* peer, Packet* packet)
		{
			PluginReceiveResult result = PluginInterface::OnReceive(peer, packet);
			if (result != RR_CONTINUE_PROCESSING)
				return result;

			if (packet->data[0] == ID_NEW_INCOMING_CONNECTION)
			{
				try
				{
					StandardOut::singleton()->print(MESSAGE_INFO, "New connection from %s\n", packet->systemAddress.ToString());

					boost::shared_ptr<ClientProxy> proxy = Creatable::create<ClientProxy>(packet->systemAddress, this);
					proxy->setParent(this);
					proxy->sendTop();

					event_IncommingConnection.fire(this, packet->systemAddress.ToString(), proxy);
				}
				catch (std::exception& e)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Server::OnReceive packet %d: %s", packet->data[0], e.what());
				}
			}

			return RR_CONTINUE_PROCESSING;
		}

		worker_thread::work_result Server::ping(boost::weak_ptr<Server> server, std::string publicIP, int thumbnailId, std::string pingUrl)
		{
			try
			{
				std::stringstream nameStream;

				{
					TextXmlWriter writer(nameStream);

					XmlElement root(Name::declare("root", -1));

					boost::shared_ptr<Server> s = server.lock();
					if (!s)
						return worker_thread::done;

					root.addChild(new XmlElement(Name::declare("server", -1), publicIP));
					root.addChild(new XmlElement(Name::declare("port", -1), s->outgoingPort));
					root.addChild(new XmlElement(Name::declare("numPlayers", -1), s->players->numPlayers()));
					root.addChild(new XmlElement(Name::declare("maxPlayers", -1), s->players->getMaxPlayers()));
					root.addChild(new XmlElement(Name::declare("thumbnailId", -1), thumbnailId));

					writer.serialize(&root);

					nameStream.flush();
				}

				std::string response;
				Http(pingUrl).post(nameStream, false, response);
			}
			catch (std::exception& exp)
			{
				StandardOut::singleton()->print(MESSAGE_ERROR, exp);
			}

			boost::xtime xt;
			boost::xtime_get(&xt, boost::TIME_UTC);

			xt.sec += 10;

			boost::thread::sleep(xt);

			return worker_thread::more;
		}

		Server::ClientProxy::ClientProxy(SystemAddress systemAddress, Server* server)
			: Replicator(systemAddress, server->peerInterface(),server),
			  server(server)
		{
		}
		
		Server::ClientProxy::~ClientProxy() {}

		void Server::ClientProxy::onSentMarker(long id)
		{
			sendPhysicsEnabled = true;
		}

		
}}

namespace RBX { namespace Network { void Server::ClientProxy::sendTop(){ RakNet::BitStream bitStream; bitStream << (unsigned char)0x47; std::vector<Instance*>::iterator end=replicationContainers.end(); for(std::vector<Instance*>::iterator iter=replicationContainers.begin();iter!=end;iter++){serializeId(bitStream,*iter);}peer->Send(&bitStream,HIGH_PRIORITY,RELIABLE_ORDERED,0,remotePlayerId,false); } }}
