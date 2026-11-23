// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace RBX {
class Instance;
namespace Network {
class Player;
class Client {
public:
    static bool clientIsPresent(const Instance* context, bool);
};
class Server {
public:
    static bool serverIsPresent(const Instance* context, bool);
};
class Players {
public:
    static Player* findLocalPlayer(const Instance* context);
};
}
}

// INFERRED: return is a 0-4 network-mode code; the meaning of each value is not known from the binary.
extern "C" int fn_00574fe0(const RBX::Instance* instance)
{
    bool client = RBX::Network::Client::clientIsPresent(instance, true);
    bool server = RBX::Network::Server::serverIsPresent(instance, true);
    bool hasPlayer = RBX::Network::Players::findLocalPlayer(instance) != 0;

    if (server)
        return 0;
    if (client)
        return (hasPlayer ? 0 : 1) + 1;
    return (hasPlayer ? 0 : 1) + 3;
}
