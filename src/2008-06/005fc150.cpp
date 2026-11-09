// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_backpackfournative1af21384465f5056.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include "util/Events.h"
struct Object;struct First{};struct Second{};struct Third{};struct Fourth{};
typedef RBX::Notifier<Object,First> N1;typedef RBX::Notifier<Object,Second> N2;typedef RBX::Notifier<Object,Third> N3;typedef RBX::Notifier<Object,Fourth> N4;
struct ObjectPrefix{virtual ~ObjectPrefix();char prefix[0x20];};struct ObjectGap{virtual ~ObjectGap();char gap[0xc8];};
struct Object:ObjectPrefix,N1,N2,ObjectGap,N3,N4{};
struct OwnerPrefix{virtual ~OwnerPrefix();char prefix[0x164];void beforeDisconnect();};struct OwnerGap{virtual ~OwnerGap();char gap[4];};
struct S:OwnerPrefix,RBX::Listener<Object,First>,RBX::Listener<Object,Second>,OwnerGap,RBX::Listener<Object,Third>,RBX::Listener<Object,Fourth>{char gap[8];boost::shared_ptr<Object> object;void disconnect();};
void S::disconnect(){beforeDisconnect();if(object){N1::disconnect(object,this);N2::disconnect(object,this);N3::disconnect(object,this);N4::disconnect(object,this);object.reset();}}
