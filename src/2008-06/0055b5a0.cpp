// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct S;
struct Document;
struct Sink;

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Connection {
    void send(Document*, Sink*);
    void remove(S*);
};

struct Shared {
    Connection* pointer;
    Control* control;
    __forceinline ~Shared();
};

__forceinline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

struct Value {
    bool extract(int*);
};

struct Node {
    unsigned char prefix[8];
    Value value;
};

struct Document {
    Node* find(int);
};

struct Sink {
    virtual void write(Value*, int);
};

extern int connectionKey;
extern int fallbackKey;

struct S {
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
    virtual Shared getConnection(int);
    void process(Document*, Sink*);
};

void S::process(Document* document, Sink* sink)
{
    int id = 0;
    Node* node = document->find(connectionKey);
    if (node && node->value.extract(&id)) {
        Shared connection = getConnection(id);
        if (connection.pointer) {
            connection.pointer->send(document, sink);
            if (connection.pointer)
                connection.pointer->remove(this);
        } else {
            Node* fallback = document->find(fallbackKey);
            if (fallback)
                sink->write(&fallback->value, 0);
        }
    }
}
