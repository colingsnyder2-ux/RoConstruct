// from server: 100% by colin
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
    char gap0[0x3e8];
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
