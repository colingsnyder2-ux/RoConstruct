#pragma once
// >>> native-status (generated) -- do not edit >>>
// ReplicatorMarker | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 3fbb7a70 | roc native-status --write
// 2008-06 native RBX::Network::Marker (inactive). Shape after the donor tools/rbxgs/Client/Network/Replicator.h
// (where Marker lives with Replicator; kept in its own header so the donor Replicator.h is not shadowed).
// Every base, field and size below is read from the 2008-06 binary:
//   RTTI       vtable 0082529c .?AVMarker@Network@RBX@@ (7 bases): DescribedNonCreatable<Marker, DescribedBase,
//              sMarker> (name mangled $1?sMarker@23@3QBDB: a const char array), private noncopyable (mdisp 0xc).
//              One slot: scalar deleting destructor 004b8600 (calls ~SignalSource 0056bd40 directly).
//   size       0x10: newMarker 004b9190 allocates 0x10 and calls the constructor 004b9140.
//   fields     constructor 004b9140: NonFactoryProduct<DescribedBase, sMarker> 004b85b0, descriptor
//              (classDescriptor 004b18d0) at +0x8, then +0xc bool returned = false.
#include "reflection/reflection.h"
#include "util/Object.h"
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>

struct NativeReplicatorLayout;

namespace RBX
{
	namespace Network
	{
		extern const char sMarker[];

		class Marker : public DescribedNonCreatable<Marker, Reflection::DescribedBase, sMarker>, private boost::noncopyable
		{
			friend struct ::NativeReplicatorLayout; // tests/NativeReplicatorLayout.cpp offset asserts
		private:
			bool returned;                                                            // +0xc

		private:
			Marker()                                                                  // 004b9140
				: returned(false)
			{
			}

		public:
			static boost::shared_ptr<Marker> newMarker()                              // 004b9190
			{
				return boost::shared_ptr<Marker>(new Marker);
			}
		};
	}
}
