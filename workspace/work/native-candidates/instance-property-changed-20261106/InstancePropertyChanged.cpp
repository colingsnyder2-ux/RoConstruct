// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT /I{headers}/../../../work/native-candidates/instance-property-changed-20261106/profile /I{headers}/std-noinline-string /I{headers}/runservice-events
#include "v8tree/Instance.h"
#include "v8tree/PropertyChanged.h"
namespace RBX {
void Instance::raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor) {
    PropertyChanged event(Reflection::Property(descriptor, this));
    Notifier<Instance, PropertyChanged>::raise(event);
    if (!event_propertyChanged.empty(this)) event_propertyChanged.fire(this, &descriptor);
    Instance* p = parent;
    if (p) p->onChildChanged(this, event);
}
}


typedef char NativePropertySize[sizeof(RBX::Reflection::Property) == 8 ? 1 : -1];
typedef char NativePropertyChangedSize[sizeof(RBX::PropertyChanged) == 8 ? 1 : -1];
