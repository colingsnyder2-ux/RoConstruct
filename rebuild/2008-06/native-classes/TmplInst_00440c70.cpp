// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 00440c70 ?create@Creator@?$FactoryProduct@VSoundChannel@Soundscape@RBX@@VInstance@3@$1?sSoundChannel@23@3PADA@RBX@@UBE?AV?$shared: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "SoundChannel/SoundChannel.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only (definition as in AppUnit400_2008Creators.cpp).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Soundscape::SoundChannel, RBX::Instance, RBX::Soundscape::sSoundChannel>::Creator::create() const;
