// from server: 100% by EspClaude
// roc 2007-08 005e6130  unit: RBX::Flag  size: 36 bytes
// Flag::canBePickedUpByPlayer (rbxgs v8datamodel/Flag.cpp body); offsets from the target.
class BrickColor {
public:
    int number;
    bool operator!=(const BrickColor& o) const { return number != o.number; }
};
class Player {
public:
    char pad[0x120];
    BrickColor teamColor;   // +0x120
    bool neutral;           // +0x124
    bool getNeutral() const { return neutral; }
    BrickColor getTeamColor() const { return teamColor; }
};
class Flag {
public:
    char pad[0x240];
    BrickColor teamColor;   // +0x240
    bool canBePickedUpByPlayer(Player* p) const;
};

bool Flag::canBePickedUpByPlayer(Player* p) const
{
    if (p->getNeutral() != false)
        return false;
    BrickColor current = teamColor;
    if (p->getTeamColor() != current)
        return true;
    return false;
}
