// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_deserializerefslot41acaf6a50338696.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/function.h", "roc_espeon_machineheader2f6c7dcf10adead1.cpp")
#pragma include_alias("reflection/signal.h", "roc_espeon_machineheader16e657153fe9fb6e.cpp")
#pragma include_alias("reflection/type.h", "roc_espeon_machineheader4aaa2bdeb1c2b6c3.cpp")
#pragma include_alias("reflection/reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/Reflection.h", "roc_espeon_machineheadera6fefc64bf3a6f9e.cpp")
#pragma include_alias("reflection/enumconverter.h", "roc_espeon_machineheader297ae1c3351d4ab6.cpp")
#pragma include_alias("util/Http.h", "roc_espeon_machineheader5b78b946a11cad23.cpp")
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
#define _CPPUNWIND 1
#include "v8tree/Instance.h"
#include <map>
#include <vector>
namespace RakNet {class BitStream;}
// Native Streaming.h WaitItem; target map is at +0x2b54.
struct WaitItem {const RBX::Reflection::RefPropertyDescriptor* desc; boost::shared_ptr<RBX::Instance> instance;};
bool resolveId(const RBX::Guid::Data&,RBX::Instance*&);
boost::shared_ptr<RBX::Instance> acquireInstance(RBX::Instance*);
// Borrowed descriptor view: target calls setter at vtable +0x34. Other slots unidentified.
struct RefSetterView {
virtual void slot0()=0;
virtual void slot1()=0;
virtual void slot2()=0;
virtual void slot3()=0;
virtual void slot4()=0;
virtual void slot5()=0;
virtual void slot6()=0;
virtual void slot7()=0;
virtual void slot8()=0;
virtual void slot9()=0;
virtual void slot10()=0;
virtual void slot11()=0;
virtual void slot12()=0;
virtual void setRefValue(RBX::Reflection::DescribedBase*,RBX::Reflection::DescribedBase*) const=0;
};
class IdSerializerRecovery {
public:
 void deserializeId(RakNet::BitStream&,RBX::Guid::Data&);
 void deserializeRef(RBX::Reflection::Property&,RakNet::BitStream&);
};
void IdSerializerRecovery::deserializeRef(RBX::Reflection::Property& property,RakNet::BitStream& stream) {
 RBX::Guid::Data id;
 deserializeId(stream,id);
 RBX::Instance* owner=static_cast<RBX::Instance*>(property.getInstance());
 if(owner) {
  const RBX::Reflection::RefPropertyDescriptor& desc=static_cast<const RBX::Reflection::RefPropertyDescriptor&>(property.getDescriptor());
  RBX::Instance* value;
  if(resolveId(id,value)) reinterpret_cast<const RefSetterView*>(&desc)->setRefValue(owner,value);
  else {
   WaitItem wi={&desc,acquireInstance(owner)};
   typedef std::map<RBX::Guid::Data,std::vector<WaitItem> > WaitMap;
   (*reinterpret_cast<WaitMap*>(reinterpret_cast<char*>(this)+0x2b54))[id].push_back(wi);
  }
 }
}
