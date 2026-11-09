// from server: 84% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
#include <stddef.h>
namespace RBX {
class StatsOwner { public: int o; };
class PeerPad { public: char pad[0x100]; };
class Peer : public PeerPad, public StatsOwner {};
class StatsItem {
public:
    StatsItem(const char* name, int kind, bool flag, StatsOwner* owner);
    virtual ~StatsItem();
    char itemPad[0x1cc - 4];
};
class NetPeerStats : public StatsItem {
public:
    NetPeerStats(int id, Peer* peer);
    ~NetPeerStats();
    int pad1cc;
    int count;
    std::map<int, int> values;
    int id;
};
NetPeerStats::NetPeerStats(int id, Peer* peer)
    : StatsItem("Net Peer Stats", 8, false, peer), count(0), id(id)
{
}
}
