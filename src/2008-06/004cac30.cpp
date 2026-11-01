// from server: 100% by colin
struct BitStream {
    int bitsUsed;
    char storage[0x114];

    void Reset();
};

void __cdecl writeByte(BitStream*, unsigned char);
void __cdecl writeTime(BitStream*, unsigned int);
unsigned int __cdecl getTime();

struct Item {
    virtual void unused() = 0;
    virtual unsigned int value() = 0;
};

struct Sender {
    void send(BitStream*, unsigned int);
};

struct S {
    char padding0[8];
    Sender* sender;
    char padding1[4];
    bool initialized;
    char padding2[3];
    int limit;
    BitStream stream;
    int count;

    bool f(Item*);
};

bool S::f(Item* item)
{
    if (!initialized) {
        stream.Reset();
        writeByte(&stream, 0x18);
        writeTime(&stream, getTime());
        writeByte(&stream, 0x50);
        ++count;
        initialized = true;
    }

    sender->send(&stream, item->value());
    return ((stream.bitsUsed + 7) >> 3) < limit;
}
