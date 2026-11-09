// from server: 100% by colin
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_manual_meshcache_48239a58a7313120.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Table.h>
#include <G3D/Vector3.h>
#include <G3D/ReferenceCount.h>
struct Mesh:G3D::ReferenceCountedObject {char storage[28];};
struct Variations {G3D::ReferenceCountedPointer<Mesh> meshes[1];};
typedef G3D::Table<G3D::Vector3,Variations> Table;
struct SurfaceTypes {unsigned value;SurfaceTypes():value(0){}};
template<class K,class V> struct Entry {K key;V value;};
template<class K,class V> struct Node {unsigned hash;Entry<K,V> entry;Node* next;
Node(K k,V v,unsigned h,Node* n){this->entry.key=k;this->entry.value=v;this->hash=h;this->next=n;}};
template struct Node<SurfaceTypes,Table>;

