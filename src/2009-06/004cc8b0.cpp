// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 0049aca0  unit: RBX::Network::VPlayers::?$SignalDesc  size: 37 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049aca0
//
// 0049aca0  8b442404             mov eax, dword ptr [esp + 4]
// 0049aca4  50                   push eax
// 0049aca5  e8a670ffff           call 0x491d50
// 0049acaa  83c404               add esp, 4
// 0049acad  85c0                 test eax, eax
// 0049acaf  7411                 je 0x49acc2
// 0049acb1  8b80a0010000         mov eax, dword ptr [eax + 0xdc]
// 0049acb7  85c0                 test eax, eax
// 0049acb9  7407                 je 0x49acc2
// 0049acbb  8b8070010000         mov eax, dword ptr [eax + 0x8c]
// 0049acc1  c3                   ret 
// 0049acc2  33c0                 xor eax, eax
// 0049acc4  c3                   ret 

namespace RBX {
class Instance;
class ModelInstance;

namespace Network {
class Player
{
    char gap0[0x8c];
    ModelInstance* character;
public:
    ModelInstance* getCharacter() const { return character; }
};

class Players
{
    char gap0[0xdc];
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
