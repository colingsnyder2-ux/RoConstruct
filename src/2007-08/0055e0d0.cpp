// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_native_app_workspace_29b0f02042851033.cpp

// Candidate translation unit (score above; library headers required).
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
#pragma include_alias("util/UIEvent.h", "../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp")
#pragma include_alias(<util/UIEvent.h>, <../roc_espeon_aug2007_uievent_header_3f3774ebe50da7af.cpp>)
#pragma include_alias("v8datamodel/Workspace.h", "../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp")
#pragma include_alias(<v8datamodel/Workspace.h>, <../roc_espeon_aug2007_workspace_header_d38fc45c16cb1519.cpp>)
#define _CRT_SECURE_NO_DEPRECATE
#include "v8xml/XmlElement.h"
#include "v8xml/XmlSerializer.h"
#include "util/Utilities.h"
#include "util/Debug.h"

const RBX::Name& value_IDREF_null = RBX::Name::declare("null", 1);
const RBX::Name& value_IDREF_nil = RBX::Name::declare("nil", 2);
const RBX::Name& name_xsinil = RBX::Name::declare("xsi:nil", 3);
const RBX::Name& name_xsitype = RBX::Name::declare("xsi:type", 4);
const RBX::Name& tag_xmlnsxsi = RBX::Name::declare("xmlns:xsi", 5);
const RBX::Name& name_root = RBX::Name::declare("root", 6);
const RBX::Name& name_referent = RBX::Name::declare("referent", 7);
const RBX::Name& name_DeleteItem = RBX::Name::declare("DeleteItem", 8);
const RBX::Name& tag_roblox = RBX::Name::declare("roblox", 9);
const RBX::Name& tag_version = RBX::Name::declare("version", 10);
const RBX::Name& tag_External = RBX::Name::declare("External", 11);
const RBX::Name& name_Ref = RBX::Name::declare("Ref", 12);
const RBX::Name& name_token = RBX::Name::declare("token", 13);
const RBX::Name& name_name = RBX::Name::declare("name", 14);
const RBX::Name& tag_Refs = RBX::Name::declare("Refs", 21);
const RBX::Name& tag_X = RBX::Name::declare("X", 23);
const RBX::Name& tag_Y = RBX::Name::declare("Y", 24);
const RBX::Name& tag_Z = RBX::Name::declare("Z", 25);
const RBX::Name& tag_R00 = RBX::Name::declare("R00", 26);
const RBX::Name& tag_R01 = RBX::Name::declare("R01", 27);
const RBX::Name& tag_R02 = RBX::Name::declare("R02", 28);
const RBX::Name& tag_R10 = RBX::Name::declare("R10", 29);
const RBX::Name& tag_R11 = RBX::Name::declare("R11", 30);
const RBX::Name& tag_R12 = RBX::Name::declare("R12", 31);
const RBX::Name& tag_R20 = RBX::Name::declare("R20", 32);
const RBX::Name& tag_R21 = RBX::Name::declare("R21", 33);
const RBX::Name& tag_R22 = RBX::Name::declare("R22", 34);
const RBX::Name& tag_R = RBX::Name::declare("R", 35);
const RBX::Name& tag_G = RBX::Name::declare("G", 36);
const RBX::Name& tag_B = RBX::Name::declare("B", 37);
const RBX::Name& tag_class = RBX::Name::declare("class", 38);
const RBX::Name& tag_Item = RBX::Name::declare("Item", 39);
const RBX::Name& tag_Properties = RBX::Name::declare("Properties", 40);
const RBX::Name& tag_Feature = RBX::Name::declare("Feature", 41);
const RBX::Name& tag_binary = RBX::Name::declare("binary", 44);
const RBX::Name& tag_hash = RBX::Name::declare("hash", 45);
const RBX::Name& tag_null = RBX::Name::lookup("null");
const RBX::Name& tag_mimeType = RBX::Name::declare("mimeType", 48);
const RBX::Name& tag_xsinoNamespaceSchemaLocation = RBX::Name::declare("xsi:noNamespaceSchemaLocation", 49);

void XmlNameValuePair::clearValue() const
{
	switch (valueType)
	{
	case HANDLE:
		delete handleValue;
		break;
	case STRING:
		delete stringValue;
		break;
	case CONTENTID:
		delete contentIdValue;
		break;
	}

	valueType = NONE;
}

bool XmlNameValuePair::getValue(std::string& value) const
{
	if (valueType == STRING)
	{
		value = *stringValue;
		return true;
	}

	return false;
}

bool XmlNameValuePair::getValue(const RBX::Name*& value) const
{
	if (valueType == NAME)
	{
		value = nameValue;
		return true;
	}
	else if (valueType == STRING)
	{
		value = &RBX::Name::declare(stringValue->c_str(), -1);
		clearValue();
		nameValue = value;
		valueType = NAME;
		return true;
	}

	return false;
}

bool XmlNameValuePair::getValue(RBX::ContentId& value) const
{
	if (valueType == CONTENTID)
	{
		value = *contentIdValue;
		return true;
	}
	else if (valueType == STRING)
	{
		value = RBX::ContentId(*stringValue);
		clearValue();
		contentIdValue = new RBX::ContentId(value);
		valueType = CONTENTID;
		return true;
	}

	return false;
}

bool XmlNameValuePair::getValue(int& value) const
{
	if (valueType == INT)
	{
		value = intValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<int>::convertToValue(*stringValue, value))
		{
			clearValue();
			intValue = value;
			valueType = INT;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(unsigned& value) const
{
	if (valueType == UINT)
	{
		value = uintValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<unsigned>::convertToValue(*stringValue, value))
		{
			clearValue();
			uintValue = value;
			valueType = UINT;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(bool& value) const
{
	if (valueType == BOOL)
	{
		value = boolValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<bool>::convertToValue(*stringValue, value))
		{
			clearValue();
			boolValue = value;
			valueType = BOOL;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(float& value) const
{
	if (valueType == FLOAT)
	{
		value = floatValue;
		return true;
	}
	else if (valueType == STRING)
	{
		if (RBX::StringConverter<float>::convertToValue(*stringValue, value))
		{
			clearValue();
			floatValue = value;
			valueType = FLOAT;
			return true;
		}
	}

	return false;
}

bool XmlNameValuePair::getValue(RBX::InstanceHandle& value) const
{
	if (valueType == NAME && *nameValue == value_IDREF_null)
	{
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}
	else if (valueType == STRING && value_IDREF_null == *stringValue)
	{
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}
	else if (valueType == STRING && *stringValue == "")
	{
		clearValue();
		handleValue = new RBX::InstanceHandle(NULL);
		valueType = HANDLE;
	}

	if (valueType == HANDLE)
	{
		value = *handleValue;
		return true;
	}

	return false;
}

template<>
bool XmlNameValuePair::isValueType<RBX::ContentId>() const
{
	return valueType == CONTENTID;
}

template<>
bool XmlNameValuePair::isValueType<std::string>() const
{
	return valueType == STRING;
}

bool XmlNameValuePair::isValueEqual(const RBX::Name* value) const
{
	switch (valueType)
	{
	case NAME:
		return value == nameValue;
	case STRING:
		return *value == *stringValue;
	default:
		return false;
	}
}

std::string XmlNameValuePair::toString(XmlWriter* writer) const
{
	switch (valueType)
	{
	case NONE:
		return "";
	case BOOL:
		return RBX::StringConverter<bool>::convertToString(boolValue);
	case INT:
		return RBX::StringConverter<int>::convertToString(intValue);
	case UINT:
		return RBX::StringConverter<unsigned>::convertToString(uintValue);
	case FLOAT:
		return RBX::StringConverter<float>::convertToString(floatValue);
	case NAME:
		return nameValue->toString();
	case HANDLE:
		if (!handleValue->getTarget())
		{
			return value_IDREF_null.name;
		}
		else
		{
			int index = writer->getHandleIndex(*handleValue);

			char buffer[32];
			sprintf(buffer, "RBX%d", index);
			return buffer;
		}
	case STRING:
		return *stringValue;
	case CONTENTID:
		return contentIdValue->toString();
	default:
		RBXASSERT(0);
		return "";
	}
}

void XmlNameValuePair::replaceHandles(const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	typedef std::map<RBX::Instance*, RBX::InstanceHandle>::const_iterator Iter;

	if (valueType == HANDLE)
	{
		Iter r = isolationMap.find(handleValue->getTarget().get());

		if (r != isolationMap.end())
		{
			*handleValue = r->second;
		}
	}
}

XmlAttribute* XmlElement::findAttribute(const RBX::Name& _tag)
{
	XmlAttribute* attribute;
	for (attribute = attributes.firstChild(); attribute != NULL; attribute = attribute->nextSibling())
	{
		if (attribute->getTag() == _tag)
			return attribute;
	}

	return NULL;
}

const XmlAttribute* XmlElement::findAttribute(const RBX::Name& _tag) const
{
	const XmlAttribute* attribute;
	for (attribute = attributes.firstChild(); attribute != NULL; attribute = attribute->nextSibling())
	{
		if (attribute->getTag() == _tag)
			return attribute;
	}

	return NULL;
}

const XmlElement* XmlElement::findFirstChildByTag(const RBX::Name& _tag) const
{
	const XmlElement* child;
	for (child = firstChild(); child != NULL; child = child->nextSibling())
	{
		if (child->getTag() == _tag)
			return child;
	}

	return NULL;
}

const XmlElement* XmlElement::findNextChildWithSameTag(const XmlElement* node) const
{
	const XmlElement* child;
	for (child = node->nextSibling(); child != NULL; child = child->nextSibling())
	{
		if (child->getTag() == node->getTag())
			return child;
	}

	return NULL;
}

bool XmlElement::isXsiNil() const
{
	bool isXsiNil;
	const XmlAttribute* attribute = findAttribute(name_xsinil);
	return attribute && attribute->getValue(isXsiNil) && isXsiNil;
}
