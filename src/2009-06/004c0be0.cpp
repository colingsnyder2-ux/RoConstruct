// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_8c6c212b05769eea.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
#include <boost/signals/connection.hpp>
namespace rbx { namespace signals {
template<class Sig> class signal;
template<class A> class signal<void(A)> {
	void* impl;
public:
	void operator()(A a);
};
} }
namespace RBX {
class Instance {
public:
    virtual ~Instance();
    void setParent(Instance* instance);
};
class ModelInstance : public Instance {};
template<class T> boost::shared_ptr<T> shared_from(T* r);
namespace Reflection { class PropertyDescriptor; }
namespace Network {
class PlayerHead : public Instance { char pad[0x88]; };
extern const Reflection::PropertyDescriptor prop_Character;
class Players {
public:
    static bool backendProcessing(const Instance* context, bool testInDatamodel);
    static bool frontendProcessing(const Instance* context, bool testInDatamodel);
};
class Player : public PlayerHead {
public:
    boost::shared_ptr<ModelInstance> character;
    char pad2[0xa0 - 0x94];
    boost::signals::connection characterDiedConnection;
    char pad3[0xd4 - 0xa0 - sizeof(boost::signals::connection)];
    rbx::signals::signal<void(boost::shared_ptr<ModelInstance>)> characterAddedSignal;
    rbx::signals::signal<void(boost::shared_ptr<ModelInstance>)> characterRemovingSignal;
    void setCharacter(ModelInstance* value);
    void onCharacterChangedBackend();
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
            characterRemovingSignal(character);
            if (Players::backendProcessing(this, false))
                character->setParent(NULL);
            character.reset();
        }
        if (value)
        {
            character = shared_from(value);
            if (Players::backendProcessing(this, false))
                onCharacterChangedBackend();
            characterAddedSignal(character);
            if (Players::frontendProcessing(this, false))
                onCharacterChangedFrontend();
        }
        raisePropertyChanged(prop_Character);
    }
}
}
}
