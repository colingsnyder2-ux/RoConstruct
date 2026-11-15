// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#undef _RELEASEASSERT // 004b7f20 builds its ConstProperty without RBXASSERT(isMemberOf): 00570c40 has one caller in the exe
// 2008-06 native RBX::Network::Replicator::ReplicatorStatsItem rows that do not depend on the (partial) Replicator
// layout (inactive); evidence in native-headers/Network/Replicator2008.h. Verified by
// tests/record_native_network_replicator2008.py. Original bodies: Creatable<Instance>::create<ReplicatorStatsItem,
// shared_ptr<Replicator>, RakNetStatistics*> 004b7e50 (Replicator::createStatsItems 004b82d0 calls it) and
// shared_ptr<ReplicatorStatsItem>(ReplicatorStatsItem*, Creatable<Instance>::Deleter) 004acf50. The constructor
// 004b62c0 and update 004b6530 read Replicator members past +0x2b90 and stay open; the implicit destructor 004b6690,
// deleting destructor 004b6710 and its thunks are only emitted with the constructor's vtable.
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "util/standardout.h"
#include "BitStream.h"
#include <typeinfo>

namespace RBX
{
	// Same inline definition as AppUnit558_2008Instance.cpp (reflection/member.h only declares it); the target inlines it.
	template<>
	inline Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator&
	Reflection::MemberDescriptorContainer<Reflection::PropertyDescriptor>::ConstIterator::operator++()
	{
		++iter;
		return *this;
	}

	namespace Network
	{
		// 004b7f20 (name INFERRED, see Replicator2008.h; getDefault 004b4bb0, serializeValue 004b6890,
		// operator<<(bool) 004a5b10, NetworkSettings::singleton 0049e890 +0x131 / +0x132, StandardOut::print 005693a0).
		// PARKED, not exact (839 of 938 bytes): same control flow and calls, but the target inlines the StandardOut
		// shared_ptr release after the "1 bit" and "%d bits" prints and calls ~shared_ptr 00600660 after the
		// "(default)" print, and keeps the iterator in ebp; this compile calls 00600660 for both later prints.
		// Rejected: ConstProperty from *iter (does not compile: Describing is Property), RBXASSERT(isMemberOf)
		// active (target has no 00570c40 call), "%d bits" branch written before the "(default)" branch (same object).
		void Replicator::writeProperties(const Instance* instance, RakNet::BitStream& stream)
		{
			const Instance* defaultInstance = getDefault(instance->getClassName());

			Reflection::ConstPropertyIterator iter = instance->properties_begin();
			Reflection::ConstPropertyIterator end = instance->properties_end();
			for (; iter != end; ++iter)
			{
				const Reflection::PropertyDescriptor& descriptor = iter.getDescriptor();
				Reflection::ConstProperty property(descriptor, instance);
				if (descriptor.canStreamWrite() && &descriptor != &Instance::propParent)
				{
					if (typeid(bool) == descriptor.type.type)
					{
						serializeValue(property, false, stream);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, 1 bit", descriptor.type.name.c_str(), descriptor.name.c_str());
					}
					else if (defaultInstance && descriptor.equalValues(instance, defaultInstance))
					{
						stream << true;
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, 1 bit (default)", descriptor.type.name.c_str(), descriptor.name.c_str());
					}
					else
					{
						int bits = stream.GetNumberOfBitsUsed();
						stream << false;
						serializeValue(property, false, stream);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, %d bits", descriptor.type.name.c_str(), descriptor.name.c_str(), stream.GetNumberOfBitsUsed() - bits);
					}
				}
			}
		}
	}

	template boost::shared_ptr<Network::Replicator::ReplicatorStatsItem>
	Creatable<Instance>::create<Network::Replicator::ReplicatorStatsItem, boost::shared_ptr<Network::Replicator>,
								RakNetStatistics*>(boost::shared_ptr<Network::Replicator>, RakNetStatistics*); // 004b7e50
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::Network::Replicator::ReplicatorStatsItem>;
template class boost::shared_ptr<RBX::Network::Replicator>;
