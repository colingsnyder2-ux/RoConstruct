// from server: 100% by tester
// roc-cl: 50727
namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
    const char* name;
};
}

class BrickColor
{
public:
    int number;
};

namespace Network {
class Player
{
    char gap0[0x1b4];
    BrickColor teamColor;
public:
    static Reflection::PropertyDescriptor prop_teamColor;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor);
    void setTeamColor(BrickColor value);
};

void Player::setTeamColor(BrickColor value)
{
    if (value.number != teamColor.number) {
        teamColor = value;
        raisePropertyChanged(prop_teamColor);
    }
}
}
}
