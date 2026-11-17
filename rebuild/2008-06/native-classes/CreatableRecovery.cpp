// Native template instantiations.
#include "v8datamodel/Feature.h"
#include "v8datamodel/Mouse.h"
namespace RBX {
template boost::shared_ptr<Hole> Creatable<Instance>::create<Hole>();
template boost::shared_ptr<Mouse> Creatable<Instance>::create<Mouse>();
}
