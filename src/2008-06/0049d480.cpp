// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_playerargument_b270c37333ee0a94.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 84% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *stringConstructor)(String*, const char*);

__forceinline String::String(const char* text) {
    stringConstructor(this, text);
}

struct Error {
    char storage[40];
    Error(const String&);
    ~Error();
};

extern "C" __declspec(noreturn) void __stdcall ThrowObject(void*, void*);

struct Player {char storage[20];void initialize(int);void attach(void*);};
typedef boost::shared_ptr<Player> Shared;

extern Shared __cdecl createPlayer();

struct Context {
    int get();
    void set(int);
    void restore(int);
};

extern Context* __cdecl currentContext();

struct Scope {
    int saved;
    Scope(int);
    ~Scope();
};

__forceinline Scope::~Scope() {
    Context* context = currentContext();
    int previous = context->get();
    if (previous != saved) {
        context->set(saved);
        if (previous)
            context->restore(previous);
    }
}

struct Property {
    void set(bool);
};

struct Registry {
    virtual void unused0();
    virtual void unused1();
    virtual bool contains(void*);
};

extern Registry* registry;

struct S {
    char padding[0x150];
    Property property;
    char gap[0x4f];
    Shared player;

    void notify(void*);
    void assign(const Shared&);
    Shared f(int);
};

__forceinline void S::assign(const Shared& value) {
    player = value;
}

Shared S::f(volatile int argument) {
    if (player) {
        String message("Local player already exists");
        Error error(message);
        ThrowObject(&error, reinterpret_cast<void*>(0x8d1bc8));
    }

    {
        Scope scope(6);
        assign(createPlayer());
    }

    player->initialize(argument);
    player->attach(this);
    notify(reinterpret_cast<void*>(0x970388));

    bool present;
    if (player)
        present = registry->contains(reinterpret_cast<char*>(player.get()) + 20);
    else
        present = false;
    property.set(present);

    return player;
}
