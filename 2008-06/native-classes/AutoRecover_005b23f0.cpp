// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
#include "v8datamodel/Accoutrement.h"

namespace RBX
{
	const char sHat[] = "Hat";

	// INFERRED: same local template member definitions as native-classes/Accoutrement.cpp (generic ones are not in shared headers).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	template<> Reflection::ClassDescriptor& Reflection::Described<Hat, sHat,
		FactoryProduct<Hat, Accoutrement, sHat> >::classDescriptor() {
		static Reflection::ClassDescriptor descriptor(Accoutrement::classDescriptor(), sHat);
		return descriptor;
	}

	template class FactoryProduct<Hat, Accoutrement, sHat>;
	template DescribedCreatable<Hat, Accoutrement, sHat>::DescribedCreatable();
}
