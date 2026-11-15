// 2008-06 native ContentProvider template instances of the application range 00418000..00424000 (inactive).
// Verified by tests/record_native_app_unit418_2008.py. All headers are read-only here.
// Separate unit: util/NativeContentProvider.h fails after the main unit's headers (C2011 'RBX::ContentProvider' :
// 'class' type redefinition against the donor util/ContentProvider.h that DHTMLWindowService2008.h reaches), as in
// CreatableSharedCount2008Content.cpp.
//   * boost::shared_ptr<ContentProvider>(ContentProvider*, Creatable<Instance>::Deleter) 0041e420 (171 B);
//   * Creatable<Instance>::create<ContentProvider>() 0041e5d0 (120 B; ServiceProvider::create reaches it, there is no
//     Creator: ContentProvider is DescribedNonCreatable);
//   * Name::doDeclare<sContentProvider>() 0041dfe0 and callDoDeclare 0041e0f0.
#include "util/NativeContentProvider.h"

namespace RBX
{
	template const Name& Name::declare<sContentProvider>();
}

template boost::shared_ptr<RBX::ContentProvider> RBX::Creatable<RBX::Instance>::create<RBX::ContentProvider>();

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::ContentProvider>;
