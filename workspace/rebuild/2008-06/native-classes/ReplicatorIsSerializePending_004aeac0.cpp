// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native RBX::Network::Replicator::isSerializePending (inactive), declared in Network/Replicator2008.h.
//
// 004aeac0  RBX::Network::Replicator::isSerializePending(const Instance*) const - INFERRED identity (registry
//   placeholder func_004aeac0): donor tools/rbxgs/Client/Network/Replicator.cpp (verbatim body below) and the donor
//   Replicator.h public declaration `bool isSerializePending(const Instance* instance) const;`.
// Evidence (2008-06 binary):
//   * 74 bytes, ret 4, one stack parameter, this in ecx, no writes - a const member taking a 4-byte pointer.
//   * reads [ecx+0x2c90] / [ecx+0x2ca8]: Replicator::pendingNewInstances (+0x2c90, its head node +0x18) as declared
//     in Network/Replicator2008.h; 004ae060 is that set's out-of-line find (_SECURE_SCL checked iterator compare).
//   * callers: RoundRobinPhysicsSender::sendPhysicsData 004caaf0 (this = [sender+0x4] = Replicator*) and the
//     PhysicsSender row 004ca980 (this = [sender+0x3c]); both pass one PartInstance* on the stack.
#include "Network/Replicator2008.h"

namespace RBX
{
	namespace Network
	{
		// 004aeac0
		bool Replicator::isSerializePending(const Instance* instance) const
		{
			return pendingNewInstances.find(instance) != pendingNewInstances.end();
		}
	}
}
