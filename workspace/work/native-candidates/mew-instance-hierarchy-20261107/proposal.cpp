// Inactive 2008 Instance hierarchy methods, reviewed from mewpokemons contributor source.
#include "v8tree/Instance.h"
#include <algorithm>
#include <boost/bind.hpp>

namespace RBX {
bool Instance::contains(const Instance* child) const
{
    for (; child != NULL; child = child->parent) {
        if (child == this)
            return true;
    }
    return false;
}

void Instance::removeAllChildren()
{
    while (children)
        children->back()->setParent(NULL);
}

void Instance::remove()
{
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > c = children.read();
    setParent(NULL);
    if (c)
        std::for_each(c->begin(), c->end(), boost::bind(&Instance::remove, _1));
}
}
