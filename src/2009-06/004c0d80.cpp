// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
namespace Reflection { class PropertyDescriptor { public: int x; }; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor& d);
    char pad[0x98];
};
namespace Network {
class Player : public Instance {
public:
    bool neutral;
    static Reflection::PropertyDescriptor prop_neutral;
    void setNeutral(bool value);
};
void Player::setNeutral(bool value)
{
    if (value != neutral) {
        neutral = value;
        raisePropertyChanged(prop_neutral);
    }
}
}
}
