// 2008-06 native rows of the clothing adjustor-thunk runs inside the application range 0048c000..00498000 (Network/
// Player.cpp unit, inactive). Verified by tests/record_native_app_unit48c_2008.py. All headers are read-only here.
//
// The unit emits the Clothing / Pants / Shirt vtables (it creates those classes), and with them the vector deleting
// destructor thunks of their non-primary bases (`sub ecx, N; jmp ??_G`):
//   * FactoryProduct<Clothing, CharacterAppearance, sClothing>: 0048f890 (-0x10), 0048f8a0 (-0x130), 0048f8b0 (-0x64),
//     0048f8c0 (-0x84), 0048f8d0 (-0xa4), each jumping to its ??_G 0048f8e0 (counted by clothing-working.json);
//   * Pants: 0048fb30 (-0x44), 0048fb40 (-0xa4), 0048fb50 (-0xc4), 00493360 (-0x64), 00493370 (-0x84), 00493380 (-0x10),
//     00493390 (-0x14), 00493990 (-0x24), 004939a0 (-0x130) -> ??_GPants 004933a0 (clothing-working.json);
//   * Shirt: 00493460 (-0x130), 00493470 (-0x24), 00493480 (-0x44), 00493490 (-0xa4), 00493a20 (-0x64), 00493a30
//     (-0x84), 00493a40 (-0xc4), 00493a50 (-0x10), 00493a60 (-0x14) -> ??_GShirt 00493a70 (clothing-working.json;
//     evidence names ??_EShirt@RBX@@W...). The Pants / Shirt thunks need the inline constructors (pending build only).
// The adjustments are the base offsets of the native Clothing.h hierarchy (RTTI of the FactoryProduct<Clothing>
// vtables 008218c8..00821850 at +0x10/+0x64/+0x84/+0xa4/+0x130).
#include "v8datamodel/Clothing.h"

namespace RBX
{
	// The FactoryProduct constructor util/Object.h only declares (the same definition AppUnit480_2008Player.cpp uses).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}
}

// FactoryProduct<Clothing, CharacterAppearance, sClothing>: its vtables and their thunks.
template class RBX::FactoryProduct<RBX::Clothing, RBX::CharacterAppearance, RBX::sClothing>;

#ifdef NATIVE_APPUNIT48C_PENDING
// Pending build only (generated v8datamodel/Clothing.h copy with the inline constructors `Pants() {}` / `Shirt() {}`;
// proposal for the Clothing.h owner). The original emitted Pants() 00493920 / Shirt() 004939b0 as COMDATs in this
// unit (create<Pants> 004941d0 / create<Shirt> 00494250 call them out of line), and with them the Pants / Shirt
// vtables and the thunks above. The current header declares the constructors out of line (native-classes/Clothing.cpp
// defines them), so the current-header build emits no Pants / Shirt vtable.
namespace RBX
{
	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}
}

template boost::shared_ptr<RBX::Pants> RBX::Creatable<RBX::Instance>::create<RBX::Pants>();
template boost::shared_ptr<RBX::Shirt> RBX::Creatable<RBX::Instance>::create<RBX::Shirt>();
#endif
