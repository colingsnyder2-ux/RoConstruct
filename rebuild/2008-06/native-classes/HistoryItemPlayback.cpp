#include "v8datamodel/HistoryRecord.h"
#include "v8tree/Instance.h"
#include <boost/bind.hpp>
#include <algorithm>

void RBX::HistoryItem::play()
{
    switch (kind) {
    case 1:
        std::for_each(properties.begin(), properties.end(), boost::bind(&HistoryItem::applyProperty, this, _1));
        object->setParent(parent.get());
        break;
    case 2:
        std::for_each(properties.begin(), properties.end(), boost::bind(&HistoryItem::applyProperty, this, _1));
        break;
    case 3:
        object->setParent(NULL);
        break;
    }
}
