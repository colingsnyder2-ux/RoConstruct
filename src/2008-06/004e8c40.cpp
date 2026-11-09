// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_meshdecalmapkeyaddress8d3240c7fb86947c.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
struct Mesh:G3D::ReferenceCountedObject{};
struct Key {G3D::Vector3 size;int face;bool operator<(const Key&b)const{if(face<b.face)return true;if(face>b.face)return false;return &size.x < &b.size.x;}};
typedef std::map<Key,G3D::ReferenceCountedPointer<Mesh> > Map;
struct Cache:Map {std::pair<iterator,bool> add(const value_type&v);};
std::pair<Map::iterator,bool> Cache::add(const value_type&v){return insert(v);}
