// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

extern "C" long __cdecl _InterlockedDecrement(long volatile*);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
#pragma intrinsic(_InterlockedDecrement, _InterlockedIncrement)
struct Cnt {
    virtual ~Cnt(); virtual void dispose(); virtual void destroy();
    long use; long weak;
    void weak_add_ref() { _InterlockedIncrement(&weak); }
    void weak_release() { if (_InterlockedDecrement(&weak) == 0) destroy(); }
    void release() { if (_InterlockedDecrement(&use) == 0) { dispose(); weak_release(); } }
};
template <class T> struct SP {
    T* px; Cnt* pn;
    ~SP() { if (pn) pn->release(); }
};
template <class T> struct WP {
    T* px; Cnt* pn;
    WP(const SP<T>& r) : px(r.px), pn(r.pn) { if (pn) pn->weak_add_ref(); }
    ~WP();
};
namespace RBX {
class PartInstance;
struct World { char pad[0xa4]; void* contactManager; };
struct RootInstance { char pad[0x170]; World* world; };
SP<PartInstance> shared_from(PartInstance* p);
struct Vec { void* a; void* b; void* c; void* d; Vec(const Vec&); ~Vec(); };
class MegaDragger {
public:
    WP<PartInstance> mousePart;
    Vec parts;
    bool flag;
    void* extra;
    RootInstance* root;
    void* cm;
    MegaDragger(PartInstance* part, const Vec& parts, RootInstance* root, void* extra);
};
MegaDragger::MegaDragger(PartInstance* part, const Vec& p, RootInstance* r, void* e)
    : mousePart(shared_from(part)), parts(p), flag(true), extra(e), root(r),
      cm(r->world->contactManager)
{
}
}
