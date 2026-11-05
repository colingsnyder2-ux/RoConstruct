// from server: 100% by coldek
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_codex_lookup_2b694745c76e1751.cpp

// Candidate translation unit (score above; library headers required).
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
#include <boost/shared_ptr.hpp>
using boost::shared_ptr;
namespace RBX {
class Instance {
public:
    virtual ~Instance();
};
class ModelInstance : public Instance {};
namespace Network {
class Player : public Instance {
public:
    char pad[0x170 - 4];
    ModelInstance* character;
    ModelInstance* getCharacter() const { return character; }
};

class Players {
public:
    __declspec(noalias) shared_ptr<const std::vector<shared_ptr<Instance> > > getPlayers();
    shared_ptr<Instance> playerFromCharacter(shared_ptr<Instance> character);
};

shared_ptr<Instance> Players::playerFromCharacter(shared_ptr<Instance> character)
{
    shared_ptr<const std::vector<shared_ptr<Instance> > > myPlayers = getPlayers();

    const std::vector<shared_ptr<Instance> >* v = myPlayers.get();
    std::vector<shared_ptr<Instance> >::const_iterator iter = v->begin();
    std::vector<shared_ptr<Instance> >::const_iterator end = v->end();

    for (; iter != end; iter++)
    {
        if (static_cast<Player*>(iter->get())->getCharacter() == static_cast<ModelInstance*>(character.get()))
            return *iter;
    }

    return shared_ptr<Instance>();
}
}
}
