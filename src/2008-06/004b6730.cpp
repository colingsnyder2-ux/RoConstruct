// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_unsignedkey_183192349d5022d7.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <map>
struct Object { unsigned char storage[0x2a24]; Object(); };
typedef boost::shared_ptr<Object> Shared;
typedef std::map<unsigned int,Shared> Map;
struct S { unsigned char padding[0x2b90]; Map objects; Object* get(int); };
Object* S::get(int key) {
 int savedKey=key;
 key=savedKey;
 Map::iterator position=objects.find(key);
 if(position==objects.end()) {
  Shared value(new Object);
  key=savedKey;
  objects[key]=value;
  return value.get();
 }
 return position->second.get();
}
