// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native STL instances of the Network/Streaming.cpp unit on the element types of RBX::Network::IdSerializer
// and StringSender (read-only native-headers/Network/IdSerializer.h), inside the application range 0049c000..004a8000
// (inactive). The original emits them for IdSerializer::resolvePendingBindings / deserializeInstanceRef and
// StringSender::send (callers 004a8110..004a9440, past this range): std::vector<IdSerializer::WaitItem> (0xc bytes:
// desc +0, shared_ptr<Instance> +4), std::map<Guid::Data, std::vector<WaitItem> > (IdSerializer +0x2b54) and the
// StringSender dictionary std::map<std::string, unsigned char> (+0x00). Explicit instantiations only (the usual access
// checks do not apply to names in an explicit instantiation, so the protected WaitItem can be named).
// Verified by tests/record_native_app_unit49c_2008.py.
#include "Network/IdSerializer.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include "reflection/property.h"
#include <BitStream.h>
#include <boost/bind.hpp>
#include <algorithm>
#include <stdexcept>

// StringReceiver / StringSender members of the same Network/Streaming.cpp unit, in the original's address order.
// Shape after the donor tools/rbxgs/Client/Network/Streaming.cpp; 2008 keeps std::string strings[] arrays (see
// IdSerializer.h). The original's `stream << (unsigned char)x` is the same unit's operator<< 004a6350
// (AppUnit49C_2008Streaming.cpp), which it inlines to BitStream::Write<unsigned char> (WriteBits(&x, 8, true)); this
// unit does not define that operator, so the bodies call Write directly (a codegen analog of the inlined operator).
namespace RBX
{
	namespace Network
	{
		// Donor Streaming.cpp static IdSerializer::setRefValue (cdecl, 004a6de0): RefPropertyDescriptor slot 0x34 with
		// both Instance pointers converted to DescribedBase (NULL-checked +0x14). Bound by resolvePendingBindings 004a9250.
		void IdSerializer::setRefValue(WaitItem& wi, Instance* instance)                      // 004a6de0
		{
			wi.desc->setRefValue(wi.instance.get(), instance);
		}

		void StringReceiver::receive(RakNet::BitStream& stream, std::string& value)          // 004a6e20
		{
			unsigned char id;
			stream >> id;                                                                     // 004a6380

			if (id == 0)
			{
				value.clear();
			}
			else if (id >> 7)
			{
				stream >> value;                                                              // 004a6610
				strings[id & 127] = value;
			}
			else
			{
				value = strings[id];
			}
		}

		void StringReceiver::receive(RakNet::BitStream& stream, const Name*& value)          // 004a6f70
		{
			std::string s;
			receive(stream, s);

			value = &Name::declare(s.c_str(), -1);                                            // 00553f90
		}

		// 004a70b0 (donor Streaming.cpp IdSerializer::deserializeId; identity: thiscall ret 8, receive(const Name*&)
		// 004a6f70 on scopeNames' StringReceiver (+0x130 + 0xe24 = +0xf54), Name::getNullName 00554270, then
		// BitStream::ReadBits 004a5210 (24 bits, right-aligned). 2008 throws on a short read: string 00823e90
		// "BitStream >> RBX::Guid::Data failed" (std::runtime_error, throw info 008d1bc8).
		void IdSerializer::deserializeId(RakNet::BitStream& stream, Guid::Data& id)
		{
			scopeNames.receive(stream, id.scope);
			if (id.scope != &Name::getNullName())
			{
				id.index = 0;
				if (!stream.ReadBits((unsigned char*)&id.index, 24))
					throw std::runtime_error("BitStream >> RBX::Guid::Data failed");
			}
			else
			{
				id.index = 0;
			}
		}

		bool StringSender::trySend(RakNet::BitStream& stream, const std::string& value)      // 004a7ba0
		{
			if (value == "")
			{
				stream.Write((unsigned char)0);
				return true;
			}

			std::map<std::string, unsigned char>::const_iterator iter = dictionary.find(value);

			if (iter == dictionary.end())
			{
				return false;
			}
			else
			{
				stream.Write(iter->second);
				return true;
			}
		}

		// 2008 differs from the donor: the new entry is inserted with the current lastIndex, the evicted string is
		// erased afterwards (map erase(key) 004a7d30) and lastIndex advances last.
		void StringSender::send(RakNet::BitStream& stream, const std::string& value)         // 004a7e20
		{
			if (value == "")
			{
				stream.Write((unsigned char)0);
				return;
			}

			std::pair<std::map<std::string, unsigned char>::iterator, bool> pair =
				dictionary.insert(std::pair<const std::string, unsigned char>(value, (unsigned char)lastIndex)); // 004a7a30

			if (!pair.second)
			{
				stream.Write(pair.first->second);
			}
			else
			{
				dictionary.erase(strings[lastIndex]);
				strings[lastIndex] = value;

				stream.Write((unsigned char)(lastIndex | 0x80));
				stream << value;                                                              // 004a6560
				lastIndex = lastIndex % 127 + 1;
			}
		}

		// Donor Streaming.cpp StringSender::serializeString: the instance goes DescribedBase -> Instance -> DescribedBase
		// (two NULL-checked +-0x14 adjustments before descriptor slot 0x1c getStringValue), then send 004a7e20.
		void StringSender::serializeString(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream) // 004a83e0
		{
			const Instance* instance = static_cast<const Instance*>(property.getInstance());
			const Reflection::PropertyDescriptor& desc = property.getDescriptor();

			std::string value = desc.getStringValue(instance);
			send(bitStream, value);
		}

		// Donor Streaming.cpp IdSerializer::serializeRef: RefPropertyDescriptor slot 0x30 getRefValue, NULL-checked -0x14
		// to Instance, then serializeId 004a8ae0.
		void IdSerializer::serializeRef(const Reflection::ConstProperty& property, RakNet::BitStream& bitStream) // 004a8b90
		{
			const Reflection::RefPropertyDescriptor& prop = static_cast<const Reflection::RefPropertyDescriptor&>(property.getDescriptor());
			serializeId(bitStream, (Instance*)prop.getRefValue(property.getInstance()));
		}

#ifdef NATIVE_GUID_REGISTRY_LOOKUP
		// BLOCKED: both bodies call the static GuidItem<Instance> registry lookup 0049ba80 (cdecl, ret 0: returns true
		// with NULL for the null scope Name 00554270, else locks the registry mutex at singleton 009705e8 +0x20 and finds
		// the Guid::Data), which core util/GuidItem.h does not declare. Proposal: declare it there as
		// `static bool sub_0049ba80(const Guid::Data& id, T*& item); // INFERRED: 0049ba80` (placeholder name, the
		// sub_004b3dd0 pattern); this guard's spelling of the call follows that proposal.

		// 004a8b60 (donor Streaming.h IdSerializer::deserializeInstanceRef(stream, Instance*&, Guid::Data&); identity:
		// ret 0xc, `this` passed through unchanged to deserializeId 004a70b0, then the registry lookup 0049ba80(id,
		// instance) whose bool is returned; callers Replicator::readChangedProperty 004b7a30 / readInstanceDelete 004b0800).
		bool IdSerializer::deserializeInstanceRef(RakNet::BitStream& stream, Instance*& instance, Guid::Data& id)
		{
			deserializeId(stream, id);
			return GuidItem<Instance>::sub_0049ba80(id, instance);
		}
#endif

		// 004a9250 (donor Streaming.cpp IdSerializer::resolvePendingBindings; identity: waitItems +0x2b54 find 004a7b20,
		// std::for_each 004a7920 over the WaitItem vector with boost::bind(&setRefValue 004a6de0, _1, instance), then
		// erase(iterator) 004a8d50; ret 0xc for the by-value Guid::Data).
		void IdSerializer::resolvePendingBindings(Instance* instance, Guid::Data id)
		{
			std::map<Guid::Data, std::vector<WaitItem> >::iterator iter = waitItems.find(id);
			if (iter != waitItems.end())
			{
				std::for_each(iter->second.begin(), iter->second.end(), boost::bind(&IdSerializer::setRefValue, _1, instance));
				waitItems.erase(iter);
			}
		}

#ifdef NATIVE_GUID_REGISTRY_LOOKUP
		// 004a9440 (donor Streaming.h IdSerializer::deserializeRef; identity: caller Replicator::deserializeValue 004b6ab0
		// (Ref branch), deserializeId 004a70b0, registry lookup 0049ba80, RefPropertyDescriptor slot 0x34 setRefValue,
		// else a WaitItem {desc, shared_from<Instance> 00618a40} appended to waitItems[id] (operator[] 004a9320,
		// push_back 004a8790)). BLOCKED on the 0049ba80 declaration (see deserializeInstanceRef above).
		void IdSerializer::deserializeRef(Reflection::Property& property, RakNet::BitStream& stream)
		{
			Guid::Data id;
			deserializeId(stream, id);

			if (Instance* instance = static_cast<Instance*>(property.getInstance()))
			{
				const Reflection::RefPropertyDescriptor& desc = static_cast<const Reflection::RefPropertyDescriptor&>(property.getDescriptor());
				Instance* target;
				if (GuidItem<Instance>::sub_0049ba80(id, target))
				{
					desc.setRefValue(instance, target);
				}
				else
				{
					WaitItem item = { &desc, shared_from(instance) };
					waitItems[id].push_back(item);
				}
			}
		}
#endif
	}
}


template class std::vector<RBX::Network::IdSerializer::WaitItem>;
template class std::map<RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem> >;
template class std::map<std::string, unsigned char>;
// std::map derives from std::_Tree (VS2008 <xtree>); an explicit instantiation of the map does not instantiate the
// members of its base, so the trees are instantiated as well.
template class std::_Tree<std::_Tmap_traits<RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem>,
	std::less<RBX::Guid::Data>, std::allocator<std::pair<const RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem> > >, false> >;
template class std::_Tree<std::_Tmap_traits<std::string, unsigned char, std::less<std::string>,
	std::allocator<std::pair<const std::string, unsigned char> >, false> >;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Network::IdSerializer::WaitItem> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> > >;
template class std::_Revranit<std::_Vector_const_iterator<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::iterator<std::random_access_iterator_tag,RBX::Network::IdSerializer::WaitItem,int,RBX::Network::IdSerializer::WaitItem const *,RBX::Network::IdSerializer::WaitItem const &> >;
template class std::_Revranit<std::_Vector_iterator<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::iterator<std::random_access_iterator_tag,RBX::Network::IdSerializer::WaitItem,int,RBX::Network::IdSerializer::WaitItem *,RBX::Network::IdSerializer::WaitItem &> >;
template class std::_Tmap_traits<RBX::Guid::Data,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >,0>;
template class std::_Vector_const_iterator<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >;
template class std::_Vector_iterator<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Guid::Data,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,unsigned char,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> >;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Guid::Data,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<RBX::Guid::Data,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<RBX::Guid::Data,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >,0> >::iterator,std::_Tree<std::_Tmap_traits<RBX::Guid::Data,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> >,std::less<RBX::Guid::Data>,std::allocator<std::pair<RBX::Guid::Data const ,std::vector<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > > >,0> >::iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,unsigned char,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> >,0> >::const_iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,unsigned char,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> >,0> >::const_iterator>;
template class std::pair<std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,unsigned char,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> >,0> >::iterator,std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,unsigned char,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,unsigned char> >,0> >::iterator>;
template class std::reverse_iterator<std::_Vector_const_iterator<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > >;
template class std::reverse_iterator<std::_Vector_iterator<RBX::Network::IdSerializer::WaitItem,std::allocator<RBX::Network::IdSerializer::WaitItem> > >;
