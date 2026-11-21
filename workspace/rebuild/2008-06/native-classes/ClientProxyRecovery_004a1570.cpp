// 2008-06 native RBX::Network::Server::ClientProxy (inactive): vftable slots 17 and 19 proved byte-equal;
// slot 16 (replicates, 004a3290, 170 bytes) PARKED — see parking evidence below.
//
// PARKED: 004a3290 slot 16 replicates(const Instance*) const
//   Target disassembly: sub esp,8; push esi/edi; __RTDynamicCast(object,0,&instanceType,&scriptType,0)
//     (MSVCR90 __RTDynamicCast at 0x6a17c6; type descriptors 0x92e1c8 scriptType, 0x92907c messageType);
//     if eax: [eax+0x14c]==0 ? [esi+0x130] : eax+0x138; call fn_004a2fa0 (std::map::find);
//     compare end iterator; else RTDynamicCast(messageType) sete al; ret 4.
//   Reads server (+0x2d70) -> Server::names std::set<std::string> at +0x164.
//   BLOCKED: Server::names (+0x164) is private in rebuild/2008-06/native-headers/Network/Server2008.h
//     and Script members +0x130 (embedded source), +0x138 (script id), +0x14c (size) are private
//     in rebuild/2008-06/native-headers/script/Script.h. Both headers are owned by another worker
//     and may not be edited by this lease. A clean reproduction needs either friend/access added by
//     the header owner, or raw-offset views (forbidden by project rules: no raw-offset member access,
//     no __emit/byte blobs/patched target bytes). Not three failed variants — blocked by private-member
//     access, not by compilation. Declare only; do not define until unblocked.
//   Identity row present (unverified lead): ?sub_004a3290@ClientProxy@Server@Network@RBX@@QAE_NPAVInstance@4@@Z -> 004a3290
//
// Slots proved byte-equal (bound in work/native-client/class-identity-bindings.json):
//   slot 17 004a1a30 findTargetPlayer() -> return remotePlayer.get();
//   slot 19 004a1570 onSentMarker(long id) -> sendPhysicsEnabled = true;
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#include "Network/ClientProxy2008.h"
#include "script/Script.h"
#include "v8datamodel/Message.h"

namespace RBX
{
	namespace Network
	{
		// slot 16 004a3290 (170 B): dynamic_cast<const Script*> (type descriptors 0092907c Instance -> 0092e1c8 Script);
		// a script replicates when its name is in the Server's script-name set (server +0x2d70, names +0x164, find
		// 004a2fa0). The name is the one Server::registerScript 004a31d0 inserted: the embedded source (*Script +0x130)
		// when the script id (+0x138, size +0x14c) is empty, else the id. Any other instance replicates unless it is a
		// Message (dynamic_cast to 00939b1c, sete). ClientProxy is nested in Server, so it reads the private name set.
		bool Server::ClientProxy::replicates(const Instance* instance) const
		{
			if (const Script* script = dynamic_cast<const Script*>(instance))
			{
				if (script->getScriptId().isNull())
					return server->names.find(script->getEmbeddedCode()) != server->names.end();
				else
					return server->names.find(script->getScriptId().toString()) != server->names.end();
			}
			if (dynamic_cast<const Message*>(instance))
				return false;
			return true;
		}

		// slot 17 004a1a30: returns the cached remote player (+0x2d68).
		// INFERRED: name from the slot; the body returns remotePlayer's stored pointer.
		Player* Server::ClientProxy::findTargetPlayer()
		{
			return remotePlayer.get();
		}

		// slot 19 004a1570: marks that a marker was sent (sendPhysicsEnabled +0x2cd0).
		// INFERRED: name from the slot; the inherited Replicator::sendPhysicsEnabled flag is set.
		void Server::ClientProxy::onSentMarker(long id)
		{
			sendPhysicsEnabled = true;
		}
	}
}
