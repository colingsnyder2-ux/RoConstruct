// 2008-06 override of Source/App/include/v8datamodel/Value.h: class-name template parameters take the
// char array itself (const char*), as the 2008 binary pushes .data name arrays directly.
#pragma once
#include "v8tree/Instance.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/CoordinateFrame.h>

namespace RBX
{
	extern char sIntValue[];
	extern char sBoolValue[];
	extern char sFloatValue[];
	// 2008-06 binary: RTTI .?AV?$Value@N$1?sDoubleValue@RBX@@3PADA@RBX@@ (vtable 0084948c, class name
	// "NumberValue"); the array is defined by native-classes/ValueDouble2008.cpp and the per-T order is int,
	// bool, double, string, Vector3, CFrame, Color3, BrickColor (creatable-shared-count 00635150..00636210).
	// The 2008-06 binary has no Value<float>.
	extern char sDoubleValue[];
	extern char sColor3Value[];
	extern char sVector3Value[];
	extern char sBrickColorValue[];
	extern char sStringValue[];
	extern char sCFrameValue[];

	template<typename ValueType, const char* ClassName>
	class Value : public DescribedCreatable<Value<ValueType, ClassName>, Instance, ClassName>
	{
	private:
		ValueType value;
	private:
		static const ValueType defaultValue;
	public:
		static Reflection::BoundProp<ValueType, 1> desc_Value;
		static Reflection::SignalDesc<Value, void(ValueType)> desc_ValueChanged;

	public:
		Value();
		const Value& getValue() const;
		void setValue(const Value&);
	protected:
		virtual bool askSetParent(const Instance*) const;
	private:
		void onValueChanged(const Reflection::PropertyDescriptor&);
	};

	typedef Value<int,			sIntValue>			IntValue;
	typedef Value<bool,			sBoolValue>		BoolValue;
	typedef Value<double,		sDoubleValue>	DoubleValue;
	typedef Value<float,		sFloatValue>		FloatValue;
	typedef Value<G3D::Color3,	sColor3Value>		Color3Value;
	typedef Value<G3D::Vector3,	sVector3Value>		Vector3Value;
	typedef Value<BrickColor,	sBrickColorValue>	BrickColorValue;
	typedef Value<std::string,	sStringValue>		StringValue;
	typedef Value<G3D::CoordinateFrame, sCFrameValue> CFrameValue;

	extern char sObjectValue[];
	
	class ObjectValue : public DescribedCreatable<ObjectValue, Instance, sObjectValue>
	{
	private:
		boost::shared_ptr<Instance> value;
	public:
		static Reflection::RefPropDescriptor<ObjectValue, Instance> desc_Value;
		static Reflection::SignalDesc<ObjectValue, void(boost::shared_ptr<Instance>)> desc_ValueChanged;

	public:
		ObjectValue();
		Instance* getValue() const;
		void setValue(Instance*);
	protected:
		virtual bool askSetParent(const Instance*) const;
	private:
		void onValueChanged(const Reflection::PropertyDescriptor&);
	};

	void registerValueClasses();
}
