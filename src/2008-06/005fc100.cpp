// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_backpacknativebases03a1ff65d9fa471a.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include "util/Events.h"
struct Object;struct First{};struct Second{};
typedef RBX::Notifier<Object,First> FirstSignal;typedef RBX::Notifier<Object,Second> SecondSignal;
struct ObjectPrefix{virtual ~ObjectPrefix();char prefix[0x60];};
struct Object:ObjectPrefix,FirstSignal,SecondSignal{};
struct OwnerPrefix{virtual ~OwnerPrefix();char prefix[0x16c];};
struct S:OwnerPrefix,RBX::Listener<Object,First>,RBX::Listener<Object,Second>{char gap[0x20];boost::shared_ptr<Object> object;void disconnect();};
void S::disconnect(){if(object){FirstSignal::disconnect(object,this);SecondSignal::disconnect(object,this);object.reset();}}
