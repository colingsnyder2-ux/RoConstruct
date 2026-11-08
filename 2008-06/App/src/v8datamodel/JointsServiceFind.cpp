// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/nullable-class-name
// >>> native-status (generated) -- do not edit >>>
// JointsServiceFind | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 52cff009 | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8datamodel/JointsService.h"
namespace RBX {
template<class Class> size_t ServiceProvider::doGetClassIndex() {
    static size_t index = newIndex();
    return index;
}
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}
template<class Derived, const char* ClassName>
const Name* NonFactoryProduct<Derived, ClassName>::className() {
    return ClassName ? &Name::declare<ClassName>() : NULL;
}

template<> JointsService* ServiceProvider::find<JointsService>() const {
    size_t index = getClassIndex<JointsService>();
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
    } else {
        JointsService* service = static_cast<JointsService*>(serviceArray[index].get());
        if (service) return service;
    }
    const Name* name = JointsService::className();
    if (!name) return NULL;
    boost::shared_ptr<Instance> item = findServiceByClassName(*name);
    if (!item) return NULL;
    serviceArray[index] = item;
    return static_cast<JointsService*>(item.get());
}
}
