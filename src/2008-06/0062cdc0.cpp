// from server: 100% by tester
namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
    const char* name;
};
}

class BrickColor
{
    int number;
public:
    ~BrickColor() {}
};

class FlagStand
{
    char gap0[0x3fc];
    BrickColor teamColor;
public:
    static Reflection::PropertyDescriptor prop_TeamColor;
    void raisePropertyChanged(const Reflection::PropertyDescriptor& descriptor);
    void setTeamColor(BrickColor value);
};

void FlagStand::setTeamColor(BrickColor value)
{
    teamColor = value;
    raisePropertyChanged(prop_TeamColor);
}
}
