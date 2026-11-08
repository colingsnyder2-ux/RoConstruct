// 2008-06 native RBX::Value<double, sDoubleValue> (DoubleValue; class name "NumberValue"), inactive.
// Evidence (verified by tests/record_native_value_double2008.py):
//   * RTTI .?AV?$Value@N$1?sDoubleValue@RBX@@3PADA@RBX@@ (vtable 0084948c, 21 bases, Instance at 0): the template
//     argument is a non-const char array; it is the only Value<double> and no Value<float> RTTI exists in 2008.
//   * create 00639800 allocates 0x138 = Instance 0x130 + the double value at +0x130 (constructor 00638380 stores
//     fldz there, then setName("Value") 0055af90).
//   * main vtable slot 3 (askSetParent) is 00565ff0 (`mov al, 1; ret 4`, ICF-shared), the other slots are Instance's.
//   * desc_Value 0097d3f0: BoundProp<double, 1>("Value", "Data", +0x130, onValueChanged 0063ab70, STANDARD 5),
//     initializer 007f8650 / atexit 00800ae0; desc_ValueChanged 0097d490: SignalDesc<Value, void(double)>("Changed",
//     "value"), initializer 007f8680 / atexit 00800e60. onValueChanged fires desc_ValueChanged with the value.
#include "v8datamodel/Value.h"

namespace RBX
{
	char sDoubleValue[] = "NumberValue"; // 0095d9f0 (doDeclare 006331f0, classDescriptor 00636b50)

	// Template members the shared headers only declare (same definitions as ClickDetector.cpp / Tool.cpp).
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
		// SignalDescImpl<1, S> members reflection/signal.h only declares (same shape as the two-argument ones in
		// ChangeHistoryStart.cpp); connectGeneric is slot 1 of the desc_ValueChanged vtable 00848b54 (0063abc0).
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

	template<typename ValueType, const char* ClassName>
	Value<ValueType, ClassName>::Value()
		: value()
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

	// Dynamic initializers 007f8650, 007f8680 (in this order).
	template<>
	Reflection::BoundProp<double, 1> DoubleValue::desc_Value("Value", "Data", &DoubleValue::value, &DoubleValue::onValueChanged, Reflection::PropertyDescriptor::STANDARD);
	template<>
	Reflection::SignalDesc<DoubleValue, void(double)> DoubleValue::desc_ValueChanged("Changed", "value");

	template class Value<double, sDoubleValue>;

	// create<DoubleValue> 00639800 (FactoryProduct<DoubleValue>::Creator::create 0063a080 calls it).
	template boost::shared_ptr<DoubleValue> Creatable<Instance>::create<DoubleValue>();
}
