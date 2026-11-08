// 2008-06 native STL instances of the Network/Streaming.cpp unit on the element types of RBX::Network::IdSerializer
// and StringSender (read-only native-headers/Network/IdSerializer.h), inside the application range 0049c000..004a8000
// (inactive). The original emits them for IdSerializer::resolvePendingBindings / deserializeInstanceRef and
// StringSender::send (callers 004a8110..004a9440, past this range): std::vector<IdSerializer::WaitItem> (0xc bytes:
// desc +0, shared_ptr<Instance> +4), std::map<Guid::Data, std::vector<WaitItem> > (IdSerializer +0x2b54) and the
// StringSender dictionary std::map<std::string, unsigned char> (+0x00). Explicit instantiations only (the usual access
// checks do not apply to names in an explicit instantiation, so the protected WaitItem can be named).
// Verified by tests/record_native_app_unit49c_2008.py.
#include "Network/IdSerializer.h"

template class std::vector<RBX::Network::IdSerializer::WaitItem>;
template class std::map<RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem> >;
template class std::map<std::string, unsigned char>;
// std::map derives from std::_Tree (VS2008 <xtree>); an explicit instantiation of the map does not instantiate the
// members of its base, so the trees are instantiated as well.
template class std::_Tree<std::_Tmap_traits<RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem>,
	std::less<RBX::Guid::Data>, std::allocator<std::pair<const RBX::Guid::Data, std::vector<RBX::Network::IdSerializer::WaitItem> > >, false> >;
template class std::_Tree<std::_Tmap_traits<std::string, unsigned char, std::less<std::string>,
	std::allocator<std::pair<const std::string, unsigned char> >, false> >;
