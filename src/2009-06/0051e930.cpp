// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace G3D {
class System {
public:
    static void* alignedMalloc(unsigned int bytes, unsigned int alignment);
    static void memset(void* dst, unsigned char value, unsigned int numBytes);
};
template<class Key, class Value> class Table {
    class Node;
    unsigned int _size;
    Node** bucket;
    unsigned int numBuckets;
public:
    Table() {
        numBuckets = 10;
        _size = 0;
        bucket = (Node**)System::alignedMalloc(sizeof(Node*) * numBuckets, 16);
        System::memset(bucket, 0, sizeof(Node*) * numBuckets);
    }
    virtual ~Table();
};
}
namespace RBX {
template<class T> struct Less { Less() {} };
template<class T> struct Alloc { Alloc() {} };
template<class T> struct SharedRef { T* px; void* pn; SharedRef() : px(0), pn(0) {} ~SharedRef(); };
template<class K, class V> class Tree {
public:
    Tree(const Less<K>& c, const Alloc<V>& a);
    ~Tree();
    char data[0x20];
};
template<class K, class V> class Map : public Tree<K, V> {
public:
    Map() : Tree<K, V>(Less<K>(), Alloc<V>()) {}
};
class RenderSurfaceTypes;
struct Variations;
struct KeyA; struct KeyB;
class MeshCache {
public:
    MeshCache();
    G3D::Table<RenderSurfaceTypes, G3D::Table<int, Variations> > table;
    void* a;
    void* b;
    SharedRef<KeyA> ref;
    std::map<KeyA*, int> mapA;
    std::map<KeyB*, int> mapB;
    int count;
};
typedef char check1[sizeof(std::map<int,int>) == 0x20 ? 1 : -1];
MeshCache::MeshCache() : a(0), b(0), count(0)
{
}
}
