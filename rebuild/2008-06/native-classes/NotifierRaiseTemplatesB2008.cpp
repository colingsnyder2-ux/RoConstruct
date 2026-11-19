// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native Notifier<Class, Event>::raise instances, second batch (inactive); companion of NotifierRaiseTemplates2008.cpp.
// The bodies are the read-only util/Events.h templates (listener loop with RaiseRange; try/catch of std::exception in the
// listener overload). Event copies are inline, so the shared headers' declared-only copy constructors are defined here.
//   Notifier<Instance, PropertyChanged>::raise(event, listener) 0040a1c0 (197) and raise(event) 0040a530 (143)
//   Notifier<PartInstance, CanAggregateChanged>::raise(event) 0059b220 (122)
//   Notifier<Selection, SelectionChanged>::raise(event, listener) 00566960 (171)
//   Notifier<FillToolColor, BrickColor>::raise(event, listener) 004305f0 (176)
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/ToolsPart.h"

namespace RBX
{
	inline PropertyChanged::PropertyChanged(const PropertyChanged& other) : property(other.property) {}
	inline CanAggregateChanged::CanAggregateChanged(const CanAggregateChanged& other) : canClump(other.canClump) {}

	template void Notifier<Instance, PropertyChanged>::raise(PropertyChanged, Listener<Instance, PropertyChanged>*) const;
	template void Notifier<Instance, PropertyChanged>::raise(PropertyChanged) const throw();
	template void Notifier<PartInstance, CanAggregateChanged>::raise(CanAggregateChanged) const throw();
	template void Notifier<Selection, SelectionChanged>::raise(SelectionChanged, Listener<Selection, SelectionChanged>*) const;
	template void Notifier<FillToolColor, BrickColor>::raise(BrickColor, Listener<FillToolColor, BrickColor>*) const;
}
