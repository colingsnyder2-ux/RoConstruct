// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
template<class T> class shared_ptr {
public:
    T* px; void* pn;
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
namespace RBX {
class Instance { public: virtual ~Instance(); };
template<class Base> class Creatable {
public:
    class Deleter { public: void operator()(Base* p); };
    template<class T> static boost::shared_ptr<T> create()
    {
        return boost::shared_ptr<T>(new T(), Deleter());
    }
};
class Script : public Instance {
public:
    Script();
    char pad[0x90 - 4];
};
template boost::shared_ptr<Script> Creatable<Instance>::create<Script>();
}
