// from server: 100% by king_originala
struct BitStream {
    unsigned int used;
    unsigned int capacity;
    unsigned int readOffset;
    unsigned char* data;
    unsigned char ownsData;
    unsigned char buffer[256];

    BitStream();
    ~BitStream();
};

extern "C" void __cdecl writeByte(BitStream*, unsigned char);
extern "C" void __cdecl writeValue(BitStream*, const void*);
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
    virtual void send(BitStream*, int, int, int, unsigned int,
                      unsigned int, int) = 0;
};

struct S {
    unsigned char padding0[0x2c58];
    Proxy* proxy;
    unsigned char padding1[8];
    unsigned int* begin;
    unsigned int* end;
    unsigned char padding2[0xe4];
    Peer* peer;
    unsigned int address;
    unsigned int port;

    void append(BitStream*, unsigned int);
    void finish(unsigned int, BitStream*);
    void f();
};

void S::f()
{
    BitStream stream;
    writeByte(&stream, 0x4b);
    writeValue(&stream, getValue() + 4);

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
