// Implementation: C:\Users\colin\RoConstruct\tools\openrbx\Client\roc_espeon_channelmap_b1415270b48907a5.cpp
// Build pointer preserved: C:\Users\colin\RoConstruct\src\2008-06\005bb5f0.cpp
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
