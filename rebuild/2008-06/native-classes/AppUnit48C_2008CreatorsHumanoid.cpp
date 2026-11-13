// 2008-06 native rows of the Humanoid Creatable instances inside the application range 0048c000..00498000 (inactive).
// Verified by tests/record_native_app_unit48c_2008.py. Built against the native 2008 humanoid/Humanoid2008.h (sizeof
// 0x22c, extern char sHumanoid[]: RTTI 3PADA), which cannot share a unit with humanoid/Humanoid.h; headers read-only.
//   * FactoryProduct<Humanoid, Instance, sHumanoid>::Creator::create() const 004907f0 (Creator vtable 00821b30 slot 0);
//   * Creatable<Instance>::create<Humanoid>() 00490770 (malloc 0x22c, Humanoid() 005db280);
//   * boost::shared_ptr<Humanoid>(Humanoid*, Creatable<Instance>::Deleter) 004906c0 (shared_count 00490630, counted
//     by creatable-shared-count).
// >>> native-status (generated) -- do not edit >>>
// AppUnit48C_2008CreatorsHumanoid | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 254eb711 | roc native-status --write
#include "humanoid/Humanoid2008.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only; the same definition as AppUnit48C_2008Creators.cpp.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

template boost::shared_ptr<RBX::Humanoid> RBX::Creatable<RBX::Instance>::create<RBX::Humanoid>();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::Humanoid, RBX::Instance, RBX::sHumanoid>::Creator::create() const;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::Humanoid>;
