// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_texturekeyinheritance7a12dfe6085e438a.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <G3D/Vector3.h>
#include <G3D/Vector2.h>
#include <G3D/ReferenceCount.h>
struct Mesh:G3D::ReferenceCountedObject{};
struct DecalKey {G3D::Vector3 size;int face;bool operator<(const DecalKey&b)const{if(face<b.face)return true;if(face>b.face)return false;return &size.x<&b.size.x;}};
struct Key:protected DecalKey {G3D::Vector2 tile;bool operator<(const Key&b)const{if(&tile.x<&b.tile.x)return true;if(&tile.x>&b.tile.x)return false;return DecalKey::operator<(b);}};
typedef std::map<Key,G3D::ReferenceCountedPointer<Mesh> > Map;
struct Cache:Map {std::pair<iterator,bool> add(const value_type&v);};
std::pair<Map::iterator,bool> Cache::add(const value_type&v){return insert(v);}
