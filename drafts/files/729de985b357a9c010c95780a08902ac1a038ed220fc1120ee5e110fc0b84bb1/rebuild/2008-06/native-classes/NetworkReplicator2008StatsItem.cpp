// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
#undef _RELEASEASSERT // 004b7f20 builds its ConstProperty without RBXASSERT(isMemberOf): 00570c40 has one caller in the exe
// 2008-06 native RBX::Network::Replicator::ReplicatorStatsItem rows that do not depend on the (partial) Replicator
// layout (inactive); evidence in native-headers/Network/Replicator2008.h. Verified by
// tests/record_native_network_replicator2008.py. Original bodies: Creatable<Instance>::create<ReplicatorStatsItem,
// shared_ptr<Replicator>, RakNetStatistics*> 004b7e50 (Replicator::createStatsItems 004b82d0 calls it) and
// shared_ptr<ReplicatorStatsItem>(ReplicatorStatsItem*, Creatable<Instance>::Deleter) 004acf50. The constructor
// 004b62c0 and update 004b6530 read Replicator members past +0x2b90 and stay open; the implicit destructor 004b6690,
// deleting destructor 004b6710 and its thunks are only emitted with the constructor's vtable.
// Replicator members here: getDefault 004b4bb0, getSharedDictionary 004b6730, writeProperties 004b7f20 (parked);
// serializeValue 004b6890.
#include "Network/Replicator2008.h"
#include "Network/NetworkSettings.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "util/standardout.h"
#include "BitStream.h"
#include "security/SecurityContext.h"
#include "v8datamodel/PartInstance.h"
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
		// 004b4bb0 (donor Replicator::getDefault; Impersonator(Replicator) 0042bc10, map find 00591bd0 and operator[]
		// 00592610 (both identical-code folded with other pointer-keyed maps), AbstractFactoryProduct<Instance>::create
		// 00420190, "Replication: Can't create default object of type %s" 00824de4 at MESSAGE_ERROR).
		const Instance* Replicator::getDefault(const Name& className)
		{
			Security::Impersonator impersonate(Security::Replicator);

			std::map<const Name*, boost::shared_ptr<Instance> >::iterator iter = defaultObjects.find(&className);

			if (iter == defaultObjects.end())
			{
				boost::shared_ptr<Instance> instance = AbstractFactoryProduct<Instance>::create(className);

				if (!instance)
				{
					StandardOut::singleton()->print(MESSAGE_ERROR, "Replication: Can't create default object of type %s", className.c_str());
				}

				defaultObjects[&className] = instance;
				return instance.get();
			}
			else
			{
				return iter->second.get();
			}
		}

		// 004b6730 (donor Replicator::getSharedDictionary; strings +0x2b90 find 00591bd0 / operator[] 00592610 (identical-
		// code folded), new(0x2a24) SharedStringDictionary 004b3d10, shared_count(SharedStringDictionary*) 004b5d20).
		SharedStringDictionary& Replicator::getSharedDictionary(const Reflection::PropertyDescriptor& descriptor)
		{
			std::map<const Reflection::PropertyDescriptor*, boost::shared_ptr<SharedStringDictionary> >::iterator iter = strings.find(&descriptor);

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

		// 004b6890 (donor Replicator::serializeValue). StringSender::serializeString 004a83e0 and IdSerializer::serializeRef
		// 004a8b90 are in AppUnit49C_2008IdSerializerTemplates.cpp. Branch order and callees read from the target:
		// singleton<std::string> 0056cdf0 -> getSharedDictionary 004b6730 + serializeString; <bool> 0056cc30 ->
		// getValue<bool> 004ad000 + operator<<(bool) 004a5b10; <int> 0056cbc0 -> 004ad060 + 004a61a0; <float> 0056cca0
		// -> 004ad0c0 + 004a6400; <double> 0056cd10 -> serialize<double> 004ae7b0; <BrickColor> 0056d120 -> 004a7570;
		// <Color3> 0056cf40 -> 004ada80; <Vector3> 0056ce60 -> PartInstance::prop_Size 00976148 ? writeBrickVector
		// 004a6700 (getValue<Vector3> 004accd0) : serialize<Vector3> 004acd30; <CoordinateFrame> 00599a00 -> 004adaa0;
		// dynamic_cast EnumPropertyDescriptor (0092fea4) -> serializeEnum 004a5a30; RefPropertyDescriptor (0092fe70) ->
		// serializeRef; <ContentId> 0056cd80 -> 004a6d00 (serialize<std::string>: the ContentId instance is identical-code
		// folded or the 2008 source streams the content string). The bool argument is never read in 2008.
		void Replicator::serializeValue(const Reflection::ConstProperty& property, bool, RakNet::BitStream& stream)
		{
			if (property.getDescriptor().type == Reflection::Type::singleton<std::string>())
				getSharedDictionary(property.getDescriptor()).serializeString(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<bool>())
				stream << property.getValue<bool>();
			else if (property.getDescriptor().type == Reflection::Type::singleton<int>())
				stream << property.getValue<int>();
			else if (property.getDescriptor().type == Reflection::Type::singleton<float>())
				stream << property.getValue<float>();
			else if (property.getDescriptor().type == Reflection::Type::singleton<double>())
				serialize<double>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<BrickColor>())
				serialize<BrickColor>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::Color3>())
				serialize<G3D::Color3>(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::Vector3>())
			{
				if (&property.getDescriptor() == &PartInstance::prop_Size)
					writeBrickVector(stream, property.getValue<G3D::Vector3>());
				else
					serialize<G3D::Vector3>(property, stream);
			}
			else if (property.getDescriptor().type == Reflection::Type::singleton<G3D::CoordinateFrame>())
				serialize<G3D::CoordinateFrame>(property, stream);
			else if (dynamic_cast<const Reflection::EnumPropertyDescriptor*>(&property.getDescriptor()))
				serializeEnum(property, stream);
			else if (dynamic_cast<const Reflection::RefPropertyDescriptor*>(&property.getDescriptor()))
				serializeRef(property, stream);
			else if (property.getDescriptor().type == Reflection::Type::singleton<ContentId>())
				serialize<std::string>(property, stream);
		}

		// 004b7f20 (name INFERRED, see Replicator2008.h; getDefault 004b4bb0, serializeValue 004b6890,
		// operator<<(bool) 004a5b10, NetworkSettings::singleton 0049e890 +0x131 / +0x132, StandardOut::print 005693a0).
		// PARKED, not exact (848 of 938 bytes): same control flow and calls, but the target inlines the StandardOut
		// shared_ptr release after the "1 bit" and "%d bits" prints (lock xadd, ebx = -1) and calls ~shared_ptr
		// 00600660 only after the "(default)" print; this compile calls 00600660 after all three prints.
		// Building the ConstProperty first and reading the descriptor through it gives the target's stack slots
		// (described instance at esp+0x14, end at the argument slot); first divergence is now insn 28 (004b7f75).
		// Rejected: ConstProperty from *iter (does not compile: Describing is Property), RBXASSERT(isMemberOf)
		// active (target has no 00570c40 call), "%d bits" branch written before the "(default)" branch (same object,
		// also with this form), a descriptor reference taken from property.getDescriptor() (first divergence insn 20).
		void Replicator::writeProperties(const Instance* instance, RakNet::BitStream& stream)
		{
			const Instance* defaultInstance = getDefault(instance->getClassName());

			Reflection::ConstPropertyIterator iter = instance->properties_begin();
			Reflection::ConstPropertyIterator end = instance->properties_end();
			for (; iter != end; ++iter)
			{
				Reflection::ConstProperty property(iter.getDescriptor(), instance);
				if (property.getDescriptor().canStreamWrite() && &property.getDescriptor() != &Instance::propParent)
				{
					if (typeid(bool) == property.getDescriptor().type.type)
					{
						serializeValue(property, false, stream);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, 1 bit", property.getDescriptor().type.name.c_str(), property.getDescriptor().name.c_str());
					}
					else if (defaultInstance && property.getDescriptor().equalValues(instance, defaultInstance))
					{
						stream << true;
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, 1 bit (default)", property.getDescriptor().type.name.c_str(), property.getDescriptor().name.c_str());
					}
					else
					{
						int bits = stream.GetNumberOfBitsUsed();
						stream << false;
						serializeValue(property, false, stream);
						if (NetworkSettings::singleton().printInstances && NetworkSettings::singleton().printProperties)
							StandardOut::singleton()->print(MESSAGE_INFO, "   write %s %s, %d bits", property.getDescriptor().type.name.c_str(), property.getDescriptor().name.c_str(), stream.GetNumberOfBitsUsed() - bits);
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
