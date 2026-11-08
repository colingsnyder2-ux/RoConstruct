#include "v8datamodel/Selection.h"

namespace RBX {

boost::shared_ptr<Instance> Selection::back() const
{
    return selection->size() > 0 ? selection->back() : boost::shared_ptr<Instance>();
}

}
