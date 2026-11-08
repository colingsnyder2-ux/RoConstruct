#pragma once
// >>> native-status (generated) -- do not edit >>>
// SelectionGroup | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 422dd290 | roc native-status --write
#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance;
namespace Reflection { class ClassDescriptor; }
// Recovery name; original helpers 00442350/00439660 prove grouping by descriptor.
class SelectionGroup : public std::map<const Reflection::ClassDescriptor*,
                                       std::vector<boost::shared_ptr<Instance> > > {
public:
    void add(Instance*);
    void remove(Instance*);
};
}
