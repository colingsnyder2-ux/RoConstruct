// from server: 100% by EspClaude
// roc 2009-06 00487ad0
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


class Thing : public Instance
{
    char data[0xf8 - 4];
public:
    Thing();
};

template boost::shared_ptr<Thing> Creatable<Instance>::create<Thing>();
}
