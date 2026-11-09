// from server: 100% by colin
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

class IModelModifier { public: virtual ~IModelModifier(); };

class ModelInstance : public Instance, public virtual IModelModifier
{
    char data[0x22c - 12];
public:
    ModelInstance();
};

template boost::shared_ptr<ModelInstance> Creatable<Instance>::create<ModelInstance>();
}
