// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native FactoryProduct<C, D, N>::creator static members: their dynamic initializers (??__E?creator@...)
// and atexit destructors (??__F?creator@...) in 007ee760..007fe8b0 (inactive). The donor 2007 util/Object.h defines
// Creator()/~Creator() and `creator` in the header; the native util/Object.h only declares them, so this unit is
// their definition (the pattern of AppUnit400_2008Creators.cpp for Creator::create()). Creator() ends with
// isConstructed = 666: iOS 2013 Object.h asserts Creator::wasConstructed() (isConstructed == 0x29a) and each 2008
// initializer stores 0x29a to its own instantiation. Byte-proved per class by native_creator_gate.py.
#include <afxwin.h>
#include "AppLeaves2008/DHTMLWindowService2008.h"
#include "v8tree/Instance.h"

namespace RBX
{
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

// One explicit instantiation per class (getCreator() is public; creator is private): it instantiates that class's creator object, initializer and atexit destructor.
template const RBX::ICreator& RBX::FactoryProduct<DHTMLWindowService, RBX::Instance, sDHTMLWindowService>::getCreator();
