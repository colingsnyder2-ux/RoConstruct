// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_timerconnecthelperse895747c7f8674d2.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
struct Listener {virtual ~Listener();};struct Prefix {virtual ~Prefix();char padding[0x12c];};
struct Notifier {void remove(Listener*);void add(Listener*);};
struct Run {char prefix[0x130];Notifier notifier;};
struct Provider {Run* create();};extern boost::shared_ptr<Run> sharedRun(Run*);
struct Timer:Prefix,Listener {boost::shared_ptr<Run> run;void update(const Provider*,Provider*);};
inline void disconnect(const boost::shared_ptr<Run>& r,Listener* l){if(r)r->notifier.remove(l);}
inline void connect(const boost::shared_ptr<Run>& r,Listener* l){if(r)r->notifier.add(l);}
void Timer::update(const Provider*,Provider* provider){disconnect(run,this);run=sharedRun(provider?provider->create():0);connect(run,this);}
