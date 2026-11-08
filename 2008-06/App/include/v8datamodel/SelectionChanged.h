#pragma once
// >>> native-status (generated) -- do not edit >>>
// SelectionChanged | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 90840113 | roc native-status --write
#include <boost/shared_ptr.hpp>

namespace RBX {
class Instance;
class Selection;

// Existing Selection event source; native callbacks confirm two shared owners.
class SelectionChanged {
    friend class Selection;
public:
    const boost::shared_ptr<Instance> addedItem;
    const boost::shared_ptr<Instance> removedItem;
private:
    SelectionChanged(boost::shared_ptr<Instance> added, boost::shared_ptr<Instance> removed)
        : addedItem(added), removedItem(removed) {}
};
}
