// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <stdlib.h>
namespace boost {
template<class T>
class shared_ptr
{
    T* px;
    void* pn;
public:
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
namespace G3D { class RenderDevice; }
namespace RBX {
template<class T>
class Creatable
{
public:
    class Deleter
    {
    public:
        void operator()(T* instance);
    };
    template<class U, class A1>
    static boost::shared_ptr<U> create(A1 a1)
    {
        return boost::shared_ptr<U>(new U(a1), Deleter());
    }
protected:
    static void* operator new(size_t size) { return ::operator new(size); }
};
class A0 { public: virtual void a0(); char pad[0x10]; };
class A1 { public: virtual void a1(); };
class A2 { public: virtual ~A2(); void* d; };
class A3 { public: virtual void a3(); char pad[8]; };
class Instance : public Creatable<Instance>, public A0, public A1, public A2, public A3 {
public:
    virtual ~Instance();
    char ipad[0x8c - 0x2c];
};
namespace Stats {
class Item : public Instance {
public:
    Item();
    double value;
    char spad[0xd0 - 0x98];
};
}
}
class CRobloxWnd {
public:
    class RenderStatsItem : public RBX::Stats::Item {
        G3D::RenderDevice* rd;
    public:
        RenderStatsItem(G3D::RenderDevice* rd) : rd(rd) {}
        virtual void a0();
    };
};
template boost::shared_ptr<CRobloxWnd::RenderStatsItem> RBX::Creatable<RBX::Instance>::create<CRobloxWnd::RenderStatsItem, G3D::RenderDevice*>(G3D::RenderDevice*);
