// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_docstopnative499ae39ea92aba6c.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <memory>
struct Resource{~Resource();};
struct Workspace{char prefix[0x1b4];int active;void setActive(int);};
struct Service{void stop();};
struct Model{char prefix[0x204];Service*service;Workspace*workspace();void reset();};
struct Holder{boost::shared_ptr<Model>get();};
struct Guard{char storage[12];Guard(boost::shared_ptr<const Model>);~Guard();};
extern void detach(Resource*,Model*);
inline Workspace*workspaceOf(const boost::shared_ptr<Model>&m){return m?m->workspace():0;}
struct Doc{char prefix[0x74];std::auto_ptr<Resource>resource;char gap[0x1c];Holder*holder;boost::shared_ptr<Model>getModel();void stop();};
void Doc::stop(){Guard guard(holder->get());if(getModel()->workspace()->active!=0){workspaceOf(getModel())->setActive(0);getModel()->reset();detach(resource.get(),getModel().get());getModel()->service->stop();resource.reset();}}
