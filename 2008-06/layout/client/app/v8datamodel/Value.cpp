// =============================================================================
// Value.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/Value.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/Value.h"
#include "util/Object.h"

namespace RBX
{
	char sIntValue[] = "IntValue";
	char sBoolValue[] = "BoolValue";
	char sStringValue[] = "StringValue";
	char sVector3Value[] = "Vector3Value";
	char sCFrameValue[] = "CFrameValue";
	char sColor3Value[] = "Color3Value";
	char sBrickColorValue[] = "BrickColorValue";
	char sObjectValue[] = "ObjectValue";

	// Template members the shared headers only declare (same definitions as ValueDouble2008.cpp / ClickDetector.cpp).
	template<class C, class D, const char* N>
	FactoryProduct<C, D, N>::FactoryProduct() : D() {}

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::className() { return Name::declare<N>(); }

	template<class C, class D, const char* N>
	const Name& FactoryProduct<C, D, N>::getClassName() const { return className(); }

	template<class C, class D, const char* N>
	DescribedCreatable<C, D, N>::DescribedCreatable()
		: Reflection::Described<C, N, FactoryProduct<C, D, N> >() {}

	namespace Reflection
	{
		// SignalDescImpl<1, S> members reflection/signal.h only declares (as in ValueDouble2008.cpp).
		template<typename S>
		SignalDescImpl<1, S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
			: wrapper(wrapper)
		{
		}

		template<typename S>
		boost::signals::connection SignalDescImpl<1, S>::connectGeneric(SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
		{
			return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper), pos);
		}
	}

	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

	template<typename ValueType, const char* ClassName>
	Value<ValueType, ClassName>::Value()
		: value(defaultValue)
	{
		setName("Value");
	}

	template<typename ValueType, const char* ClassName>
	bool Value<ValueType, ClassName>::askSetParent(const Instance*) const
	{
		return true;
	}

	template<typename ValueType, const char* ClassName>
	void Value<ValueType, ClassName>::onValueChanged(const Reflection::PropertyDescriptor&)
	{
		desc_ValueChanged.fire(this, value);
	}

#define NATIVE_APPUNIT634_VALUE(T, N, D) \
	template<> \
	const T Value<T, N>::defaultValue = D; \
	template<> \
	Reflection::BoundProp<T, 1> Value<T, N>::desc_Value("Value", "Data", &Value<T, N>::value, &Value<T, N>::onValueChanged, Reflection::PropertyDescriptor::STANDARD); \
	template<> \
	Reflection::SignalDesc<Value<T, N>, void(T)> Value<T, N>::desc_ValueChanged("Changed", "value"); \
	template class Value<T, N>; \
	template boost::shared_ptr<Value<T, N> > Creatable<Instance>::create<Value<T, N> >();

	NATIVE_APPUNIT634_VALUE(int, sIntValue, 0)
	NATIVE_APPUNIT634_VALUE(bool, sBoolValue, false)
	NATIVE_APPUNIT634_VALUE(std::string, sStringValue, std::string())
	NATIVE_APPUNIT634_VALUE(G3D::Vector3, sVector3Value, G3D::Vector3())
	NATIVE_APPUNIT634_VALUE(G3D::CoordinateFrame, sCFrameValue, G3D::CoordinateFrame())
	NATIVE_APPUNIT634_VALUE(G3D::Color3, sColor3Value, G3D::Color3())
	NATIVE_APPUNIT634_VALUE(BrickColor, sBrickColorValue, BrickColor::random())
#undef NATIVE_APPUNIT634_VALUE

	template boost::shared_ptr<Object> FactoryProduct<IntValue, Instance, sIntValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<BoolValue, Instance, sBoolValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<DoubleValue, Instance, sDoubleValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<StringValue, Instance, sStringValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<Vector3Value, Instance, sVector3Value>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<CFrameValue, Instance, sCFrameValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<Color3Value, Instance, sColor3Value>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<BrickColorValue, Instance, sBrickColorValue>::Creator::create() const;

	Reflection::RefPropDescriptor<ObjectValue, Instance> ObjectValue::desc_Value(
		"Value",
		"Data",
		&ObjectValue::getValue,
		&ObjectValue::setValue,
		Reflection::PropertyDescriptor::STANDARD);
	Reflection::SignalDesc<ObjectValue, void(boost::shared_ptr<Instance>)> ObjectValue::desc_ValueChanged("Changed", "value");

	Instance* ObjectValue::getValue() const
	{
		return value.get();
	}

	void ObjectValue::setValue(Instance* newValue)
	{
		if (value.get() != newValue)
		{
			value = shared_from(newValue);
			raisePropertyChanged(desc_Value);
			desc_ValueChanged.fire(this, value);
		}
	}

	void registerValueClasses()
	{
		IntValue::classDescriptor();
		DoubleValue::classDescriptor();
		BoolValue::classDescriptor();
		StringValue::classDescriptor();
		Vector3Value::classDescriptor();
		CFrameValue::classDescriptor();
		Color3Value::classDescriptor();
		BrickColorValue::classDescriptor();
		ObjectValue::classDescriptor();
	}
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class RBX::Reflection::TSignalDesc<void __cdecl(G3D::Color3)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(G3D::CoordinateFrame)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(G3D::Vector3)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(RBX::BrickColor)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(bool)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(int)>;
template class RBX::Reflection::TSignalDesc<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >)>;
template class RBX::Reflection::TypedPropertyDescriptor<RBX::Instance *>;
template class boost::function1<void,G3D::Color3,std::allocator<void> >;
template class boost::function1<void,G3D::CoordinateFrame,std::allocator<void> >;
template class boost::function1<void,G3D::Vector3,std::allocator<void> >;
template class boost::function1<void,RBX::BrickColor,std::allocator<void> >;
template class boost::function1<void,bool,std::allocator<void> >;
template class boost::function1<void,double,std::allocator<void> >;
template class boost::function1<void,int,std::allocator<void> >;
template class boost::function1<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,std::allocator<void> >;
template class boost::function<void __cdecl(G3D::Color3),std::allocator<void> >;
template class boost::function<void __cdecl(G3D::CoordinateFrame),std::allocator<void> >;
template class boost::function<void __cdecl(G3D::Vector3),std::allocator<void> >;
template class boost::function<void __cdecl(RBX::BrickColor),std::allocator<void> >;
template class boost::function<void __cdecl(bool),std::allocator<void> >;
template class boost::function<void __cdecl(boost::shared_ptr<RBX::Instance>),std::allocator<void> >;
template class boost::function<void __cdecl(int),std::allocator<void> >;
template class boost::function<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),std::allocator<void> >;
template class boost::mpl::integral_c<unsigned int,4>;
template class boost::signal1<void,G3D::Color3,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(G3D::Color3),std::allocator<void> > >;
template class boost::signal1<void,G3D::CoordinateFrame,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(G3D::CoordinateFrame),std::allocator<void> > >;
template class boost::signal1<void,G3D::Vector3,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(G3D::Vector3),std::allocator<void> > >;
template class boost::signal1<void,RBX::BrickColor,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(RBX::BrickColor),std::allocator<void> > >;
template class boost::signal1<void,bool,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(bool),std::allocator<void> > >;
template class boost::signal1<void,int,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(int),std::allocator<void> > >;
template class boost::signal1<void,std::basic_string<char,std::char_traits<char>,std::allocator<char> >,boost::last_value<void>,int,std::less<int>,boost::function<void __cdecl(std::basic_string<char,std::char_traits<char>,std::allocator<char> >),std::allocator<void> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::any> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::signals::connection> >;
template class std::_Container_base_aux_alloc_real<std::allocator<boost::signals::trackable const *> >;
template class std::allocator<RBX::Reflection::SignatureDescriptor::Item>;
template class std::allocator<boost::signals::connection>;
template class std::allocator<std::_List_nod<boost::signals::connection,std::allocator<boost::signals::connection> >::_Node *>;
template class std::vector<boost::any,std::allocator<boost::any> >;
template class std::vector<boost::signals::trackable const *,std::allocator<boost::signals::trackable const *> >;

template void RBX::Name::callDoDeclare<RBX::sIntValue>();
template void RBX::Name::callDoDeclare<RBX::sBoolValue>();
template void RBX::Name::callDoDeclare<RBX::sStringValue>();
template void RBX::Name::callDoDeclare<RBX::sCFrameValue>();
template void RBX::Name::callDoDeclare<RBX::sBrickColorValue>();

namespace RBX
{
ObjectValue::ObjectValue()
{
	std::string name("Value");
	Instance::setName(name);
}
}

#include "reflection/type.h"
#include "util/Utilities.h"
#include "G3D/format.h"
#include "G3D/Vector3.h"
#include "G3D/Color3.h"
#include "G3D/CoordinateFrame.h"
#include "v8datamodel/BrickColor.h"
#include <stdexcept>

namespace RBX { namespace Reflection {
template<class T> T& Value::genericConvert() {
	T* id = boost::any_cast<T>(&value);
	if (id) return *id;
	if (isType<std::string>()) {
		T v;
		if (StringConverter<T>::convertToValue(*boost::any_cast<std::string>(&value),v)) {
			value = v;
			_type = &Type::singleton<T>();
			return *boost::any_cast<T>(&value);
		}
	}
	throw std::runtime_error(G3D::format("Unable to cast %s to %s", _type->tag.c_str(), Type::singleton<T>().tag.c_str()));
}
template float& Value::genericConvert<float>();
}}

#include "util/Sound.h"

namespace RBX { namespace Reflection {
template<class T> T Value::get() const {
	if (isType<T>()) return boost::any_cast<const T&>(value);
	Value copy(*this);
	return copy.convert<T>();
}
template bool Value::get<bool>() const;
template float Value::get<float>() const;
template int Value::get<int>() const;
template Soundscape::SoundId Value::get<Soundscape::SoundId>() const;
}}
