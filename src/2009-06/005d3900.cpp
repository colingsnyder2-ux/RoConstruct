// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <map>
namespace RBX { class Instance; }
namespace rbx { namespace signals {
class connection {
public:
    void* a;
    void* b;
    connection();
    connection(const connection&);
    ~connection();
    void disconnect();
};
} }
namespace RBX {
class Selection {
public:
    char pad[0xac];
    std::map<Instance*, rbx::signals::connection> connections;
    void onRemoved(Instance* i);
};
void Selection::onRemoved(Instance* i)
{
    std::map<Instance*, rbx::signals::connection>::iterator it = connections.find(i);
    it->second.disconnect();
    connections.erase(it);
}
}
