// from server: 100% by king_originala
extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

struct Peer
{
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
    virtual void stop(int, int);
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void start(unsigned, unsigned, int, int);
};

struct Callback
{
    void func_0049f130(int, int);
};

struct Client
{
    char padding[0x140];
    Peer* peer;
    Callback callback;
    unsigned first;
    unsigned second;

    void prepare();
};

void Callback::func_0049f130(int, int)
{
    Client* client = reinterpret_cast<Client*>(
        reinterpret_cast<char*>(this) - 0x144);
    client->prepare();
    client->peer->start(client->first, client->second, 1, 0);
    client->peer->stop(3000, 0);
    _ReadWriteBarrier();
}
