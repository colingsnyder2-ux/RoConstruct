// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
namespace RBX {
class Instance;
namespace Network {
class Player;
class Client { public: static bool clientIsPresent(const Instance* context, bool testInDatamodel); };
class Server { public: static bool serverIsPresent(const Instance* context, bool testInDatamodel); };
class Players { public: static Player* findLocalPlayer(const Instance* context); };
}
}

using namespace RBX;
using namespace RBX::Network;

// INFERRED: ABI is cdecl with one Instance* arg (arg read at [esp+0x10] after 3 pushes, plain ret)
extern "C" int fn_00574fe0(const Instance* context)
{
    bool client = Client::clientIsPresent(context, true);
    bool server = Server::serverIsPresent(context, true);
    bool hasPlayer = Players::findLocalPlayer(context) != 0;
    if (server)
        return 0;
    if (client)
        return hasPlayer ? 1 : 2;
    return hasPlayer ? 3 : 4;
}
