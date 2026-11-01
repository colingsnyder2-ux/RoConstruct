// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
struct BrickColor { int number; };
namespace Reflection { class PropertyDescriptor; }
class Instance {
public:
    void raisePropertyChanged(const Reflection::PropertyDescriptor&);
};
namespace Network {
class Player : public Instance {
    char pad[0x94];
    BrickColor teamColor;
public:
    void setTeamColor(BrickColor value);
};
extern Reflection::PropertyDescriptor prop_teamColor;
void Player::setTeamColor(BrickColor value)
{
    if (value.number != teamColor.number) {
        teamColor = value;
        raisePropertyChanged(prop_teamColor);
    }
}
}
}
