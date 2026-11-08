// 2008-06 native RBX::Network::Marker (inactive); evidence in native-headers/Network/ReplicatorMarker.h. Verified by
// tests/record_native_replicator.py. Marker's members are inline (donor Replicator.h); in 2008 the Replicator unit
// emits them because Replicator::sendMarker 004b9210 calls newMarker 004b9190. Replicator itself is not recovered
// yet, so this unit takes newMarker's address (nativeReplicatorNewMarker, not an original symbol) to emit the same
// COMDAT bodies (newMarker 004b9190, Marker() 004b9140, NonFactoryProduct<DescribedBase, sMarker>() 004b85b0,
// ~Marker scalar deleting 004b8600, shared_count<Marker> 004ac040): a codegen analog, not the original unit.
#include "Network/ReplicatorMarker.h"

namespace RBX
{
	namespace Network
	{
		const char sMarker[] = "NetworkMarker"; // 008244f8 (classDescriptor 004b18d0)

		// Dynamic initializer 007f2290 (vtable 00824c80, atexit 007fc2e0).
		static Reflection::SignalDesc<Marker, void(void)> event_Received("Received");

		extern boost::shared_ptr<Marker> (*nativeReplicatorNewMarker)();
		boost::shared_ptr<Marker> (*nativeReplicatorNewMarker)() = &Marker::newMarker;
	}
}
