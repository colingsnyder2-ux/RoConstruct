#pragma once
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
