// 2008-06 native boost / STL instances on RBX::Network::Marker of the Network/Replicator.cpp unit inside the
// application range 004ac000..004b0000 (inactive), against the read-only native-headers/Network/ReplicatorMarker.h.
// Verified by tests/record_native_app_unit4ac.py.
//   * boost::detail::shared_count::shared_count<Marker>(Marker*) 004ac040 (called by Marker::newMarker 004b9190; the
//     catch(...) funclet `boost::checked_delete(p); throw;` is the separate row 004ac0ae);
//   * sp_counted_impl_p<Marker> (vtable 008246f4): dispose 004ac390 (ICF-shared `delete px_` body);
//   * std::deque<boost::shared_ptr<Marker> > (Replicator +0x2cdc): pop_front 004ae2f0 (caller 004b8490) and
//     _Tidy 004af1b0 (callers ~deque 004b0f20 and ~Replicator 004b96b0).
#include "Network/ReplicatorMarker.h"
#include <deque>

template boost::detail::shared_count::shared_count(RBX::Network::Marker*);
template class boost::detail::sp_counted_impl_p<RBX::Network::Marker>;
template class std::deque<boost::shared_ptr<RBX::Network::Marker> >;
