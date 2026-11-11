// Rebuild glue: SerializerV2::loadInstances, which rbxgs declares and calls (ContentProvider::load,
// Instance::clone, the 2008 paste and insert verbs) but never defines. It reads each top-level <Item>
// the way Instance::readChild does, without parenting, then resolves references like
// SerializerV2::load. Behavioural reconstruction, not byte-verified.
#include "v8xml/SerializerV2.h"
#include "v8xml/XmlElement.h"
#include "v8tree/Instance.h"

