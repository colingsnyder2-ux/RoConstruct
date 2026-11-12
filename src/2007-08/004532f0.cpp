// from server: 100% by EspClaude
// from server: 79% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-lib: rbxgs-dll roc_claude_49d23df30c89dda5.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <memory>
struct Owner{~Owner();};
struct State{char prefix[0x14c];int active;char gap[0x1ac-0x150];bool flag;void fire(int);void request(int v){if(!flag)fire(v);}};
struct Model{State*state();void setOwner(Owner*);};
struct Source{boost::shared_ptr<Model>get();};
struct Guard{int storage[3];Guard(boost::shared_ptr<const Model>);~Guard();};
extern Owner*createOwner();
inline State*stateOf(const boost::shared_ptr<Model>&m){return m?m->state():0;}
struct Doc{char prefix[0x60];std::auto_ptr<Owner>owner;char gap[0x14];Source*source;boost::shared_ptr<Model>get();void run();};
void Doc::run(){Guard guard(source->get());if(get()->state()->active==0){owner.reset(createOwner());get()->setOwner(owner.get());}stateOf(get())->request(1);}
