#define NATIVE_DESCENDANT_HELPERS_ONLY
#include "../native-classes/InstanceDescendantEvents.cpp"

template void RBX::Notifier<RBX::Instance, RBX::DescendantRemoving>::raise(RBX::DescendantRemoving) const;
template void RBX::Notifier<RBX::Instance, RBX::DescendantAdded>::raise(RBX::DescendantAdded) const;
template void RBX::Reflection::SignalDescImpl<1, void(boost::shared_ptr<RBX::Instance>)>::fire(
    RBX::Reflection::SignalSource*, const boost::shared_ptr<RBX::Instance>);
