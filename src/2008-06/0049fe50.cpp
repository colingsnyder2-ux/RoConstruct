// from server: 100% by king_originala
struct Client;
struct Peer;

struct Listener
{
    unsigned state;
    void detach(Listener*);
    void attach(Listener*);
};

struct Property
{
    void set(Peer*);
};

struct Node
{
    char padding[0x130];
    Listener listener;
    Property* oldProperty();
    Property* newProperty();
};

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

struct Client
{
    char padding[0x140];
    Peer* peer;
    Listener listener;
    unsigned first;
    unsigned second;

    void prepare();
    void change(Node*, Node*);
    void func_0049fe50(Node*, Node*);
};

void Client::func_0049fe50(Node* oldNode, Node* newNode)
{
    Listener* link = this ? &listener : 0;
    if (oldNode)
    {
        oldNode->listener.detach(link);
        prepare();
        peer->start(first, second, 1, 0);
        peer->stop(3000, 0);
        Property* property = oldNode->oldProperty();
        property->set(0);
    }

    change(oldNode, newNode);

    if (newNode)
    {
        Property* property = newNode->newProperty();
        property->set(peer);
    }

    link = this ? &listener : 0;
    if (newNode)
        newNode->listener.attach(link);
}
