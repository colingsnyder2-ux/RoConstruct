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
class Instance;

template<class T>
class CopyOnWrite
{
    boost::shared_ptr<T> object;
public:
    boost::shared_ptr<const T> read() const;
};

namespace Network {
class Players
{
    char gap0[0x198];
    CopyOnWrite<std::vector<boost::shared_ptr<Instance> > > players;
public:
    boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > getPlayers();
};

boost::shared_ptr<const std::vector<boost::shared_ptr<Instance> > > Players::getPlayers()
{
    return players.read();
}
}
}
