// 2008-06 native RBX::Value<T, sXValue> instances other than Value<double> (application range 00634000..00640000),
// inactive. The class template, its descriptor statics and the class-name arrays are declared by the committed
// read-only native v8datamodel/Value.h; ValueDouble2008.cpp (value-double2008-working.json) owns T = double.
// Evidence (verified by tests/record_native_app_unit634_2008.py):
//   * RTTI .?AV?$Value@H$1?sIntValue@RBX@@3PADA@RBX@@, _N sBoolValue, basic_string sStringValue, Vector3 sVector3Value,
//     CoordinateFrame sCFrameValue, Color3 sColor3Value, BrickColor sBrickColorValue (non-const char arrays, 3PADA);
//     the 2008 binary has no Value<float>.
//   * The shared_count<Value<T>*, Deleter> instances 00635150..00636210 (creatable-shared-count) give the per-T order
//     int, bool, double, string, Vector3, CFrame, Color3, BrickColor; the instances below follow it.
//   * Each Value<T> body (constructor, desc_Value BoundProp<T, 1>("Value", "Data", +0x130, onValueChanged, STANDARD),
//     desc_ValueChanged SignalDesc<Value, void(T)>("Changed", "value")) has the DoubleValue shape; the allocation
//     sizes are read from the create<T> bodies by the recorder.
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
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

	// util/Object.h declares Creator::create() only (same definition as AppUnit48C_2008Creators.cpp): slot 0 of
	// each Value Creator vtable, 00639f20..0063a3f0 (175 B each).
	template<typename Class, typename DerivedClass, const char* ClassName>
	boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
	{
		return Creatable<Instance>::create<Class>();
	}

	// The constructors copy the class's defaultValue: a load of the constant for int / bool, a copy from the
	// statics std::string 0097d280 (initializer 007f86a0), Vector3 009611c0 (static zero data), CoordinateFrame
	// 0097d3a0 (initializer 007f8760), Color3 0097d320 (zero-filled, no initializer: empty Color3()) and BrickColor
	// 0097d3ec (initializer 007f8820 calls BrickColor::random 005b5ee0).
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

	// Dynamic initializers in this order: 007f85b0..007f8630 (int, bool), [007f8650 / 007f8680 DoubleValue,
	// ValueDouble2008.cpp], 007f86a0..007f8860 (string, Vector3, CFrame, Color3, BrickColor).
	NATIVE_APPUNIT634_VALUE(int, sIntValue, 0)
	NATIVE_APPUNIT634_VALUE(bool, sBoolValue, false)
	NATIVE_APPUNIT634_VALUE(std::string, sStringValue, std::string())
	NATIVE_APPUNIT634_VALUE(G3D::Vector3, sVector3Value, G3D::Vector3())
	NATIVE_APPUNIT634_VALUE(G3D::CoordinateFrame, sCFrameValue, G3D::CoordinateFrame())
	NATIVE_APPUNIT634_VALUE(G3D::Color3, sColor3Value, G3D::Color3())
	NATIVE_APPUNIT634_VALUE(BrickColor, sBrickColorValue, BrickColor::random())
#undef NATIVE_APPUNIT634_VALUE

	// Creator::create for every Value class (DoubleValue's 0063a080 too; create<DoubleValue> 00639800 is counted by
	// value-double2008-working.json).
	template boost::shared_ptr<Object> FactoryProduct<IntValue, Instance, sIntValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<BoolValue, Instance, sBoolValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<DoubleValue, Instance, sDoubleValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<StringValue, Instance, sStringValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<Vector3Value, Instance, sVector3Value>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<CFrameValue, Instance, sCFrameValue>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<Color3Value, Instance, sColor3Value>::Creator::create() const;
	template boost::shared_ptr<Object> FactoryProduct<BrickColorValue, Instance, sBrickColorValue>::Creator::create() const;

	// ObjectValue (Value.h): desc_Value RefPropDescriptor<ObjectValue, Instance> 0097d364 (initializer 007f8880:
	// getValue 00565e30, setValue 0063a920, STANDARD), desc_ValueChanged 0097d330 (initializer 007f88c0).
	Reflection::RefPropDescriptor<ObjectValue, Instance> ObjectValue::desc_Value("Value", "Data", &ObjectValue::getValue, &ObjectValue::setValue, Reflection::PropertyDescriptor::STANDARD);
	Reflection::SignalDesc<ObjectValue, void(boost::shared_ptr<Instance>)> ObjectValue::desc_ValueChanged("Changed", "value");

	Instance* ObjectValue::getValue() const
	{
		return value.get();
	}

	// 0063a920: compare, assign shared_from(newValue), raisePropertyChanged(desc_Value), fire desc_ValueChanged.
	void ObjectValue::setValue(Instance* newValue)
	{
		if (value.get() != newValue)
		{
			value = shared_from(newValue);
			raisePropertyChanged(desc_Value);
			desc_ValueChanged.fire(this, value);
		}
	}

	// 00637ae0: the classDescriptor calls in the order the original makes them (the DoubleValue one is 00636b50).
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
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

// Name registrations emitted by this unit (bytes and sX relocation identity proven against the 2008-06 client).
template void RBX::Name::callDoDeclare<RBX::sIntValue>();
template void RBX::Name::callDoDeclare<RBX::sBoolValue>();
template void RBX::Name::callDoDeclare<RBX::sStringValue>();
template void RBX::Name::callDoDeclare<RBX::sCFrameValue>();
template void RBX::Name::callDoDeclare<RBX::sBrickColorValue>();
