#include "v8datamodel/Selection.h"

boost::shared_ptr<RBX::Instance> RBX::Selection::front() const
{
    return selection->size() > 0 ? *selection->begin() : boost::shared_ptr<Instance>();
}
