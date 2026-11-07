// >>> native-status (generated) -- do not edit >>>
// FlagStandService | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 47af4ac9 | roc native-status --write
#include "v8datamodel/FlagStandService.h"
#include "reflection/property.h"
namespace RBX {
const char sFlagStandService[] = "FlagStandService";
// Stand-in until a native FlagStand.h exists (donor header does not compile natively): declares only the
// donor's non-virtual `Flag* FlagStand::GetFlag()` (tools/rbxgs/Client/App/include/v8datamodel/FlagStand.h); no fields.
class FlagStand { public: Flag* GetFlag(); };
template<> Reflection::ClassDescriptor& Reflection::Described<FlagStandService,sFlagStandService,FactoryProduct<FlagStandService,Instance,sFlagStandService> >::classDescriptor() {
 static Reflection::ClassDescriptor descriptor(Instance::classDescriptor(), "FlagStandService");
 return descriptor;
}
template<class C,class D,const char* N> FactoryProduct<C,D,N>::FactoryProduct():D() {}
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::className() { return Name::declare<N>(); }
template<class C,class D,const char* N> const Name& FactoryProduct<C,D,N>::getClassName() const { return className(); }
template<class C,class D,const char* N> DescribedCreatable<C,D,N>::DescribedCreatable():Reflection::Described<C,N,FactoryProduct<C,D,N> >() {}

// Constructor 0062ccd0 parked: donor body is `setName("FlagStandService"); propArchivable.setValue(this, false);`, but
// native Instance.h lacks Instance::propArchivable and the original TypedPropertyDescriptor<T>::GetSet has 4 virtual
// slots (setValue at +0xc). See work/flagstandservice-20261104/header-proposal.md.
FlagStandService::~FlagStandService() {}
FlagStand* FlagStandService::FindStandWithFlag(Flag* f) {
 if (flagStands.empty()) return NULL;
 for (std::list<FlagStand*>::const_iterator iter=flagStands.begin();iter!=flagStands.end();iter++)
  if ((*iter)->GetFlag()==f) return *iter;
 return NULL;
}
void FlagStandService::RegisterFlagStand(FlagStand* s) { flagStands.push_back(s); }
void FlagStandService::UnregisterFlagStand(FlagStand* s) { flagStands.remove(s); }
}
