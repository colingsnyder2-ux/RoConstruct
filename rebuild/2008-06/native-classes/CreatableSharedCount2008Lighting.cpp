// boost::detail::shared_count::shared_count<T*, RBX::Creatable<RBX::Instance>::Deleter>(T*, Deleter) instances (2008-06,
// inactive). Each original is a 131-byte COMDAT (pinned extent: ret 8 at +0x6b, then the catch(...) funclet that
// calls the deleter and rethrows) storing the sp_counted_impl_pd<T*, Deleter> vtable named by its RTTI; the
// expected address and T of every instance are listed in tests/record_native_creatable_shared_count.py.
// Separate unit: T = RBX::Lighting comes from the native v8datamodel/Lighting2008.h (G3D LightingParameters and
// boost date_time), kept apart from the main unit's header set; nothing is declared here.
// >>> native-status (generated) -- do not edit >>>
// CreatableSharedCount2008Lighting | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src f7f17186 | roc native-status --write
#include "v8datamodel/Lighting2008.h"

typedef RBX::Creatable<RBX::Instance>::Deleter CreatableInstanceDeleter;

template boost::detail::shared_count::shared_count(RBX::Lighting*, CreatableInstanceDeleter); // 004ac4c0
