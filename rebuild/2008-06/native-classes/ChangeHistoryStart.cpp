// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ChangeHistoryStart | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 713e1fac | roc native-status --write
#include "v8datamodel/ChangeHistoryService.h"
#include "v8datamodel/HistoryRecord.h"
#include <boost/bind.hpp>

namespace RBX { namespace Reflection {
template<class S>
SignalDescImpl<2, S>::GenericSlotAdapter::GenericSlotAdapter(GenericSlotWrapper* wrapper)
    : wrapper(wrapper)
{
}

template<class S>
void SignalDescImpl<2, S>::GenericSlotAdapter::operator()(
    typename boost::function_traits<S>::arg1_type a, typename boost::function_traits<S>::arg2_type b)
{
    std::vector<boost::any> args(2);
    args[0] = a;
    args[1] = b;
    wrapper->execute(args);
}

template<class S>
boost::signals::connection SignalDescImpl<2, S>::connectGeneric(
    SignalInstance* instance, GenericSlotWrapper* wrapper, boost::signals::connect_position pos) const
{
    return static_cast<typename TSignalDesc<S>::TSignalInstance*>(instance)->connect(GenericSlotAdapter(wrapper), pos);
}
}}

RBX::Reflection::SignalDesc<RBX::Instance, void(boost::shared_ptr<RBX::Instance>, const RBX::Reflection::PropertyDescriptor*)>
    RBX::Instance::event_itemChanged("ItemChanged", "object", "descriptor");

void RBX::ChangeHistoryService::start()
{
    current = new HistoryRecord(this);
    forward = history.end();
    backward = history.begin();
    context->visitDescendents(boost::bind(&ChangeHistoryService::onHistoryAdded, this, _1));
    if (enabled) {
        commit("base");
        while (history.size() > 1) mergeFirst();
    }
    connectionAdded = Instance::event_descendentAdded.connect(context, boost::bind(&ChangeHistoryService::onHistoryAdded, this, _1), 10);
    connectionRemoved = Instance::event_descendentRemoving.connect(context, boost::bind(&ChangeHistoryService::onHistoryRemoving, this, _1), 10);
    connectionChanged = Instance::event_itemChanged.connect(context, boost::bind(&ChangeHistoryService::onHistoryChanged, this, _1, _2), 10);
}