// from server: 100% by king_originala
struct Stream {
    int bits;
    char padding[272];
};

struct Address {
    unsigned int low;
    unsigned int high;
};

struct PeerState {
    char padding[0x2d54];
    Address address;
    void prepare(Stream*, int);
};

struct Holder {
    int padding;
    PeerState* state;
};

struct Peer {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual bool send(Stream*, int, int, char, Address, bool);
};

struct Receiver {
    char padding0[8];
    Holder* holder;
    Peer* peer;
    unsigned char pending;
    char padding1[7];
    Stream stream;
    int priority;

    void flush();
};

void Receiver::flush()
{
    if (((stream.bits + 7) & ~7) > 0) {
        holder->state->prepare(&stream, 0);
        Address address = holder->state->address;
        peer->send(&stream, priority, 4, 0, address, false);
    }
    pending = 0;
}
