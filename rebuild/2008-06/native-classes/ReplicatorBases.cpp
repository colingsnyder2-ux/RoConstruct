// 2008-06 native RBX::Network::Replicator base chain (inactive): the class-template instances that the
// Replicator constructor 004b9bd0 pulls in, DescribedNonCreatable<Replicator, IdSerializer, sReplicator>
// (constructor 004b9ad0) -> NonFactoryProduct<IdSerializer, sReplicator> (004b9570) -> IdSerializer
// (004b94a0) -> SharedStringDictionary (004b3d10) -> StringSender (004b3c90), and the matching destructors.
// The Replicator class itself is not recovered yet (its layout past +0x2b74 needs the physics sender/receiver,
// string dictionary and profiler types); this unit instantiates the base chain explicitly instead of through
// Replicator's constructor: these come out of this unit as COMDATs, a codegen analog, not their original unit.
// Verified by tests/record_native_replicator.py.
// >>> native-status (generated) -- do not edit >>>
// ReplicatorBases | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 1d9e7735 | roc native-status --write
#include "Network/IdSerializer.h"

namespace RBX
{
	namespace Network
	{
		class Replicator;
		extern const char sReplicator[];
		const char sReplicator[] = "NetworkReplicator"; // 008244e4 (RTTI $1?sReplicator@23@3QBDB; classDescriptor 004b3800)
	}

	// Template members the shared headers only declare (same definitions as NetworkPlayers.cpp / Feature.cpp):
	// className 004b95d0, getClassName 004b9670 for NonFactoryProduct<IdSerializer, sReplicator>.
	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

	template<class D, const char* N>
	const Name& NonFactoryProduct<D, N>::getClassName() const { return className(); }

	template class DescribedNonCreatable<Network::Replicator, Network::IdSerializer, Network::sReplicator>;
}
