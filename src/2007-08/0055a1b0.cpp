// from server: 100% by Intel
// from server: 100% by EspClaude
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
class Camera : public Instance
{
    char data[0x224 - 4];
public:
    Camera(bool b = true);
};
namespace Network {
class Players : public Instance
{
    char data[0x1b0 - 4];
public:
    Players();
};
}
template boost::shared_ptr<Camera> Creatable<Instance>::create<Camera>();
}
