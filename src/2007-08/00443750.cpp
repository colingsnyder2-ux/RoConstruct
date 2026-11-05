// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS /EHsc /MD
// roc-lib: rbxgs roc_espeon_aug2007_viewport_family_8d8c6f47be21aa78.cpp

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
#include "v8xml/SerializerV2.h"
#include "v8datamodel/DataModel.h"
#include <boost/bind.hpp>
#include <algorithm>

bool ArchiveBinder::resolveRefs()
{
	size_t counts = std::count_if(idrefBindings.begin(), idrefBindings.end(), boost::bind(&ArchiveBinder::resolveIDREF, this, _1));

	return MergeBinder::resolveRefs() && counts == idrefBindings.size();
}

bool ArchiveBinder::resolveIDREF(IDREFBinding binding)
{
	std::string s;
	bool success = binding.valueIDREF->getValue(s);

	RBXASSERT(success);
	RBXASSERT(value_IDREF_nil.name.compare(s));
	RBXASSERT(value_IDREF_null.name.compare(s));
	RBXASSERT(s != "");

	std::map<std::string, RBX::InstanceHandle>::iterator found = idMap.find(s);
	if (found != idMap.end())
	{
		RBX::InstanceHandle& foundHandle = found->second;
		binding.idref->assignIDREF(binding.propertyOwner,foundHandle);
		return true;
	}
	else
	{
		binding.idref->assignIDREF(binding.propertyOwner,RBX::InstanceHandle(NULL));
		return false;
	}
}

bool ArchiveBinder::processID(const XmlNameValuePair* valueID, RBX::Instance* source)
{
	if (!MergeBinder::processID(valueID, source))
	{
		std::string s;
		bool success = valueID->getValue(s);

		RBXASSERT(success);
		RBXASSERT(idMap.find(s) == idMap.end());

		idMap[s] = shared_from(source);
	}

	return true;
}

bool ArchiveBinder::processIDREF(const XmlNameValuePair* valueIDREF, RBX::Reflection::DescribedBase* propertyOwner, const RBX::IIDREF* idref)
{
	if (!MergeBinder::processIDREF(valueIDREF, propertyOwner, idref))
	{
		IDREFBinding binding = {valueIDREF, propertyOwner, idref};
		idrefBindings.push_back(binding);
	}

	return true;
}

static void buildIsolationMap(XmlElement* element, std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	XmlAttribute* referent = element->findAttribute(name_referent);
	if (referent)
	{
		RBX::InstanceHandle h;
		bool success = referent->getValue(h);

		RBXASSERT(success);
		RBXASSERT(isolationMap.find(h.getTarget().get()) == isolationMap.end());

		isolationMap[h.getTarget().get()] = RBX::InstanceHandle();
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = element->nextChild(child))
	{
		buildIsolationMap(child, isolationMap);
	}
}

static void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	element->replaceHandles(isolationMap);

	for (XmlAttribute* attr = element->getFirstAttribute(); attr != NULL; attr = element->getNextAttribute(attr))
	{
		attr->replaceHandles(isolationMap);
	}

	for (XmlElement* elem = element->firstChild(); elem != NULL; elem = element->nextChild(elem))
	{
		isolate(elem, isolationMap);
	}
}

void SerializerV2::isolateHandles(XmlElement* root)
{
	std::map<RBX::Instance*, RBX::InstanceHandle> isolationMap;

	buildIsolationMap(root, isolationMap);
	isolate(root, isolationMap);
}

XmlElement* SerializerV2::newRootElement()
{
	static const RBX::Name& tag_xmlnsxmime = RBX::Name::declare("xmlns:xmime", -1);

	XmlElement* thisElement = new XmlElement(tag_roblox);
	thisElement->addAttribute(tag_xmlnsxmime,"http://www.w3.org/2005/05/xmlmime");
	thisElement->addAttribute(tag_xmlnsxsi,"http://www.w3.org/2001/XMLSchema-instance");
	thisElement->addAttribute(tag_xsinoNamespaceSchemaLocation,"http://www.roblox.com/roblox.xsd");

	thisElement->addAttribute(tag_version, 4);

	thisElement->pushBackChild(new XmlElement(tag_External, &value_IDREF_null));
	thisElement->pushBackChild(new XmlElement(tag_External, &value_IDREF_nil));

	return thisElement;
}

void SerializerV2::load(XmlElement* root, RBX::DataModel* dataModel)
{
	ArchiveBinder binder;
	dataModel->readChildren(root, binder);

	binder.resolveRefs();
}

void SerializerV2::loadXML(std::istream& stream, RBX::DataModel* dataModel)
{
	TextXmlParser machine(stream.rdbuf());
	std::auto_ptr<XmlElement> root = machine.parse();

	if (root->getTag() == tag_roblox)
	{
		XmlAttribute* version = root->findAttribute(tag_version);
		if (!version->getValue(schemaVersionLoading))
			throw std::runtime_error("SerializerV2::loadXML no version number");

		if (schemaVersionLoading < 4)
			throw std::runtime_error("SerializerV2::loadXML schemaVersionLoading<4");

		load(root.get(), dataModel);
		dataModel->setDirty(false);
	}
	else
	{
		schemaVersionLoading = 1;
		throw std::runtime_error("SerializerV2::loadXML ill-formed XML. No Roblox tag");
	}
}
