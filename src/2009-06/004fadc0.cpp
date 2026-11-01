// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a2ac0  unit: RBX::Network::VServer::?$FactoryProduct  size: 348 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a2ac0
//

struct BitStream {
    unsigned int used;
    unsigned int capacity;
    unsigned int readOffset;
    unsigned char* data;
    unsigned char ownsData;
    unsigned char buffer[1024];

    BitStream();
    ~BitStream();
};

extern "C" void __cdecl writeByte(BitStream*, unsigned char);
extern "C" void __cdecl writeValue(BitStream*, unsigned char);
extern "C" char* __cdecl getValue();
extern void (__cdecl* const invalidParameter)();

typedef void (__cdecl* ErrorHandler)();

struct Container {
    unsigned char padding[16];
    unsigned int* end;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    unsigned int* position;
    Proxy* proxy;
    unsigned int unused;

    Container* getContainer() const;
    unsigned int value(ErrorHandler) const;
    void advance(ErrorHandler);
};

__forceinline Container* Iterator::getContainer() const
{
    return proxy ? proxy->container : 0;
}

__forceinline unsigned int Iterator::value(ErrorHandler error) const
{
    if (!proxy)
        error();
    if (position >= getContainer()->end)
        error();
    return *position;
}

__forceinline void Iterator::advance(ErrorHandler error)
{
    if (!proxy)
        error();
    if (position >= getContainer()->end)
        error();
    ++position;
}

struct Peer {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void send(BitStream*, int, int, int, unsigned int,
                      unsigned int, int) = 0;
};

struct S {
    unsigned char padding0[0x2bb4];
    Proxy* proxy;
    unsigned char padding1[8];
    unsigned int* begin;
    unsigned int* end;
    unsigned char padding2[0x2ef8 - 0x2bc8];
    unsigned int address;
    unsigned int port;
    unsigned char padding3[0x2f10 - 0x2f00];
    unsigned char flag;

    void append(BitStream*, unsigned int);
    void finish(unsigned int, BitStream*);
    void f(Peer* peer);
};

void S::f(Peer* peer)
{
    BitStream stream;
    writeByte(&stream, 0x5f);
    writeValue(&stream, flag);

    Iterator last;
    last.position = end;
    ErrorHandler error = invalidParameter;
    if (begin > last.position)
        error();
    last.proxy = proxy;

    {
        Iterator current;
        current.position = begin;
        if (current.position > end)
            error();
        current.proxy = proxy;

        for (;;) {
            if (!current.proxy || current.proxy != last.proxy)
                error();
            if (current.position == last.position)
                break;
            append(&stream, current.value(error));
            current.advance(error);
        }
    }

    if (!(0u < static_cast<unsigned int>(end - begin)))
        error();
    finish(*begin, &stream);
    peer->send(&stream, 2, 3, 0, address, port, 0);
}
