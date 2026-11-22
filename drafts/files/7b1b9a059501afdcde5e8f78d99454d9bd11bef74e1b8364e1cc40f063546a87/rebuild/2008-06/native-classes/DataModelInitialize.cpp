#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
namespace RBX { typedef DescendantAdded DescendentAdded; typedef DescendantRemoving DescendentRemoving; }
#include "v8datamodel/LocalBackpack.h"
#include "v8datamodel/Hopper.h"
#include "v8datamodel/JointsService.h"
#include "gui/Gui.h"
#include "util/RunStateOwner.h"
#include "util/Sound.h"
#include <boost/thread/once.hpp>

namespace RBX {
class PhysicsService;
template<> PhysicsService* ServiceProvider::create<PhysicsService>() const;

// v8tree/Service.h declares ServiceProvider::create<C>() const / find<C>() const / getClassIndex<C>() without bodies;
// these are the template definitions AppUnit578_2008Creators.cpp uses (create<LocalBackpack> 00578930). The
// explicit instantiation below gives this unit its own create<StarterPackService>() const body: 004b3960 (228 B,
// calls find<StarterPackService>() const 00490d70 first, then Creatable<Instance>::create<StarterPackService>
// 0048ea00), called by initializeContents at 0057aaa0. Still uncredited there: the shared reference binding
// (ogre-reference-bindings-loop8.json) maps this symbol to 00490d70, which is find<StarterPackService>() const.
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex()
{
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}

template<class Class> Class* ServiceProvider::find() const
{
    size_t index = getClassIndex<Class>();
    Class* service;
    if (index + 1 > serviceArray.size())
    {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
        service = NULL;
    }
    else
    {
        service = static_cast<Class*>(serviceArray[index].get());
        if (service != NULL)
            return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
    if (!item)
        return NULL;
    service = static_cast<Class*>(item.get());
    serviceArray[index] = item;
    return service;
}

template<class Class> Class* ServiceProvider::create() const
{
    Class* service = find<Class>();
    if (service == NULL)
    {
        boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
        service = value.get();
        size_t index = getClassIndex<Class>();
        serviceArray[index] = value;
        service->setParent(const_cast<ServiceProvider*>(this));
    }
    return service;
}

template StarterPackService* ServiceProvider::create<StarterPackService>() const;   // 004b3960

// 0057a9f0
void DataModel::initializeContents(bool start) {
    workspace->setParent(this);
    guiRoot->setParent(this);
    guiHooks->setParent(this);
    localBackpack = shared_from(ServiceProvider::create<LocalBackpack>());
    starterPackService = shared_from(ServiceProvider::create<StarterPackService>());
    runService = shared_from(ServiceProvider::create<RunService>());
    ServiceProvider::create<Soundscape::SoundService>();
    workspace->setDefaultMouseCommand();   // 005a2730 (openrbx DataModel::initializeContents; call 0057ab79)
    workspace->setVerbParent(this);
    if (start) runService->start();
    Notifier<RunService, RunTransition>::connect(runService, this);
    ServiceProvider::create<JointsService>();
    ServiceProvider::create<PhysicsService>();
}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::LocalBackpack>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::RunService,RBX::RunTransition> *,std::allocator<RBX::Listener<RBX::RunService,RBX::RunTransition> *> >;
