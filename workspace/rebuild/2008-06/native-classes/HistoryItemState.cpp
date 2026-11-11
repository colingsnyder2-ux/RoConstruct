// >>> native-status (generated) -- do not edit >>>
// HistoryItemState | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 37280e97 | roc native-status --write
#include "v8datamodel/HistoryRecord.h"
#include "v8tree/Instance.h"
#include <algorithm>
#include <boost/bind.hpp>

template<>
inline RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::Iterator&
RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::PropertyDescriptor>::Iterator::operator++()
{
    ++iter;
    return *this;
}

void RBX::HistoryItem::reset()
{
    parent.reset();
    properties.clear();
    kind = kind == 1 ? 0 : 3;
}

void RBX::HistoryItem::update(const Reflection::PropertyDescriptor* property)
{
    captureProperty(property);
    if (kind != 1) {
        kind = 2;
        return;
    }
    if (property == &Instance::propParent) parent = shared_from(object->getParent());
}

void RBX::HistoryItem::captureAll()
{
    std::for_each(object->properties_begin(), object->properties_end(), boost::bind(&HistoryItem::capture, this, _1));
    parent = shared_from(object->getParent());
    kind = 1;
}

void RBX::HistoryItem::capture(const Reflection::Property& property)
{
    const Reflection::PropertyDescriptor* descriptor = &property.getDescriptor();
    if (descriptor != &Instance::propParent) captureProperty(descriptor);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::_mfi::mf1<void,RBX::HistoryItem,RBX::Reflection::Property const &>;
