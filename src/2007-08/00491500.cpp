// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_viewport_family_6af0c332b3e7d86e.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("v8datamodel/JointsService.h", "../roc_espeon_aug2007_joints_service_header_70eae11bae482e15.cpp")
#pragma include_alias(<v8datamodel/JointsService.h>, <../roc_espeon_aug2007_joints_service_header_70eae11bae482e15.cpp>)
#pragma include_alias("v8datamodel/DebrisService.h", "../roc_espeon_aug2007_debris_pinned_header_2c0ad23d27535ab8.cpp")
#pragma include_alias(<v8datamodel/DebrisService.h>, <../roc_espeon_aug2007_debris_pinned_header_2c0ad23d27535ab8.cpp>)
#undef _RELEASEASSERT
#pragma include_alias("v8world/Edge.h", "../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp")
#pragma include_alias(<v8world/Edge.h>, <../roc_espeon_aug2007_edge_header_cb216aa0cb409651.cpp>)
#pragma include_alias("v8world/Contact.h", "../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp")
#pragma include_alias(<v8world/Contact.h>, <../roc_espeon_aug2007_contact_header_5ec74239b50ff6ca.cpp>)
#define _MT 1
#define _DLL 1
#pragma include_alias("v8kernel/KernelIndex.h", "../roc_espeon_aug2007_kernelindex_header_d7778b4d74bcf4c0.cpp")
#pragma include_alias("v8kernel/Body.h", "../roc_espeon_aug2007_body_header_b251c002665e01af.cpp")
#pragma include_alias("util/Extents.h", "../roc_espeon_aug2007_extents_inline_58e475d56d206314.cpp")
#pragma include_alias("reflection/object.h", "../roc_espeon_aug2007_describedbase_e64c736f24da029d.cpp")
#pragma include_alias("util/Debug.h", "../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp")
#pragma include_alias(<util/Debug.h>, <../roc_espeon_aug2007_ctor_debugable_025e0cb3bb8217d3.cpp>)
#pragma include_alias("util/Events.h", "../roc_espeon_aug2007_datamodel_header_e4d5a36bea2e4f16.cpp")
#pragma include_alias("reflection/reflection.h", "../roc_espeon_aug2007_described_arg_header_14221fd67bb3ca43.cpp")
#pragma include_alias("v8tree/Instance.h", "../roc_espeon_aug2007_instance_header_47f25dc9e4368119.cpp")
#pragma include_alias("v8datamodel/PartInstance.h", "../roc_espeon_aug2007_part_flags_header_a6acc69782cd7c29.cpp")
#pragma include_alias("v8world/Primitive.h", "../roc_espeon_aug2007_primitive_trivial_header_ac300ff64c6fc5e6.cpp")
#pragma include_alias("v8datamodel/DataModel.h", "../roc_espeon_aug2007_datamodel_mutex_header_321a3c67de644a82.cpp")
#pragma include_alias("v8tree/Verb.h", "../roc_espeon_aug2007_datamodel_header_c06d28d1a6b724f6.cpp")
#pragma include_alias("util/Evaluator.h", "../roc_espeon_aug2007_datamodel_header_4ba4cf67c400aa66.cpp")
#pragma include_alias(<boost/signals/signal_template.hpp>, <../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp>)
#pragma include_alias("boost/signals/signal_template.hpp", "../roc_espeon_boost133_signals_header_a54048d539243d2e.cpp")
#include "roc_espeon_boost133_header_d432d72f8740aec3.cpp"
#include "roc_espeon_boost133_header_d9eb4711b7fc841c.cpp"
#include "roc_espeon_boost133_signals_header_be197e98651271fa.cpp"

#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_header_bb71fe27a95b99c9.cpp>)
#pragma include_alias("v8world/IPipelined.h", "../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp")
#pragma include_alias(<v8world/IPipelined.h>, <../roc_espeon_aug2007_ipipelined_header_459cfa06a40ba136.cpp>)
#pragma include_alias("v8world/Joint.h", "../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp")
#pragma include_alias(<v8world/Joint.h>, <../roc_espeon_aug2007_joint_accessor_header_d77e5f1c0b32672c.cpp>)
#pragma include_alias("util/IRenderable.h", "../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp")
#pragma include_alias(<util/IRenderable.h>, <../roc_espeon_aug2007_bucket_header_1deff476fbc5a7ac.cpp>)
#pragma include_alias("v8datamodel/JointInstance.h", "../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp")
#pragma include_alias(<v8datamodel/JointInstance.h>, <../roc_espeon_aug2007_jointinstance_header_2070a5362277cad1.cpp>)
#pragma include_alias("v8world/IMoving.h", "../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp")
#pragma include_alias(<v8world/IMoving.h>, <../roc_espeon_aug2007_imoving_header_a7323a6be498a3c4.cpp>)
#pragma include_alias("v8kernel/IStage.h", "../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp")
#pragma include_alias(<v8kernel/IStage.h>, <../roc_espeon_aug2007_istage_header_b0262a91d28a95d1.cpp>)
#pragma include_alias("reflection/function.h", "../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp")
#pragma include_alias(<reflection/function.h>, <../roc_espeon_aug2007_abstract_header_991b5e9635f5d75d.cpp>)
#pragma include_alias("reflection/member.h", "../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp")
#pragma include_alias(<reflection/member.h>, <../roc_espeon_aug2007_abstract_header_56ab3d07f46302ce.cpp>)
#pragma include_alias("reflection/property.h", "../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp")
#pragma include_alias(<reflection/property.h>, <../roc_espeon_aug2007_abstract_header_4b7af236c124d7bd.cpp>)
#pragma include_alias("reflection/signal.h", "../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp")
#pragma include_alias(<reflection/signal.h>, <../roc_espeon_aug2007_abstract_header_35400af2df14a7cc.cpp>)
#pragma include_alias("script/Script.h", "../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp")
#pragma include_alias(<script/Script.h>, <../roc_espeon_aug2007_abstract_header_206648adc176eff8.cpp>)
#pragma include_alias("util/ICameraSubject.h", "../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp")
#pragma include_alias(<util/ICameraSubject.h>, <../roc_espeon_aug2007_abstract_header_15846f007cad7f25.cpp>)
#pragma include_alias("util/IControllable.h", "../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp")
#pragma include_alias(<util/IControllable.h>, <../roc_espeon_aug2007_abstract_header_134fb1e5a9dd6b81.cpp>)
#pragma include_alias("util/ILocation.h", "../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp")
#pragma include_alias(<util/ILocation.h>, <../roc_espeon_aug2007_abstract_header_b220b165aaf2f641.cpp>)
#pragma include_alias("v8datamodel/ICameraOwner.h", "../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp")
#pragma include_alias(<v8datamodel/ICameraOwner.h>, <../roc_espeon_aug2007_abstract_header_328a7f313eb894b0.cpp>)
#pragma include_alias("v8datamodel/ICharacterSubject.h", "../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp")
#pragma include_alias(<v8datamodel/ICharacterSubject.h>, <../roc_espeon_aug2007_abstract_header_72d3fec55ed90c1f.cpp>)
#pragma include_alias("v8datamodel/IPrimaryPart.h", "../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp")
#pragma include_alias(<v8datamodel/IPrimaryPart.h>, <../roc_espeon_aug2007_abstract_header_d558c6e252d36c0e.cpp>)
#pragma include_alias("v8datamodel/PVInstance.h", "../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp")
#pragma include_alias(<v8datamodel/PVInstance.h>, <../roc_espeon_aug2007_abstract_header_e7c5a66547093118.cpp>)
#pragma include_alias("v8tree/Service.h", "../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp")
#pragma include_alias(<v8tree/Service.h>, <../roc_espeon_aug2007_abstract_header_cf6415ca14eaa52c.cpp>)
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_viewport_header_04331f71cbc5bc08.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#include "reflection/type.h"
#include <g3d/color3.h>
#include <g3d/vector3.h>
#include <boost/shared_ptr.hpp>
#include "v8tree/Instance.h"
#include "v8datamodel/BrickColor.h"

namespace RBX
{
	namespace Reflection
	{
		// TODO: check if type singletons are matching
		template<>
		const Type& Type::singleton<boost::shared_ptr<RBX::Reflection::DescribedBase>>()
		{
			static Type type("Object", typeid(boost::shared_ptr<RBX::Reflection::DescribedBase>));
			return type;
		}

		template<>
		const Type& Type::singleton<boost::shared_ptr<Instance>>()
		{
			static Type type("Instance", typeid(boost::shared_ptr<Instance>));
			return type;
		}

		template<>
		const Type& Type::singleton<boost::shared_ptr<Instances>>()
		{
			static Type type("Objects", typeid(boost::shared_ptr<Instances>));
			return type;
		}

		template<>
		const Type& Type::singleton<int>()
		{
			static Type type("int", typeid(int));
			return type;
		}

		template<>
		const Type& Type::singleton<bool>()
		{
			static Type type("bool", typeid(bool));
			return type;
		}

		template<>
		const Type& Type::singleton<float>()
		{
			static Type type("float", typeid(float));
			return type;
		}

		template<>
		const Type& Type::singleton<double>()
		{
			static Type type("double", typeid(double));
			return type;
		}

		template<>
		const Type& Type::singleton<ContentId>()
		{
			static Type type("ContentId", typeid(ContentId));
			return type;
		}

		template<>
		const Type& Type::singleton<std::string>()
		{
			static Type type("string", typeid(std::string));
			return type;
		}

		template<>
		const Type& Type::singleton<G3D::Vector3>()
		{
			static Type type("Vector3", typeid(G3D::Vector3));
			return type;
		}

		template<>
		const Type& Type::singleton<G3D::Color3>()
		{
			static Type type("Color3", typeid(G3D::Color3));
			return type;
		}

		template<>
		const Type& Type::singleton<std::vector<Value>>()
		{
			static Type type("Table", typeid(std::vector<Value>));
			return type;
		}

		template<>
		const Type& Type::singleton<BrickColor>()
		{
			static Type type("BrickColor", typeid(BrickColor));
			return type;
		}

		template<>
		std::string TypedPropertyDescriptor<std::string>::getStringValue(const DescribedBase* instance) const
		{
			return getValue(instance);
		}

		template<>
		std::string TypedPropertyDescriptor<bool>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<bool>::convertToString(getValue(instance));
		}

		template<>
		std::string TypedPropertyDescriptor<float>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<float>::convertToString(getValue(instance));
		}

		template<>
		std::string TypedPropertyDescriptor<int>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<int>::convertToString(getValue(instance));
		}

		template<>
		std::string TypedPropertyDescriptor<G3D::Vector3>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<G3D::Vector3>::convertToString(getValue(instance));
		}

		template<>
		std::string TypedPropertyDescriptor<G3D::Color3>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<G3D::Color3>::convertToString(getValue(instance));
		}

		template<>
		std::string TypedPropertyDescriptor<ContentId>::getStringValue(const DescribedBase* instance) const
		{
			return StringConverter<ContentId>::convertToString(getValue(instance));
		}

		template<>
		bool TypedPropertyDescriptor<std::string>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			setValue(instance, text);
			return true;
		}

		template<>
		bool TypedPropertyDescriptor<bool>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			bool value;
			if (StringConverter<bool>::convertToValue(text, value))
			{
				setValue(instance, value);
				return true;
			}

			return false;
		}

		template<>
		bool TypedPropertyDescriptor<float>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			float value;
			if (StringConverter<float>::convertToValue(text, value))
			{
				setValue(instance, value);
				return true;
			}

			return false;
		}

		template<>
		bool TypedPropertyDescriptor<int>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			int value;
			if (StringConverter<int>::convertToValue(text, value))
			{
				setValue(instance, value);
				return true;
			}

			return false;
		}

		template<>
		bool TypedPropertyDescriptor<G3D::Vector3>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			G3D::Vector3 value;
			if (StringConverter<G3D::Vector3>::convertToValue(text, value))
			{
				setValue(instance, value);
				return true;
			}

			return false;
		}

		template<>
		bool TypedPropertyDescriptor<G3D::Color3>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			G3D::Color3 value;
			if (StringConverter<G3D::Color3>::convertToValue(text, value))
			{
				setValue(instance, value);
				return true;
			}

			return false;
		}

		template<>
		bool TypedPropertyDescriptor<ContentId>::setStringValue(DescribedBase* instance, const std::string& text) const
		{
			ContentId value;
			if (StringConverter<ContentId>::convertToValue(text, value))
			{
				setValue(instance, value);
				return true;
			}

			return false;
		}

		template<>
		void TypedPropertyDescriptor<float>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				float value;
				if (element->getValue(value))
				{
					setValue(instance, value);
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<float>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			float value = getValue(instance);
			element->setValue(value);
		}

		template<>
		void TypedPropertyDescriptor<bool>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				bool value;
				if (element->getValue(value))
				{
					setValue(instance, value);
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<bool>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			bool value = getValue(instance);
			element->setValue(value);
		}

		template<>
		void TypedPropertyDescriptor<BrickColor>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				int value;
				if (element->getValue(value))
				{
					setValue(instance, BrickColor(value));
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<BrickColor>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			element->setValue(getValue(instance).asInt());
		}

		template<>
		void TypedPropertyDescriptor<int>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				int value;
				if (element->getValue(value))
				{
					setValue(instance, value);
				}
			}
		}
		
		template<>
		void TypedPropertyDescriptor<int>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			int value = getValue(instance);
			element->setValue(value);
		}

		template<>
		void TypedPropertyDescriptor<ContentId>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				ContentId value;
				if (element->getValue(value))
				{
					setValue(instance, value);
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<ContentId>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			element->setValue(ContentId(getValue(instance)));
		}

		template<>
		void TypedPropertyDescriptor<std::string>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				std::string value;
				if (element->getValue(value))
				{
					setValue(instance, value);
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<std::string>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			element->setValue(getValue(instance));
		}

		template<>
		void TypedPropertyDescriptor<G3D::Vector3>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				if (const XmlElement* X = element->findFirstChildByTag(tag_X))
				{
					const XmlElement* Y = element->findFirstChildByTag(tag_Y);
					const XmlElement* Z = element->findFirstChildByTag(tag_Z);

					G3D::Vector3 value;

					X->getValue(value.x);
					Y->getValue(value.y);
					Z->getValue(value.z);

					setValue(instance, value);
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<G3D::Vector3>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			const Name* xName = &tag_X;
			XmlElement* xElement = new XmlElement(*xName);
			element->pushBackChild(xElement);

			const Name* yName = &tag_Y;
			XmlElement* yElement = new XmlElement(*yName);
			element->pushBackChild(yElement);

			const Name* zName = &tag_Z;
			XmlElement* zElement = new XmlElement(*zName);
			element->pushBackChild(zElement);

			G3D::Vector3 value = getValue(instance);

			xElement->setValue(value.x);
			yElement->setValue(value.y);
			zElement->setValue(value.z);
		}

		template<>
		void TypedPropertyDescriptor<G3D::Color3>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
		{
			if (!element->isXsiNil())
			{
				unsigned int colorValue;
				if (element->getValue(colorValue))
				{
					G3D::Color3 color = G3D::Color3(G3D::Color3uint8::fromARGB(colorValue));
					setValue(instance, color);	
				}
				else
				{
					const XmlElement* R = element->findFirstChildByTag(tag_R);
					const XmlElement* G = element->findFirstChildByTag(tag_G);
					const XmlElement* B = element->findFirstChildByTag(tag_B);

					G3D::Color3 value;

					R->getValue(value.r);
					G->getValue(value.g);
					B->getValue(value.b);

					setValue(instance, value);
				}
			}
		}

		template<>
		void TypedPropertyDescriptor<G3D::Color3>::writeValue(const DescribedBase* instance, XmlElement* element) const
		{
			G3D::Color3uint8 value = G3D::Color3uint8(getValue(instance));
			element->setValue(value.asUInt32());
		}
	}
}
