// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_ed0f59536c131bce.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <stdexcept>
#include <list>
#include <boost/shared_ptr.hpp>
typedef std::runtime_error RuntimeError;
struct StandardOut
{
    void print(int, const char*);
    void __cdecl printf(int, const char*, ...);
    static boost::shared_ptr<StandardOut> singleton();
};
struct Player
{
    char pad[0x54];
    std::string name;
    char pad2[0xc8 - 0x54 - sizeof(std::string)];
    int userId;
};
inline int idOf(Player* p) { if (p) return p->userId; return 0; }
struct AbuseReport
{
    int abuser;
    int reporter;
    std::string reason;
    struct Message { int userID; std::string text; };
    std::list<Message> messages;
    AbuseReport();
    ~AbuseReport();
};
struct BitStream { BitStream(); ~BitStream(); char data[0x414]; };
void __cdecl writeByte(BitStream*, int);
void __cdecl writeInt(BitStream*, int);
void __cdecl writeString(BitStream*, std::string*);
struct SystemAddress { unsigned int binaryAddress; unsigned short port; };
extern SystemAddress unassigned;
struct Peer
{
    void send(boost::shared_ptr<BitStream>, int, int, int, SystemAddress, int);
};
struct Slot { char data[0xc]; };
struct Signal
{
    void invoke(AbuseReport*, Slot*);
};
struct Pad
{
    char pad[0xa8];
    Signal* signal;
    char pad1[0x8];
};
struct Players : Pad
{
    Slot history;
    char pad2[0xdc - 0xc0];
    Player* localPlayer;
    int pad3;
    Peer* peer;
    void reportAbuse(Player* player, std::string reason);
};
void Players::reportAbuse(Player* player, std::string reason)
{
    if (signal)
    {
        const char* name = player ? player->name.c_str() : "[[[anonymous]]]";
        StandardOut::singleton()->printf(1, "Submitting abuse report from %s", name);
        AbuseReport report;
        report.abuser = idOf(localPlayer);
        report.reporter = idOf(player);
        report.reason = reason;
        Signal& s = *signal;
        s.invoke(&report, &history);
    }
    else
    {
        StandardOut::singleton()->print(1, "Sending abuse report to game server via Raknet");
        if (!peer)
            throw RuntimeError("Can't report abuse: Not in a networked game");
        boost::shared_ptr<BitStream> stream(new BitStream());
        writeByte(stream.get(), 0x67);
        writeInt(stream.get(), idOf(localPlayer));
        writeInt(stream.get(), idOf(player));
        writeString(stream.get(), &reason);
        peer->send(stream, 1, 2, 2, unassigned, 1);
    }
}
