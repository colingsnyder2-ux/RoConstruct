// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claudeL_a2880d8441105149.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/function.h", "roc_espeon_machineheader2f6c7dcf10adead1.cpp")
#pragma include_alias("reflection/signal.h", "roc_espeon_machineheader16e657153fe9fb6e.cpp")
#pragma include_alias("reflection/type.h", "roc_espeon_machineheader4aaa2bdeb1c2b6c3.cpp")
#pragma include_alias("reflection/reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/Reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/enumconverter.h", "roc_espeon_machineheader297ae1c3351d4ab6.cpp")
#pragma include_alias("reflection/object.h", "roc_espeon_machineheadercadaaebe20af2047.cpp")
#pragma include_alias("reflection/member.h", "roc_espeon_machineheader459d66d9acfae4ab.cpp")
#pragma include_alias("reflection/descriptor.h", "roc_espeon_machineheader0acd23dba6f04ff5.cpp")
#pragma include_alias("reflection/property.h", "roc_espeon_machineheadercfb6c68c9dd60df6.cpp")
#pragma include_alias(<v8tree/Verb.h>, <roc_espeon_insertnativeheader1a746c4cc8c6ae06.cpp>)
#pragma include_alias("v8tree/Verb.h", "roc_espeon_insertnativeheader1a746c4cc8c6ae06.cpp")
#pragma include_alias(<util/Name.h>, <roc_espeon_insertnativeheader115b7bccd0a9061e.cpp>)
#pragma include_alias("util/Name.h", "roc_espeon_insertnativeheader115b7bccd0a9061e.cpp")
#pragma include_alias(<util/Debug.h>, <roc_espeon_insertnativeheader5fe96130a83d2e88.cpp>)
#pragma include_alias("util/Debug.h", "roc_espeon_insertnativeheader5fe96130a83d2e88.cpp")
#pragma include_alias("v8tree/Instance.h", "roc_espeon_nativeinstanceguidportablea1682bda32c99cd2.cpp")
#include "v8tree/Verb.h"
#include "v8xml/SerializerV2.h"
#include <boost/bind.hpp>
#include <memory>
#include <stdexcept>
namespace RBX {
typedef std::vector<boost::shared_ptr<Instance> > DuplicateInstances;
bool permissionA(Instance*,int);bool permissionB(Instance*,int);
static __declspec(noinline) void checkPermissions(Instance* instance) {
 if(permissionA(instance,1)&&!permissionB(instance,1)) {
  std::string message("Insufficinet permissions");throw std::runtime_error(message);
 }
}
template<class T>T& at(void* p,unsigned n){return *reinterpret_cast<T*>(reinterpret_cast<char*>(p)+n);}
class DuplicateSelectionView {public:
 DuplicateInstances::const_iterator begin()const{return (*reinterpret_cast<DuplicateInstances* const*>(reinterpret_cast<const char*>(this)+0x154))->begin();}
 DuplicateInstances::const_iterator end()const{return (*reinterpret_cast<DuplicateInstances* const*>(reinterpret_cast<const char*>(this)+0x154))->end();}
 void replace(DuplicateInstances::iterator,DuplicateInstances::iterator);
};
class DuplicateSelectionClient {public:DuplicateSelectionView* get(bool);};
class DuplicateRecorder {public:void mark(int);};
class DuplicateOwner {public:DuplicateSelectionView* ensureSelection();DuplicateRecorder* recorder();};
class DuplicateInsertion {public:void insert(XmlElement*,DuplicateInstances*,int,int);};
void writeInstance(XmlElement*,boost::shared_ptr<Instance>);
void markInsertAction(const char*,DuplicateOwner*);
// Borrowed IDataState primary interface observed at582d1e: setDirty slot0.
class DuplicateDirtyView {public:virtual void setDirty(bool)=0;};
class DuplicateRecovery:public Verb {public:virtual void doIt(IDataState*);};
void DuplicateRecovery::doIt(IDataState* state) {
 checkPermissions(reinterpret_cast<Instance*>(at<DuplicateOwner*>(this,0x20)));
 std::auto_ptr<XmlElement> root(SerializerV2::newRootElement());
 if(at<DuplicateOwner*>(this,0x20))at<DuplicateOwner*>(this,0x20)->ensureSelection();
 DuplicateSelectionClient& selection=at<DuplicateSelectionClient>(this,0x14);
 std::for_each(selection.get(true)->begin(),selection.get(true)->end(),boost::bind(writeInstance,root.get(),_1));
 SerializerV2::isolateHandles(root.get());
 DuplicateInstances result;
 DuplicateInsertion* insertion=at<DuplicateInsertion*>(this,0xc);
 insertion->insert(root.get(),&result,2,0);
 DuplicateInstances::iterator last=result.end(); DuplicateInstances::iterator first=result.begin(); DuplicateSelectionView* view=selection.get(true); view->replace(first,last);
 (at<DuplicateOwner*>(this,0x20)?at<DuplicateOwner*>(this,0x20)->recorder():0)->mark(8);
 markInsertAction(getName().c_str(),at<DuplicateOwner*>(this,0x20));
 reinterpret_cast<DuplicateDirtyView*>(state)->setDirty(true);
}
}
