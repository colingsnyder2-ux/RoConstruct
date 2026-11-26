// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
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
class VBase { public: int v; };
class Accoutrement : public Instance, public virtual VBase {
public:
    Accoutrement();
    char pad[0x2d8 - 12];
};
template boost::shared_ptr<Accoutrement> Creatable<Instance>::create<Accoutrement>();
}
