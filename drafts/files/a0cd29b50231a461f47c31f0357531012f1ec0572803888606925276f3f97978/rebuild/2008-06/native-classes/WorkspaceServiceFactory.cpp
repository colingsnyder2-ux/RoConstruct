// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
#include <boost/thread/once.hpp>
#include "v8datamodel/Workspace.h"

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
const Name& NonFactoryProduct<Derived, ClassName>::className() { return Name::declare<ClassName>(); }

template<> Workspace* ServiceProvider::create<Workspace>() const {
    size_t index = getClassIndex<Workspace>();
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
    } else {
        Workspace* service = static_cast<Workspace*>(serviceArray[index].get());
        if (service) return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(Workspace::className());
    if (!item) return NULL;
    Workspace* service = static_cast<Workspace*>(item.get());
    serviceArray[index] = item;
    return service;
}
}
