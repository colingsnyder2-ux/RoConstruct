// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <set>
namespace G3D {
namespace System {
void* alignedMalloc(size_t bytes, size_t alignment);
void memset(void* dst, unsigned char value, size_t n);
}
template<class Key, class Value> class Table {
    struct Node;
    int _size;
    Node** bucket;
    int numBuckets;
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
struct RenderSurfaceTypes;
struct Variations;
struct E20 { int v[5]; };
bool operator<(const E20&, const E20&);
struct P8 { int v[2]; };
bool operator<(const P8&, const P8&);
struct Pair { int c; int d; Pair() : c(0), d(0) {} ~Pair(); };
struct Holder {
    G3D::Table<RenderSurfaceTypes, Variations> table;
    int a;
    int b;
    Pair cd;
    std::set<E20> s1;
    std::set<P8> s2;
    int e;
    Holder() : a(0), b(0), e(0) {}
    ~Holder();
};
Holder* make(void* p) { return new (p) Holder(); }
