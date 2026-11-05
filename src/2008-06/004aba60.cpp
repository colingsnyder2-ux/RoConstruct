// from server: 100% by colin


struct BitStream {
    int bitsUsed;
    int bitsAllocated;
    int readOffset;
    unsigned char* data;
    bool ownsData;

    void Reset();
    ~BitStream();
};

extern void __cdecl Prepare(BitStream*, int);

struct Peer;

struct PeerTable {
    void* entries[13];
    bool (__thiscall* Send)(Peer*, BitStream*, int, int, int,
                           unsigned int, unsigned int, int);
};

struct Peer {
    PeerTable* table;
};

struct Owner {
    unsigned char padding[0x2D54];
    unsigned int address;
    unsigned int port;
};

struct S {
    Owner* owner;
    Peer* peer;
    BitStream stream;

    ~S();
};

S::~S()
{
    int bytes = (stream.bitsUsed + 7) >> 3;
    if (bytes > 0) {
        Prepare(&stream, 0);
        Peer* p = peer;
        Owner* o = owner;
        p->table->Send(p, &stream, 2, 3, 0,
                       o->address, o->port, 0);
    }
    stream.Reset();
}
