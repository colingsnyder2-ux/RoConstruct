// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include "metadata-load/v8xml/SerializerV2.h"

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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tree<std::_Tmap_traits<std::basic_string<char,std::char_traits<char>,std::allocator<char> >,RBX::InstanceHandle,std::less<std::basic_string<char,std::char_traits<char>,std::allocator<char> > >,std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >,0> >;
template class std::_Vector_const_iterator<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;
template class std::_Vector_iterator<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;
template class std::allocator<RBX::MergeBinder::IDREFItem>;
template class std::allocator<std::pair<std::basic_string<char,std::char_traits<char>,std::allocator<char> > const ,RBX::InstanceHandle> >;
template class std::deque<XmlElement *,std::allocator<XmlElement *> >;
template class std::vector<RBX::MergeBinder::IDREFItem,std::allocator<RBX::MergeBinder::IDREFItem> >;
