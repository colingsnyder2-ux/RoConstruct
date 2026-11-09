// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_a3cda7efa8cef2ca.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    char pad[0x12c];
    void setParent(Instance* p);
};
class RunService;
class Heartbeat;
template<class N, class E> class Listener {
public:
    virtual void onEvent(const N*, E);
};
template<class N, class E> class Notifier {
public:
    void addListener(Listener<N, E>* l) const;
    void removeListener(Listener<N, E>* l) const;
};
class RunService : public Instance, public Notifier<RunService, Heartbeat> { };
class ServiceProvider {
public:
    RunService* findRunService() const;
    Instance* createStats() const;
};
namespace Soundscape {
class SoundService;
}
}
class SoundServiceStatsItem : public RBX::Instance { };
namespace RBX {
boost::shared_ptr<SoundServiceStatsItem> createStatsItem(const Soundscape::SoundService* s);
namespace Soundscape {
class SoundService : public Instance, public Listener<RunService, Heartbeat>
{
public:
    char pad2[0x168 - 0x134];
    boost::shared_ptr<Instance> statsItem;
    void openFmod();
    void closeFmod();
    void loadStockSounds();
    virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider);
};
void SoundService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
    Listener<RunService, Heartbeat>* listener = this;
    if (oldProvider) {
        if (RunService* rs = oldProvider->findRunService())
            rs->removeListener(listener);
    }
    if (statsItem) {
        statsItem->setParent(NULL);
        statsItem.reset();
    }
    if (oldProvider)
        closeFmod();
    Listener<RunService, Heartbeat>& listenerRef = *this;
    if (newProvider) {
        if (RunService* rs = newProvider->findRunService())
            rs->addListener(&listenerRef);
        openFmod();
        loadStockSounds();
        if (Instance* stats = newProvider->createStats()) {
            statsItem = createStatsItem(this);
            statsItem->setParent(stats);
        }
    }
}
}
}
