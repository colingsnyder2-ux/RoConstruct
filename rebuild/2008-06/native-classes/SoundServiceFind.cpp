// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// >>> native-status (generated) -- do not edit >>>
// SoundServiceFind | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 2913d5d3 | roc native-status --write
#include <boost/thread/once.hpp>
#include "../native-headers/v8datamodel/Selection.h"
#include "util/Sound.h"

// SoundService lookup uses the original out-of-line shared_ptr destructor.
namespace RBX {
template<class Class, class Derived, const char* Name>
const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}
template<class Class> Class* ServiceProvider::find() const {
    size_t index = getClassIndex<Class>();
    Class* service;
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
        service = NULL;
    } else {
        service = static_cast<Class*>(serviceArray[index].get());
        if (service != NULL) return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
    if (!item) return NULL;
    service = static_cast<Class*>(item.get());
    serviceArray[index] = item;
    return service;
}
template Soundscape::SoundService* ServiceProvider::find<Soundscape::SoundService>() const;
}
