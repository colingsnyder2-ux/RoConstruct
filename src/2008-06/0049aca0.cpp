// from server: 100% by tester
namespace RBX {
class Instance;
class ModelInstance;

namespace Network {
class Player
{
    char gap0[0x170];
    ModelInstance* character;
public:
    ModelInstance* getCharacter() const { return character; }
};

class Players
{
    char gap0[0x1a0];
    Player* localPlayer;
public:
    static Players* findPlayers(const Instance* context);
    static ModelInstance* findLocalCharacter(const Instance* context);
};

ModelInstance* Players::findLocalCharacter(const Instance* context)
{
    if (Players* players = findPlayers(context))
        if (Player* player = players->localPlayer)
            return player->getCharacter();
    return 0;
}
}
}
