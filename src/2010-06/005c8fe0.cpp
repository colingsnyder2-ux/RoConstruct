// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_descriptor_receiver_native_name_order_7d5f8e8ab29991a4.cpp

// Candidate translation unit (score above; library headers required).
#pragma include_alias("reflection/object.h", "../roc_descriptor_receiver_class_header_268a149c290eb686.cpp")
#undef _RELEASEASSERT
#include "reflection/object.h"
#include <boost/algorithm/string.hpp>
#include <boost/cstdint.hpp>

namespace RakNet { class BitStream; }
namespace RBX { namespace Network {
template<class T> class DescriptorReceiver {
 std::vector<const T*> idToDesc;
 int idBits;
 void learnName(std::string s, int i);
public:
 void getValue(unsigned int id, const T*& value) const { value = idToDesc.at(id); }
 void learn(RakNet::BitStream& stream, bool exchangeChecksum, bool useRakString);
 unsigned int receive(RakNet::BitStream& stream, const T*& value, bool versionCheck) const;
 bool verifyChecksum(const T* value, boost::uint32_t remoteChecksum);
};
using namespace Reflection;
template<> void DescriptorReceiver<PropertyDescriptor>::learnName(std::string s, int i) {
 std::vector<std::string> words;
 boost::split(words,s,boost::is_any_of(":"));
 const Name& n = Name::lookup(words[0]);
 ClassDescriptor::ClassDescriptors::const_iterator iter = ClassDescriptor::all_begin();
 while(iter != ClassDescriptor::all_end()) {
  const ClassDescriptor* c = *iter;
  if(c->name == n) {
   const Name& propertyName = Name::lookup(words[1]);
   PropertyContainer::CollectionType::const_iterator desc = c->PropertyContainer::findDescriptor(propertyName);
   if(desc != c->PropertyContainer::descriptors_end()) { idToDesc[i] = *desc; return; }
   else break;
  }
  ++iter;
 }
 idToDesc[i] = NULL;
}
} }
