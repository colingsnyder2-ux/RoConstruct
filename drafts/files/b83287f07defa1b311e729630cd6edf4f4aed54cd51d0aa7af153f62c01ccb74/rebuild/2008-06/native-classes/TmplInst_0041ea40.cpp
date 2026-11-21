// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 0041ea40 ?create@Creator@?$FactoryProduct@VPartInstance@RBX@@VPVInstance@2@$1?sPart@2@3PADA@RBX@@UBE?AV?$shared_ptr@VObject@RBX@@: explicit template instantiation (template_instances.py, byte-proved standalone)
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/PVInstance.h"
#include "util/Object.h"

namespace RBX
{
	// util/Object.h declares Creator::create() only (definition as in AppUnit400_2008Creators.cpp).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::className()
	{
		return Name::declare<ClassName>();
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::Creator()
	{
		getCreators()[&className()] = this;
		isConstructed = 666;
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::Creator::~Creator()
	{
		getCreators().erase(&className());
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	const typename FactoryProduct<Class, DerivedClass, ClassName>::Creator FactoryProduct<Class, DerivedClass, ClassName>::creator;
}
template const RBX::ICreator& RBX::FactoryProduct<RBX::PartInstance, RBX::PVInstance, RBX::sPart>::getCreator();
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<RBX::PartInstance, RBX::PVInstance, RBX::sPart>::Creator::create() const;
