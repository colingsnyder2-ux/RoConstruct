// boost::detail::shared_count::shared_count<T*, RBX::Creatable<RBX::Instance>::Deleter>(T*, Deleter) instances (2008-06,
// inactive). Each original is a 131-byte COMDAT (pinned extent: ret 8 at +0x6b, then the catch(...) funclet that
// calls the deleter and rethrows) storing the sp_counted_impl_pd<T*, Deleter> vtable named by its RTTI; the
// expected address and T of every instance are listed in tests/record_native_creatable_shared_count.py.
// Every T is the complete class of a committed native header (included read-only); nothing is declared here.
// Separate unit: util/NativeContentProvider.h fails after the main unit's headers (C2011 'RBX::ContentProvider' :
// 'class' type redefinition against the donor util/ContentProvider.h that DHTMLWindowService2008.h reaches).
// >>> native-status (generated) -- do not edit >>>
// CreatableSharedCount2008Content | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 2ad1ee69 | roc native-status --write
#include "util/NativeContentProvider.h"

typedef RBX::Creatable<RBX::Instance>::Deleter CreatableInstanceDeleter;

template boost::detail::shared_count::shared_count(RBX::ContentProvider*, CreatableInstanceDeleter); // 0041e230
