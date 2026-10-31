// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    shared_ptr(const shared_ptr& o);
    ~shared_ptr();
};
}
namespace RBX {
class Instance;
template<class T> class CopyOnWrite {
public:
    boost::shared_ptr<const T> read() const;
    char data[0x10];
};
template<class T> class vec { T* a; T* b; T* c; };
class Selection {
public:
    virtual ~Selection();
    char pad[0x8c - 4];
    CopyOnWrite<vec<boost::shared_ptr<Instance> > > selection;
    boost::shared_ptr<const vec<boost::shared_ptr<Instance> > > getSelection2();
};
boost::shared_ptr<const vec<boost::shared_ptr<Instance> > > Selection::getSelection2()
{
    return selection.read();
}
}
