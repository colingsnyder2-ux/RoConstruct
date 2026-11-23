// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native ServiceProvider::find / create for FilteredSelection<Instance> (inactive). 00617340 (174 B, registry
// placeholder func_00617340): the service-array lookup (call_once 00557330 with the index initializer 00616400 and its
// once_flag 0097bf00, doGetClassIndex 00616240 guarded by 0097bef8, serviceArray +0x190 (+0x19c / +0x1a0, 8-byte
// shared_ptr elements), resize 004124c0 when too short). Its only caller 006173f0 (create<FilteredSelection<Instance>>:
// Creatable<Instance>::create 00616ee0 allocating 0x154 and constructing the FilteredSelection<Instance> of vtable
// 00843b0c (RTTI .?AV?$FilteredSelection@VInstance@RBX@@@RBX@@), then Instance::setParent 0055a8f0). The template bodies
// are the unit-local definitions of native-classes/FilteredSelectionFactory.cpp (v8tree/Service.h only declares them),
// which instantiates the ModelInstance / PVInstance copies; no unit instantiated the Instance one.
// Batch 44: find (174 B), create (228 B), doGetClassIndex (91 B), getClassIndex (23 B) and Creatable::create (120 B) compile
// byte-identical (relocations masked) but stay uncredited: each has many relocation-masked twins and the references that
// tell them apart (the once_flag 0097bf00, the index guard 0097bef8, the placeholders 00616240 / 00616400, and 00616ee0,
// which the registry names create<Glue>) carry no registry names. Registry proposal in the batch 44 notes.
#include <boost/thread/once.hpp>
#include "v8datamodel/Selection.h"

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
template<class Class> Class* ServiceProvider::find() const {
    size_t index = getClassIndex<Class>();
    if (index + 1 > serviceArray.size()) serviceArray.resize(index + 1);
    else {
        Class* service = static_cast<Class*>(serviceArray[index].get());
        if (service) return service;
    }
    // These two original specializations have no class-name fallback.
    // The unreachable tail preserves their original exception-handling codegen.
    if (true) return NULL;
    boost::shared_ptr<Instance> item;
    if (!item) return NULL;
    serviceArray[index] = item;
    return static_cast<Class*>(item.get());
}
// 00617340 (registry placeholder func_00617340)
template FilteredSelection<Instance>* ServiceProvider::find<FilteredSelection<Instance> >() const;
template<class Class> Class* ServiceProvider::create() const {
    Class* service = find<Class>();
    if (!service) {
        boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
        service = value.get();
        size_t index = getClassIndex<Class>();
        serviceArray[index] = value;
        service->setParent(const_cast<ServiceProvider*>(this));
    }
    return service;
}
// 006173f0
template FilteredSelection<Instance>* ServiceProvider::create<FilteredSelection<Instance> >() const;
}
