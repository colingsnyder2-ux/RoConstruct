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
