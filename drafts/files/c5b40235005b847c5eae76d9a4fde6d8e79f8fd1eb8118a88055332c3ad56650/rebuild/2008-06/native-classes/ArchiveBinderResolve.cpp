#include "v8xml/SerializerV2.h"
#include <boost/bind.hpp>
#include <algorithm>

bool ArchiveBinder::resolveRefs()
{
    size_t counts = std::count_if(idrefBindings.begin(), idrefBindings.end(), boost::bind(&ArchiveBinder::resolveIDREF, this, _1));
    if (!MergeBinder::resolveRefs()) return false;
    if (counts != idrefBindings.size()) return false;
    return true;
}
