// 2008-06 native RBX::Backpack (inactive): the Backpack part of the original Hopper unit (005d16d0..005d1b70).
// Evidence in native-headers/v8datamodel/Backpack.h. Backpack.h needs a native script/Script.h (IScriptOwner), which
// does not exist yet: the unit is compiled only with NATIVE_BACKPACK_PENDING against a generated copy of the donor
// Script.h with the 2008 const-char-array class names (tests/record_native_hopper.py), so every row is recorded
// exact=false (pending-build-only).
// >>> native-status (generated) -- do not edit >>>
// Backpack | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6e5e7f84 | roc native-status --write
#ifdef NATIVE_BACKPACK_PENDING
#include "v8datamodel/Backpack.h"

namespace RBX
{
	const char sBackpack[] = "Backpack"; // 0083b738 (doDeclare 00489e1b, classDescriptor 005c0189)

	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	Backpack::Backpack()
	{
		setName("Backpack");
	}
}
#endif
