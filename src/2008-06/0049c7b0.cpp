// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_abusehistorymemberf61670cd6573df67.cpp

// Candidate translation unit (score above; library headers required).
// from server: 96% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
#include <exception>

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control
{
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Output
{
    void __cdecl print(int, const char*, ...);
};

struct Handle
{
    Output* object;
    Control* control;

    Output* operator->() const;
    ~Handle();
};

inline Output* Handle::operator->() const { return object; }

inline Handle::~Handle()
{
    if (control)
    {
        Control* p = control;
        if (_InterlockedDecrement(&p->strong) == 0)
        {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Handle __cdecl sub_569620();

#include <stdexcept>
#include <list>
typedef std::runtime_error RuntimeError;

struct Player
{
    char pad[0x110];
    std::string name;
    char pad2[0x1b4 - 0x110 - sizeof(std::string)];
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

#include "../Network/raknet30/Source/BitStream.h"
typedef RakNet::BitStream BitStream;

void __cdecl writeByte(BitStream*, int);
void __cdecl writeInt(BitStream*, int);
void __cdecl writeString(BitStream*, std::string*);

extern SystemAddress unassigned;

struct Peer
{
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void send(BitStream*, int, int, int, SystemAddress, int);
};

struct Signal
{
    void invoke(AbuseReport*, void*);
};

struct Pad
{
    char pad[0x174];
    Signal* signal;
};

struct Slot
{
    char data[0x28];
};

struct Players : Pad
{
    Slot history;
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
        sub_569620()->print(1, "Submitting abuse report from %s", name);

        AbuseReport report;
        report.abuser = idOf(localPlayer);
        report.reporter = idOf(player);
        report.reason = reason;
        Signal& s = *signal;
        s.invoke(&report, &history);
    }
    else
    {
        sub_569620()->print(1, "Sending abuse report to game server via Raknet");

        if (!peer)
            throw RuntimeError("Can't report abuse: Not in a networked game");

        BitStream stream;
        writeByte(&stream, 0x52);
        writeInt(&stream, idOf(localPlayer));
        writeInt(&stream, idOf(player));
        writeString(&stream, &reason);
        peer->send(&stream, 1, 2, 2, unassigned, 1);
    }
}
