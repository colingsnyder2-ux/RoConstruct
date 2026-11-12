// from server: 100% by EspClaude
// from server: 75% by EspClaude
// from server: 100% by colin
// roc-cl: 50727
// roc-lang: cpp
// roc-lib: rbxgs-net-dll roc_claude_fdcbd9bfdaeed71a.cpp

// Candidate translation unit (score above; library headers required).
#include <queue>
#include <BitStream.h>
#include <RakPeerInterface.h>
#include "Streaming.h"
#include "NetworkSettings.h"
#include "util/standardout.h"
namespace RBX { namespace Network {
extern const char* sMarker;

		class Marker : public DescribedNonCreatable<Marker, Reflection::DescribedBase, &sMarker>, private boost::noncopyable
		{
		private:
			bool returned;
		public:
			static Reflection::SignalDesc<Marker, void(void)> event_Returned;
			static Reflection::SignalDesc<Marker, void(float)> event_Progress;

		private:
			Marker()
				: returned(false)
			{
			}
		public:

#pragma warning (push)
#pragma warning (disable : 4311) // warning C4311: 'reinterpret_cast' : pointer truncation from 'const RBX::Network::Marker *const ' to 'long'

			long id() const
			{
				return reinterpret_cast<long>(this);
			}

#pragma warning (pop)

			void fireReturned();

		public:
			static boost::shared_ptr<Marker> newMarker()
			{
				return boost::shared_ptr<Marker>(new Marker);
			}
			static Marker* fromId(long);
		};

		
// Opaque receiver; exact nonvirtual declaration from native Replicator.h.
class Replicator { public: boost::shared_ptr<Reflection::DescribedBase> sendMarker(); };
boost::shared_ptr<Reflection::DescribedBase> Replicator::sendMarker()
		{
			boost::shared_ptr<Marker> marker = Marker::newMarker();

			RakNet::BitStream bitStream;
			bitStream << (unsigned char)0x4a /* target marker packet ID (2007-08) */;
			bitStream << (int)marker->id();

			{
				StandardOut::singleton()->print(MESSAGE_INFO, "Replicator: Requesting Marker %d of %s", (int)marker->id(), (*reinterpret_cast<SystemAddress*>(reinterpret_cast<char*>(this) + 0x1e18)).ToString());
			}

			(*reinterpret_cast<std::queue<boost::shared_ptr<Marker>>*>(reinterpret_cast<char*>(this) + 0x1dd8)).push(marker);
			(*reinterpret_cast<RakPeerInterface**>(reinterpret_cast<char*>(this) + 0x1e14))->Send(&bitStream, HIGH_PRIORITY, RELIABLE, 0, (*reinterpret_cast<SystemAddress*>(reinterpret_cast<char*>(this) + 0x1e18)), false);

			return marker;
		}

		

}}
