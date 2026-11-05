// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_docrunnative757a57a39a214dda.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <memory>
struct Owner{~Owner();};
struct State{char prefix[0x1b4];int active;void fire(int);};
struct Model{State*state();void setOwner(Owner*);};
struct Source{boost::shared_ptr<Model>get();};
struct Guard{char storage[12];Guard(boost::shared_ptr<const Model>);~Guard();};
extern Owner*createOwner();
inline State*stateOf(const boost::shared_ptr<Model>&m){return m?m->state():0;}
struct Doc{char prefix[0x74];std::auto_ptr<Owner>owner;char gap[0x1c];Source*source;boost::shared_ptr<Model>get();void run();};
void Doc::run(){Guard guard(source->get());if(get()->state()->active==0){owner.reset(createOwner());get()->setOwner(owner.get());}stateOf(get())->fire(1);}
