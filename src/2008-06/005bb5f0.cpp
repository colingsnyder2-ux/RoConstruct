// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_channelmap_b1415270b48907a5.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <string>
#include <map>
#include <utility>
typedef std::pair<std::string,int> Key;
struct Channel { unsigned char data[48]; Channel(void*,Key,bool); };
typedef boost::shared_ptr<Channel> Shared;
typedef std::map<Key,Shared> Map;
struct S { unsigned char prefix[0x134]; void* owner; unsigned char middle[0x48]; Map first,second; Shared f(Key,bool); };
Shared S::f(Key key,bool flag) {
 Map* map=flag?&second:&first;
 Map::iterator it=map->find(key);
 if(it!=map->end()) return it->second;
 Shared result(new Channel(owner,key,flag));
 (*map)[key]=result;
 return result;
}
