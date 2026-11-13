#include "v8xml/SerializerV2.h"

// PORT: donor size annotations are metadata, not 2008 API.
#include "util/ContentProvider.h"
#include "util/Name.h"
#include "util/standardout.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8xml/XmlElement.h"
#include "v8xml/XmlSerializer.h"

#include <G3D/Log.h>
#include <algorithm>
#include <cstring>
#include <functional>
#include <list>
#include <map>
#include <memory>
#include <stdexcept>
#include <string>

// PORT: selective unit; other definitions remain in the 2008 object.

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

bool ArchiveBinder::processID(const XmlNameValuePair* valueID, RBX::Instance* source)
{
	if (!MergeBinder::processID(valueID, source)) {
		std::string s;
		valueID->getValue(s);

		idMap[s].linkTo(RBX::shared_from(source));
	}

	return true;
}
