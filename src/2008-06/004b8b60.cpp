// from server: 100% by king_originala
struct Lock {
    char storage[24];
    Lock(void *, bool);
    ~Lock();
};

struct BitStream {
    char storage[276];
    BitStream(unsigned char *, unsigned int, bool);
    ~BitStream();
    void IgnoreBits(int);
};

struct Packet {
    char padding[12];
    unsigned int length;
    char unused[4];
    unsigned char *data;
};

struct ClientProxy {
    char padding[0x2d24];
    void *mutex;

    void process(Packet *);
    void handle(BitStream *);
};

void ClientProxy::process(Packet *packet)
{
    Lock lock(mutex, false);
    BitStream stream(packet->data, packet->length, false);
    stream.IgnoreBits(8);
    handle(&stream);
}
