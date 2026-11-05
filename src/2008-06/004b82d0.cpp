// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_networkbindercopy_98493a5beb0d828b.cpp

// Candidate translation unit (score above; library headers required).
#include <string>
#include <boost/shared_ptr.hpp>
struct String {
    char storage[28];
    String(const char*);
    ~String();
};

extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

__forceinline String::String(const char* text)
{
    stringConstruct(this, text);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

struct Network;

struct Connection {
    virtual void unused() = 0;
    virtual void attach(void*) = 0;
    void disconnect(int);
    void setNetwork(boost::shared_ptr<Network>);
};

struct Found {
    char prefix[0xe4];
    char signal;
};

struct Source {
    Found* find(const String&);
};

struct Dispatcher {
    typedef void* (__thiscall *Method)(Dispatcher*, unsigned long, unsigned long);
    struct Table {
        void* reserved[67];
        Method invoke;
    };
    Table* table;
};

struct S;

struct Binder {
    Binder();
    Binder(const Binder&);
    unsigned long words[2];
};

extern boost::shared_ptr<Network> __cdecl getNetwork(void*);
extern Binder __cdecl makeBinder(S*);
extern boost::shared_ptr<Connection> __cdecl build(Binder, void*);

struct S {
    char prefix[0x110];
    char attachment[0x2b88 - 0x110];
    boost::shared_ptr<Connection> connection;
    char padding[0x2d50 - 0x2b90];
    Dispatcher* dispatcher;
    unsigned long first;
    unsigned long second;
    void f(Source*);
};

void S::f(Source* source)
{
    if (connection.get()) {
        connection.get()->disconnect(0);
        connection.reset();
    }

    if (source) {
        Found* found;
        boost::shared_ptr<Network> network = getNetwork(
            (found = source->find(String("Network")))
                ? &found->signal : 0);

        if (network.get()) {
            connection = build(
                makeBinder(this),
                dispatcher->table->invoke(dispatcher, first, second));
            connection.get()->attach(attachment);
            connection.get()->setNetwork(network);
        }
    }
}