// from server: 93% by EspClaude
// from server: 100% by tester
// roc 2008-06 004974c0  unit: RBX::Network::Players  size: 33 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004974c0
//
// 004974c0  51                   push ecx
// 004974c1  56                   push esi
// 004974c2  8b74240c             mov esi, dword ptr [esp + 0xc]
// 004974c6  56                   push esi
// 004974c7  81c198010000         add ecx, 0x198
// 004974cd  c744240800000000     mov dword ptr [esp + 8], 0
// 004974d5  e8d6a0ffff           call 0x4915b0
// 004974da  8bc6                 mov eax, esi
// 004974dc  5e                   pop esi
// 004974dd  59                   pop ecx
// 004974de  c20400               ret 4

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
