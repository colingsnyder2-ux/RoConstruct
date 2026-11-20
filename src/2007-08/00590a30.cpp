// from server: 100% by Intel_Inside
// from server: 100% by Intel
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD

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
    static void* operator new(size_t size) { return malloc(size); }
};

class Instance : public Creatable<Instance>
{
public:
    virtual ~Instance();
};
class Seat : public Instance
{
    char data[0x2dc - 4];
public:
    Seat(bool b = true);
};
}
template boost::shared_ptr<RBX::Seat> RBX::Creatable<RBX::Instance>::create<RBX::Seat>();