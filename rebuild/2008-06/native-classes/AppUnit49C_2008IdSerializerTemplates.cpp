// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/../../../tools/rbxgs/Client/Network/raknet30/Source
// 2008-06 native STL instances of the Network/Streaming.cpp unit on the element types of RBX::Network::IdSerializer
// and StringSender (read-only native-headers/Network/IdSerializer.h), inside the application range 0049c000..004a8000
// (inactive). The original emits them for IdSerializer::resolvePendingBindings / deserializeInstanceRef and
// StringSender::send (callers 004a8110..004a9440, past this range): std::vector<IdSerializer::WaitItem> (0xc bytes:
// desc +0, shared_ptr<Instance> +4), std::map<Guid::Data, std::vector<WaitItem> > (IdSerializer +0x2b54) and the
// StringSender dictionary std::map<std::string, unsigned char> (+0x00). Explicit instantiations only (the usual access
// checks do not apply to names in an explicit instantiation, so the protected WaitItem can be named).
// Verified by tests/record_native_app_unit49c_2008.py.
// >>> native-status (generated) -- do not edit >>>
// AppUnit49C_2008IdSerializerTemplates | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 2e7ead5b | roc native-status --write
#include "Network/IdSerializer.h"
#include "AppUnit49C_2008/Streaming2008.h"
#include <BitStream.h>

// StringReceiver / StringSender members of the same Network/Streaming.cpp unit, in the original's address order.
// Shape after the donor tools/rbxgs/Client/Network/Streaming.cpp; 2008 keeps std::string strings[] arrays (see
// IdSerializer.h). The original's `stream << (unsigned char)x` is the same unit's operator<< 004a6350
// (AppUnit49C_2008Streaming.cpp), which it inlines to BitStream::Write<unsigned char> (WriteBits(&x, 8, true)); this
// unit does not define that operator, so the bodies call Write directly (a codegen analog of the inlined operator).
namespace RBX
{
	namespace Network
	{
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
