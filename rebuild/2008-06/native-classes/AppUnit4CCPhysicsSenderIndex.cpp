// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native rows of the physics-replication sender unit inside 004cc000..004d0000 (inactive): boost 1.34.1
// multi_index_container members of RBX::Network::PhysicsSender::PartItems that the sender's step / sendPackets reach
// and that the container instantiation in NetworkPhysicsSenders2008.cpp does not emit. Explicit member
// instantiations only, against the read-only native-headers/Network/PhysicsSenders2008.h (layout and index evidence
// there). Verified by tests/record_native_app_unit4cc.py (unit map of the range in app-unit4cc-working.json).
//
//   004cc960 (+ catch funclet 004cc9f4)  multi_index_container::insert_(const PartItem&): new(0x78) node, the index-0
//            hashed insert_(value, node) 004cc4e0, ++node_count (+0x30) on success, else delete; the funclet deletes the
//            node and rethrows. Ends `ret 8` (hidden pair<node*, bool> return + value).
//   004cca10 (+ catch funclet 004cca8a)  multi_index_container::modify_<Modifier>(Modifier, node*): `call [ebp+8]` on
//            &node->value() (cdecl, add esp 4), then the hashed modify_(node) 004cc7e0; on failure delete the node and
//            --node_count. `ret 0xc`: an 8-byte Modifier plus the node. The only caller, sendPackets 004cce00 (at
//            004cd02d), pushes the node, a second (unused) dword and the function 004c9cf0 (cdecl, one PartItem&:
//            refreshes lastFrame +0x10 from part->getCoordinateFrame 00598cb0, accumulated +0x40 = the float
//            0093cc40, lastSendStep +0x44 = 0): boost::bind(f, _1) over a free function pointer is the 8-byte
//            functor this body calls through its first dword (codegen analog; the function's own name is unknown).
//   004cc210  ordered_index<priority, greater<double> >::modify_(node*) (index 1, ordered impl at node +0x60), reached
//             from the hashed modify_ 004cc7e0; it calls the index-2 modify_ 004cbc10.
//   004ccc30  ordered_index<priority, greater<double> >::erase(iterator) (increment 004c66c0, the hashed erase_
//             004cc580, delete, --node_count); called from sendPackets 004cce00.
//
// The hashed insert_ 004cc4e0, replace_ 004cc5e0 (+ 004cc6e5) and modify_ 004cc7e0 inline RBX::hash_value
// (004ca5b0), whose definition is in NetworkPhysicsSenders2008.cpp: they are exact only in a build of that unit (the
// recorder's sender-unit evidence build) and are proposed to its owner, not counted here.
#include "Network/PhysicsSenders2008.h"
#include <boost/bind.hpp>

namespace
{
	typedef RBX::Network::PhysicsSender::PartItem SenderItem;
	typedef RBX::Network::PhysicsSender::PartItems SenderItems;
	typedef SenderItems::nth_index<1>::type SenderPriorityIndex;
	typedef boost::_bi::bind_t<void, void (*)(SenderItem&), boost::_bi::list1<boost::arg<1> > > SenderItemModifier;
}

// 004cc960 / 004cc9f4
template std::pair<SenderItems::final_node_type*, bool> SenderItems::insert_(const SenderItem& v);
// 004cca10 / 004cca8a (and, through it, the index-1 modify_ 004cc210)
template bool SenderItems::modify_<SenderItemModifier>(SenderItemModifier mod, SenderItems::final_node_type* x);
// 004ccc30
template SenderPriorityIndex::iterator SenderPriorityIndex::erase(SenderPriorityIndex::iterator position);
