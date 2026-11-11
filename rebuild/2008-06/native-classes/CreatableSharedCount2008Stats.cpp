// boost::detail::shared_count::shared_count<T*, RBX::Creatable<RBX::Instance>::Deleter>(T*, Deleter) instances (2008-06,
// inactive). Each original is a 131-byte COMDAT (pinned extent: ret 8 at +0x6b, then the catch(...) funclet that
// calls the deleter and rethrows) storing the sp_counted_impl_pd<T*, Deleter> vtable named by its RTTI; the
// expected address and T of every instance are listed in tests/record_native_creatable_shared_count.py.
// Every T is the complete class of a committed native header (included read-only); nothing is declared here.
// Separate unit: stats/Stats.h (and stats/WorkspaceStatsItem.h, which includes it) and v8datamodel/Stats.h, which the
// main unit reaches through util/Sound.h, both define RBX::Stats::Item (C2011 in either include order).
// >>> native-status (generated) -- do not edit >>>
// CreatableSharedCount2008Stats | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 11fdb6ae | roc native-status --write
#include "stats/Stats.h"
#include "stats/WorkspaceStatsItem.h"

typedef RBX::Creatable<RBX::Instance>::Deleter CreatableInstanceDeleter;

template boost::detail::shared_count::shared_count(RBX::Stats::StatsService*, CreatableInstanceDeleter); // 00456410
template boost::detail::shared_count::shared_count(RBX::Stats::TypedStatsItem<bool>*, CreatableInstanceDeleter); // 004ac620
template boost::detail::shared_count::shared_count(RBX::WorkspaceStatsItem*, CreatableInstanceDeleter); // 005a0b50
template boost::detail::shared_count::shared_count(RBX::Stats::TypedStatsItem<double>*, CreatableInstanceDeleter); // 005a0be0
template boost::detail::shared_count::shared_count(RBX::Stats::TypedStatsItem<float>*, CreatableInstanceDeleter); // 005a0c70
template boost::detail::shared_count::shared_count(RBX::Stats::TypedStatsItem<unsigned int>*, CreatableInstanceDeleter); // 005b75a0

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::function0<double,std::allocator<boost::function_base> >;
template class boost::function0<float,std::allocator<boost::function_base> >;
