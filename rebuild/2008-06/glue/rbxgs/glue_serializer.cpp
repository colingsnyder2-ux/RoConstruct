// Rebuild glue: SerializerV2::loadInstances, which rbxgs declares and calls (ContentProvider::load,
// Instance::clone, the 2008 paste and insert verbs) but never defines. It reads each top-level <Item>
// the way Instance::readChild does, without parenting, then resolves references like
// SerializerV2::load. Behavioural reconstruction, not byte-verified.
#include "v8xml/SerializerV2.h"
#include "v8xml/XmlElement.h"
#include "v8tree/Instance.h"

void SerializerV2::loadInstances(XmlElement* root, std::vector<boost::shared_ptr<RBX::Instance> >& instances)
{
	if (!root)
		return;

	ArchiveBinder binder;
	for (const XmlElement* item = root->findFirstChildByTag(tag_Item); item != NULL; item = root->findNextChildWithSameTag(item))
	{
		const RBX::Name* className = NULL;
		const XmlAttribute* classAttrib = item->findAttribute(tag_class);
		if (!classAttrib || !classAttrib->getValue(className))
			continue;

		boost::shared_ptr<RBX::Instance> instance = RBX::AbstractFactoryProduct<RBX::Instance>::create(*className);
		if (!instance)
			continue;

		instance->read(item, binder);
		instances.push_back(instance);
	}

	binder.resolveRefs();
}
