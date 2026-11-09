// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_chatservicenotifiersed8a8995d91f779c.cpp

// Candidate translation unit (score above; library headers required).
#include "util/Events.h"
struct FirstSource;struct SecondSource;struct First{};struct Second{};
struct SourcePrefix{virtual ~SourcePrefix();char prefix[0x12c];};
struct FirstSource:SourcePrefix,RBX::Notifier<FirstSource,First>{};struct SecondSource:SourcePrefix,RBX::Notifier<SecondSource,Second>{};
struct Provider{FirstSource*first();SecondSource*second();};
struct OwnerPrefix{virtual ~OwnerPrefix();char prefix[0x140];};
struct Chat:OwnerPrefix,RBX::Listener<SecondSource,Second>,RBX::Listener<FirstSource,First>{FirstSource*firstSource;SecondSource*secondSource;void update(const void*,Provider*);};
void Chat::update(const void*,Provider*provider){RBX::Notifier<FirstSource,First>::disconnect(firstSource,this);RBX::Notifier<SecondSource,Second>::disconnect(secondSource,this);firstSource=provider?provider->first():0;secondSource=provider?provider->second():0;RBX::Notifier<FirstSource,First>::connect(firstSource,this);RBX::Notifier<SecondSource,Second>::connect(secondSource,this);}
