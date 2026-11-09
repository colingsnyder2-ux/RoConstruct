// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_bc0a39e5770e439f.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    void setParent(Instance* instance);
};
class ModelInstance : public Instance {};
template<class T> boost::shared_ptr<T> shared_from(T* r);
namespace Reflection { class PropertyDescriptor; }
template<class Class, class Event> class Notifier {
    char pad[0x20];
public:
    __declspec(nothrow) void raise(Event event) const;
};
namespace Network {
struct CharacterAdded {
    const boost::shared_ptr<Instance> character;
    CharacterAdded(Instance* character) : character(shared_from(character)) {}
};
struct CharacterRemoving {
    const boost::shared_ptr<Instance> character;
    CharacterRemoving(Instance* character) : character(shared_from(character)) {}
};
class PlayerHead : public Instance { char pad[0x12c]; };
extern const Reflection::PropertyDescriptor prop_Character;
class Players {
public:
    static bool backendProcessing(const Instance* context, bool testInDatamodel);
    static bool frontendProcessing(const Instance* context, bool testInDatamodel);
};
class Player : public PlayerHead, public Notifier<Player, CharacterAdded>, public Notifier<Player, CharacterRemoving> {
public:
    boost::shared_ptr<ModelInstance> character;
    char pad2[8];
    boost::signals::connection characterDiedConnection;
    void setCharacter(ModelInstance* value);
    void onCharacterChangedFrontend();
    void raisePropertyChanged(const Reflection::PropertyDescriptor& desc);
};
void Player::setCharacter(ModelInstance* value)
{
    if (value != character.get())
    {
        if (character.get())
        {
            characterDiedConnection.disconnect();
            Notifier<Player, CharacterRemoving>::raise(character.get());
            if (Players::backendProcessing(this, false))
                character->setParent(NULL);
            character.reset();
        }
        if (value)
        {
            character = shared_from(value);
            Notifier<Player, CharacterAdded>::raise(character.get());
            if (Players::frontendProcessing(this, false))
                onCharacterChangedFrontend();
        }
        raisePropertyChanged(prop_Character);
    }
}
}
}
