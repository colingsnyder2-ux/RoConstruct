// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    template<class Y> explicit shared_ptr(Y* p);
    ~shared_ptr();
    T* px; void* pn;
};
}
class Obj {
public:
    Obj();
    char pad[0x2c];
    static boost::shared_ptr<Obj> create();
};
boost::shared_ptr<Obj> Obj::create() { return boost::shared_ptr<Obj>(new Obj()); }
