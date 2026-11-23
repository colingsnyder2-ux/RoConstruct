// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native (inactive): DescribedCreatable<C, Instance, sC>::DescribedCreatable() and FactoryProduct ctor instances the
// donor-free boot reaches first (Camera, RunService, FlagStandService constructors). Same bodies as SelectionBase.cpp.
#include "v8datamodel/Camera.h"
#include "util/RunStateOwner.h"
#include "v8datamodel/FlagStandService.h"

namespace RBX {
template<class C, class D, const char* N>
FactoryProduct<C,D,N>::FactoryProduct() : D() {}
template<class C, class D, const char* N>
DescribedCreatable<C,D,N>::DescribedCreatable() : Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}

template FactoryProduct<Camera,Instance,sCamera>::FactoryProduct();
template DescribedCreatable<Camera,Instance,sCamera>::DescribedCreatable();
template FactoryProduct<RunService,Instance,sRunService>::FactoryProduct();
template DescribedCreatable<RunService,Instance,sRunService>::DescribedCreatable();
template FactoryProduct<FlagStandService,Instance,sFlagStandService>::FactoryProduct();
template DescribedCreatable<FlagStandService,Instance,sFlagStandService>::DescribedCreatable();
}
