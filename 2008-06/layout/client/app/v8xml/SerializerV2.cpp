// =============================================================================
// SerializerV2.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8xml/SerializerV2.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8xml/XmlElement.h"
#include "metadata-load/v8xml/SerializerV2.h"

void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap); // 00591d30

// BLOCKER (core util/Handle.h, header owner): it declares `~InstanceHandle(void);` out of line (INFERRED header-gap
void buildIsolationMap(XmlElement* element, std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	XmlAttribute* referent = element->findAttribute(name_referent);
	if (referent)
	{
		RBX::InstanceHandle h;
		referent->getValue(h);

		isolationMap[h.getTarget().get()] = RBX::InstanceHandle();
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = element->nextChild(child))
	{
		buildIsolationMap(child, isolationMap);
	}
}

void SerializerV2::isolateHandles(XmlElement* root)
{
	std::map<RBX::Instance*, RBX::InstanceHandle> isolationMap;

	buildIsolationMap(root, isolationMap);
	isolate(root, isolationMap);
}

void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap);

void isolate(XmlElement* element, const std::map<RBX::Instance*, RBX::InstanceHandle>& isolationMap)
{
	element->replaceHandles(isolationMap);

	for (XmlAttribute* attribute = element->getFirstAttribute(); attribute != NULL; attribute = element->getNextAttribute(attribute))
	{
		attribute->replaceHandles(isolationMap);
	}

	for (XmlElement* child = element->firstChild(); child != NULL; child = element->nextChild(child))
	{
		isolate(child, isolationMap);
	}
}

bool ArchiveBinder::resolveIDREF(IDREFBinding binding)
{
	std::string s;
	binding.valueIDREF->getValue(s);

	std::map<std::string, RBX::InstanceHandle>::iterator iter = idMap.find(s);

	if (iter != idMap.end()) {
		const RBX::InstanceHandle& value = iter->second;

		binding.idref->assignIDREF(binding.propertyOwner, value);

		return true;
	}

	binding.idref->assignIDREF(binding.propertyOwner, RBX::InstanceHandle(NULL));

	return false;
}

bool ArchiveBinder::resolveRefs()
{
	size_t resolvedCount = std::count_if(
		idrefBindings.begin(),
		idrefBindings.end(),
		std::bind1st(std::mem_fun(&ArchiveBinder::resolveIDREF), this)
	);

	return MergeBinder::resolveRefs() && resolvedCount == idrefBindings.size();
}

bool ArchiveBinder::processID(const XmlNameValuePair* valueID, RBX::Instance* source)
{
	if (!MergeBinder::processID(valueID, source)) {
		std::string s;
		valueID->getValue(s);

		idMap[s].linkTo(RBX::shared_from(source));
	}

	return true;
}

// Explicit instantiations: they give this file the same symbols as the original object,
// where other files used them. Likely removable once the whole client links and those users exist.
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >;
template class std::_Vector_const_iterator<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;
template class std::_Vector_iterator<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;
template class std::allocator<RBX::MergeBinder::IDREFItem>;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >;
template class std::deque<XmlElement *,std::allocator<XmlElement *> >;
template class std::vector<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;

bool ArchiveBinder::processIDREF(const XmlNameValuePair* valueIDREF, RBX::Reflection::DescribedBase* propertyOwner, const RBX::IIDREF* idref)
{
	if (!MergeBinder::processIDREF(valueIDREF, propertyOwner, idref))
	{
		IDREFBinding binding = {valueIDREF, propertyOwner, idref};
		idrefBindings.push_back(binding);
	}

	return true;
}
