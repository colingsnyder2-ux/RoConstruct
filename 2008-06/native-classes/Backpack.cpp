// 2008-06 native RBX::Backpack (inactive): the Backpack part of the original Hopper unit (005d16d0..005d1b70).
// Evidence in native-headers/v8datamodel/Backpack.h (IScriptOwner from the native script/Script.h).
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::GuiItem>;
