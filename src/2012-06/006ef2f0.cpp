// from server: 100% by Xemicl
// copied from an identical function in another client (function ??$create@VBodyForce@RBX@@@?$Creatable@VInstance@RBX@@@RBX@@SA?AV?$shared_ptr@VBodyForce@RBX@@@boost@@XZ)

// from server: 94% by EspClaude

// from server: 100% by tester

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

    template<class U>
    static boost::shared_ptr<U> create()
    {
        return boost::shared_ptr<U>(new U(), Deleter());
    }

protected:
    static void* operator new(size_t size) { return ::operator new(size); }
};

class Instance : public Creatable<Instance>
{
public:
    virtual ~Instance();
};


class BodyForce : public Instance
{
    char data[0xc0 - 4];
public:
    BodyForce();
};

template boost::shared_ptr<BodyForce> Creatable<Instance>::create<BodyForce>();
}
