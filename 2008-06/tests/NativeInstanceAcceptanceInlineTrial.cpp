// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/instance-ancestor-inline
#include "v8tree/Instance.h"

bool RBX::Instance::canAcceptChildren(std::vector<boost::shared_ptr<Instance> >::const_iterator first,
                                      std::vector<boost::shared_ptr<Instance> >::const_iterator last)
{
    for (; first != last; ++first) {
        Instance* child = first->get();
        if (!child || child->isAncestorOf(this) || child->getParent() == this ||
            (!askAddChild(child) && !child->askSetParent(this)))
            return false;
    }
    return true;
}
