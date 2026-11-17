#include "Network/PhysicsSenders2008.h"
#include <boost/bind.hpp>

namespace
{
	typedef RBX::Network::PhysicsSender::PartItem SenderItem;
	typedef RBX::Network::PhysicsSender::PartItems SenderItems;
	typedef SenderItems::nth_index<1>::type SenderPriorityIndex;
	typedef boost::_bi::bind_t<void, void (*)(SenderItem&), boost::_bi::list1<boost::arg<1> > > SenderItemModifier;
}

template std::pair<SenderItems::final_node_type*, bool> SenderItems::insert_(const SenderItem& v);
template bool SenderItems::modify_<SenderItemModifier>(SenderItemModifier mod, SenderItems::final_node_type* x);
template SenderPriorityIndex::iterator SenderPriorityIndex::erase(SenderPriorityIndex::iterator position);
