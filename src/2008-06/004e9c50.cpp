// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <map>
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

struct AtomicInt32 {
    volatile long _value;
    void increment() { InterlockedIncrement(&_value); }
    unsigned int decrement() { return InterlockedDecrement(&_value) != 0; }
};
struct ReferenceCountedObject {
    AtomicInt32 refCount;
    void* weak;
    void zeroWeakPointers();
    virtual ~ReferenceCountedObject() {}
};
struct Mesh : ReferenceCountedObject {};
template <class T>
class RCP {
    T* p;
    void zero() {
        if (p != 0) {
            if (p->refCount.decrement() == 0) {
                p->zeroWeakPointers();
                delete p;
            }
            p = 0;
        }
    }
    void set(T* x) {
        if (x != p) {
            zero();
            if (x != 0) {
                p = x;
                p->refCount.increment();
            }
        }
    }
public:
    RCP() : p(0) {}
    RCP(const RCP& o) : p(0) { set(o.p); }
    ~RCP() { zero(); }
    RCP& operator=(const RCP& o) { set(o.p); return *this; }
};

struct TextureKey {
    float x, y, z;
    int face;
    bool operator<(const TextureKey& o) const {
        if (face < o.face) return true;
        if (face > o.face) return false;
        return this < &o;
    }
};

typedef std::map<TextureKey, RCP<Mesh> > Cache;
template Cache::iterator Cache::_Mybase::insert(Cache::const_iterator, const Cache::value_type&);
