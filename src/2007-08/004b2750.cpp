// from server: 100% by EspClaude
// from server: 80% by EspClaude
// roc 2007-08 004b2750  RBX::Creatable<Instance>::create<Stats::TypedStatsItem<bool>, P1>(P1) (util/Object.h)
// roc-flags: /O2 /GS /EHsc /MD
#include <stdlib.h>
namespace boost {
template<class T> class shared_ptr {
    T* px;
    void* pn;
public:
    template<class Y, class D> shared_ptr(Y* p, D d);
    ~shared_ptr();
};
}
namespace RBX {
class Object { public: virtual ~Object() {} };
template<typename T>
class Creatable : public Object
{
protected:
    class Deleter
    {
    public:
        void operator()(T* obj)
        {
            T::predelete(obj);
            delete obj;
        }
    };
    Creatable() {}
    virtual ~Creatable() {}
public:
    template<typename Class, typename Parameter1>
    static boost::shared_ptr<Class> create(Parameter1 p1)
    {
        return boost::shared_ptr<Class>(new Class(p1), Deleter());
    }
private:
    static void* operator new(size_t size) { return malloc(size); }
    static void operator delete(void* ptr) { free(ptr); }
};
class Instance : public Creatable<Instance> {
public:
    static void predelete(Instance*);
};
namespace Stats {
template<class V> class TypedStatsItem : public Instance {
public:
    TypedStatsItem(const char* name);
    char pad[0x11c];
};
}
template boost::shared_ptr<Stats::TypedStatsItem<bool> > Creatable<Instance>::create<Stats::TypedStatsItem<bool>, const char*>(const char*);
}
