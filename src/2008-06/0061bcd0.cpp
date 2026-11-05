// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_modifypermissionstatica059225f026da09a.cpp

// Candidate translation unit (score above; library headers required).
namespace RBX {
class Instance {public: virtual ~Instance(); char reserved[0x100]; Instance* parent; Instance* getRootAncestor(); bool isAncestorOf(Instance*);};
namespace Stats {class StatsService:public Instance {};}
class DataModel:public Instance {public: char reserved2[0x114]; Instance* guiRoot; char gap[4]; Instance* guiHooks;};
}
struct Context {unsigned long identity;void report(int,const char*);};
extern "C" Context* __cdecl getContext();
extern bool __cdecl hasPermission(unsigned long,int);
static __declspec(noinline) void checkModification(RBX::Instance* instance) {
 if(hasPermission(getContext()->identity,1)) return;
 if(dynamic_cast<RBX::Stats::StatsService*>(instance)) getContext()->report(1,"modify a StatsService");
 RBX::Instance* root=instance->parent ? instance->parent->getRootAncestor() : instance;
 RBX::DataModel* model=dynamic_cast<RBX::DataModel*>(root);
 if(model){
 if(model->guiRoot==instance || model->guiRoot->isAncestorOf(instance)) getContext()->report(1,"GuiRoot");
 if(model->guiHooks==instance || model->guiHooks->isAncestorOf(instance)) getContext()->report(1,"GuiHooks");
 }
}
void verify(RBX::Instance* instance){checkModification(instance);}
