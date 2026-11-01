// from server: 100% by tester
#include <vector>

namespace boost {
template<class T>
class shared_ptr
{
    T* px;
    void* pn;
public:
    shared_ptr(const shared_ptr& r);
    ~shared_ptr();
};
}

namespace RBX {

template<class T>
class CopyOnWrite
{
    boost::shared_ptr<T> object;
public:
    boost::shared_ptr<const T> read() const;
};

class Instance
{
    char gap0[0x108];
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > children;
public:
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getChildren2();
};

boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Instance::getChildren2()
{
    return children.read();
}
}
