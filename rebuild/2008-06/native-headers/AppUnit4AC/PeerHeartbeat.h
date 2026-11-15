#pragma once
// 2008-06 native declaration used by Peer::onEvent(const RunService*, Heartbeat) 004add50 (inactive;
// native-classes/AppUnit4ACPeerHeartbeat.cpp). A new, non-colliding header (no donor header has this path).
//   checkDisconnect 004aaf50 (cdecl, one Instance* argument; the address onEvent pushes for for_eachChild 0045c470):
//   dynamic_cast<Replicator*>(instance) (__RTDynamicCast 006a17c6, type descriptors 0092907c Instance / 00938db4
//   Replicator), then `if (repl && repl-><bool +0x2d4d>) repl->setParent(NULL)` (setParent 0055a8f0). Declared only:
//   its body reads a Replicator member past +0x2b90 that native-headers/Network/Replicator2008.h leaves pending.
//   In the donor tools/rbxgs Client/Network/Replicator.cpp it is a file-static function of the Peer unit.
namespace RBX
{
	class Instance;
}

void checkDisconnect(RBX::Instance* instance);                                    // 004aaf50 (declared only)
