// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Notifier<Class, Event>::raise(Event, Listener*) const instances of Instance and ServiceProvider (inactive):
// the try { listener->onEvent((Class*)this, event) } catch (std::exception&) body of util/Events.h (read-only), with the
// by-value event copied inline.
//   Notifier<Instance, ChildAdded>        00557a00 (event: shared_ptr<Instance>, v8tree/InstanceEvents.h)
//   Notifier<Instance, ChildRemoved>      00557b20 (event layout equal to ChildAdded: the same 280-byte body)
//   Notifier<Instance, DescendantRemoving> 00557c40 (two shared_ptrs, AppUnit558_2008/InstanceDescendantRemoving2008.h)
//   Notifier<ServiceProvider, ServiceRemoving> 005727d0 (event: shared_ptr<Instance>, v8tree/Service.h)
#include "v8tree/InstanceEvents.h"
#include "v8tree/Service.h"
#include "AppUnit558_2008/InstanceDescendantRemoving2008.h"

namespace RBX
{
	// INFERRED: v8tree/Instance.h only forward-declares ChildRemoved; 00557b20 is byte-identical to the ChildAdded raise, so
	// the event is the same single shared_ptr<Instance>.
	struct ChildRemoved
	{
		boost::shared_ptr<Instance> child;
		ChildRemoved(const ChildRemoved& other) : child(other.child) {}
	};

	// The shared headers declare these copy constructors (004116f0 for ChildAdded) without a body; the raise bodies copy the
	// event inline, so the defaults are defined here.
	ChildAdded::ChildAdded(const ChildAdded& other) : child(other.child) {}
	ServiceRemoving::ServiceRemoving(const ServiceRemoving& other) : service(other.service) {}

	template void Notifier<Instance, ChildAdded>::raise(ChildAdded, Listener<Instance, ChildAdded>*) const;
	template void Notifier<Instance, ChildRemoved>::raise(ChildRemoved, Listener<Instance, ChildRemoved>*) const;
	template void Notifier<Instance, DescendantRemoving>::raise(DescendantRemoving, Listener<Instance, DescendantRemoving>*) const;
	template void Notifier<ServiceProvider, ServiceRemoving>::raise(ServiceRemoving, Listener<ServiceProvider, ServiceRemoving>*) const;
}
