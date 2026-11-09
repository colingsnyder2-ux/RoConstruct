// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px;
    void* pn;
    T* get() const { return px; }
    typedef T* shared_ptr::*unspecified_bool_type;
    operator unspecified_bool_type() const { return px == 0 ? 0 : &shared_ptr::px; }
    void reset();
};
}
namespace RBX {
struct Instance;
struct ChangeHistoryService { void requestWaypoint(int); };
extern bool __cdecl isLocked(Instance*);
extern int __cdecl getAnchored(Instance*);
extern void __cdecl setAnchored(Instance*, const bool*);
template<class T> T* __cdecl findService(Instance*);
struct AnchorTool {
    char padding[0x18];
    Instance* provider;
    boost::shared_ptr<Instance> object;
    AnchorTool* apply(int);
};
AnchorTool* AnchorTool::apply(int)
{
    if (object && !isLocked(object.get())) {
        bool enabled = getAnchored(object.get()) != 0;
        setAnchored(object.get(), &enabled);
        findService<ChangeHistoryService>(provider)->requestWaypoint(8);
        object.reset();
    }
    return this;
}
}
