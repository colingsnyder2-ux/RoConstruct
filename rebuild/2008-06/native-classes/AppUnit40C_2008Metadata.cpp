// 2008-06 native rows of the reflection-metadata template block 0040c000..0040df5f inside the application range
// 0040c000..00418000 (inactive). Verified by tests/record_native_app_unit40c_2008.py. All headers are read-only here:
// reflection/Metadata.h (Item 0x150, Class 0x158, Member 0x150, Classes / Properties / Functions / Events 0x130) and
// AuthoringSettings.h (0x134).
//
// The block is the run of compiler-emitted template instances of the unit that holds the AuthoringSettings item
// (constructor 0040d140, destructor 0040a990). The class bodies themselves (Item(), Class(), Members(), the container
// destructors, AuthoringSettings, GlobalSettingsItem<AuthoringSettings>) come from the committed native-classes
// Metadata*Lifetime.cpp / MetadataClassesRegister.cpp / AuthoringSettings.cpp, which the recorder compiles unchanged.
// This file adds the template members the shared headers only declare, and instantiates them for the metadata classes:
//   * FactoryProduct<C, D, N>::FactoryProduct()            (Events 0040c200, Class 0040d1b0, Member 0040d490);
//   * DescribedCreatable<C, D, N>::DescribedCreatable()    (Classes 0040c8f0, Properties 0040c990, Functions 0040ca70,
//                                                           Events 0040cb60, Class 0040d950, Member 0040da00);
//   * FactoryProduct<C, D, N>::getClassName() const        (Functions 0040c0b0, Events 0040c3a0, Member 0040c600);
//   * Creatable<Instance>::create<C>()                     (Classes 0040d210, Properties 0040d290, Functions 0040d310,
//                                                           Events 0040d390, Member 0040de10; malloc(sizeof(C)));
//   * FactoryProduct<C, D, N>::Creator::create() const     (slot 0 of the Creator vtables 0080bc68 Classes,
//     0080bee8 Properties, 0080c088 Functions, 0080c168 Events, 0080c328 AuthoringSettings, 0080bd44 Class,
//     0080c248 Member): calls create<C>() and returns it as shared_ptr<Object>.
// shared_ptr<C>(C*, Creatable<Instance>::Deleter) (Functions 0040c000, Events 0040c2f0, Member 0040c550) and
// Described<C>::classDescriptor() (Functions 0040c0d0, Events 0040c3c0, Member 0040c760) are implicit instances.
// >>> native-status (generated) -- do not edit >>>
// AppUnit40C_2008Metadata | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src f38c891b | roc native-status --write
#include "reflection/Metadata.h"
#include "AuthoringSettings.h"
#include "util/Object.h"

namespace RBX
{
	template<typename Class, typename DerivedClass, const char* ClassName>
	FactoryProduct<Class, DerivedClass, ClassName>::FactoryProduct() {}

	template<typename Class, typename DerivedClass, const char* ClassName>
	DescribedCreatable<Class, DerivedClass, ClassName>::DescribedCreatable() {}

	template<typename Class, typename DerivedClass, const char* ClassName>
	const Name& FactoryProduct<Class, DerivedClass, ClassName>::getClassName() const
	{
		return Name::declare<ClassName>();
	}

	// util/Object.h declares Creator::create() only; this is the definition every Creator vtable slot 0 reaches.
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}
}

namespace M = RBX::Reflection::Metadata;

template RBX::FactoryProduct<M::Events, M::Members, M::sEvents>::FactoryProduct();
template RBX::FactoryProduct<M::Class, M::Item, M::sClass>::FactoryProduct();
template RBX::FactoryProduct<M::Member, M::Item, M::sMember>::FactoryProduct();

template RBX::DescribedCreatable<M::Classes, RBX::Instance, M::sClasses>::DescribedCreatable();
template RBX::DescribedCreatable<M::Properties, M::Members, M::sProperties>::DescribedCreatable();
template RBX::DescribedCreatable<M::Functions, M::Members, M::sFunctions>::DescribedCreatable();
template RBX::DescribedCreatable<M::Events, M::Members, M::sEvents>::DescribedCreatable();
template RBX::DescribedCreatable<M::Class, M::Item, M::sClass>::DescribedCreatable();
template RBX::DescribedCreatable<M::Member, M::Item, M::sMember>::DescribedCreatable();

template const RBX::Name& RBX::FactoryProduct<M::Functions, M::Members, M::sFunctions>::getClassName() const;
template const RBX::Name& RBX::FactoryProduct<M::Events, M::Members, M::sEvents>::getClassName() const;
template const RBX::Name& RBX::FactoryProduct<M::Member, M::Item, M::sMember>::getClassName() const;

template boost::shared_ptr<M::Classes> RBX::Creatable<RBX::Instance>::create<M::Classes>();
template boost::shared_ptr<M::Properties> RBX::Creatable<RBX::Instance>::create<M::Properties>();
template boost::shared_ptr<M::Functions> RBX::Creatable<RBX::Instance>::create<M::Functions>();
template boost::shared_ptr<M::Events> RBX::Creatable<RBX::Instance>::create<M::Events>();
template boost::shared_ptr<M::Member> RBX::Creatable<RBX::Instance>::create<M::Member>();

template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<M::Classes, RBX::Instance, M::sClasses>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<M::Properties, M::Members, M::sProperties>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<M::Functions, M::Members, M::sFunctions>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<M::Events, M::Members, M::sEvents>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<AuthoringSettings, RBX::GlobalSettings::Item, sAuthoringSettings>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<M::Class, M::Item, M::sClass>::Creator::create() const;
template boost::shared_ptr<RBX::Object> RBX::FactoryProduct<M::Member, M::Item, M::sMember>::Creator::create() const;

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<AuthoringSettings>;
template class boost::shared_ptr<RBX::Object>;
template class boost::shared_ptr<RBX::Reflection::Metadata::Class>;
template class boost::shared_ptr<RBX::Reflection::Metadata::Classes>;
template class boost::shared_ptr<RBX::Reflection::Metadata::Events>;
template class boost::shared_ptr<RBX::Reflection::Metadata::Functions>;
template class boost::shared_ptr<RBX::Reflection::Metadata::Member>;
template class boost::shared_ptr<RBX::Reflection::Metadata::Properties>;

// PARKED: RBX::Instance::raisePropertyChanged 0040db00 (?raisePropertyChanged@Instance@RBX@@QAEXABVPropertyDescriptor@
// Reflection@2@@Z, 160 bytes). It is a COMDAT of this metadata unit: the donor v8tree/Instance.h (tools/rbxgs App/include
// v8tree/Instance.h:359) defines it inline. Body (exact in the isolated worker
// rebuild/2008-06/tests/NativeInstancePropertyChangedWorker.cpp / record_native_instance_property_worker.py):
//   PropertyChanged event(Reflection::Property(descriptor, this));
//   Notifier<Instance, PropertyChanged>::raise(event);                         // 0040a530, Event by value
//   if (!event_propertyChanged.empty(this)) event_propertyChanged.fire(this, &descriptor); // 00973f48
//   Instance* p = parent; if (p) p->onChildChanged(this, event);              // +0x104, slot 0x3c
// Blocked by read-only headers: v8tree/Instance.h has no 'static Reflection::SignalDesc<Instance,
// void(const Reflection::PropertyDescriptor*)> event_propertyChanged;' and reflection/property.h /
// v8tree/PropertyChanged.h declare the Property / PropertyChanged copy constructors without the inline bodies the
// by-value raise needs (target: two stores, no call).
// Rejected trial 1: /I{headers}/partchunk-profile (its Instance.h declares event_propertyChanged) - MSVC resolves
// AuthoringSettings.h -> v8datamodel/GlobalSettings.h -> "v8tree/Instance.h" through the includer directory
// (native-headers/), so both Instance.h copies are included: C2011 'RBX::Instance' redefinition.
