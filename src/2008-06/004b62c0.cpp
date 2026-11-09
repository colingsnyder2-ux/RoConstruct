// from server: 100% by EspClaude
// from server: 99% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_b43d317ef6c442d8.cpp

// Candidate translation unit (score above; library headers required).
#include <intrin.h>
#include <boost/shared_ptr.hpp>
// from server: 91% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern unsigned long table0[];
extern unsigned long table10[];
extern unsigned long table14[];
extern unsigned long table20[];
extern unsigned long table24[];
extern unsigned long table44[];
extern unsigned long table64[];
extern unsigned long table84[];
extern unsigned long tablea4[];
extern unsigned long tablec4[];

struct Control {
    virtual void reserved() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct CodeProfiler;
template<class T> struct SP { T* px; T& operator*() const { return *px; } };
struct Source {
    char padding[0x2d1c];
    SP<CodeProfiler> item1c;
    SP<CodeProfiler> item20;
    SP<CodeProfiler> item24;
    SP<CodeProfiler> item28;
    SP<CodeProfiler> item2c;
    SP<CodeProfiler> item30;
    SP<CodeProfiler> item34;
    SP<CodeProfiler> item38;
    SP<CodeProfiler> item3c;
    SP<CodeProfiler> item40;
    SP<CodeProfiler> item44;
    SP<CodeProfiler> item48;
};

typedef boost::shared_ptr<Source> Shared;

struct Base {
    unsigned long words[0x158 / 4];
    void* value158;
    void* value15c;
    void* value160;
    void* value164;

    Base();
    ~Base();
    void* lookup(const char*);
    Base* attach(CodeProfiler&);
    void bind(const char*, void*);
};

struct Receiver : Base {
    Shared source;
    void* owner;
    void* value174;
    void* value178;

    Receiver(const Shared*, void*);
    const Shared& initializeTables(const Shared*);
};

inline const Shared& Receiver::initializeTables(const Shared* argument)
{
    words[0x00 / 4] = reinterpret_cast<unsigned long>(table0);
    words[0x10 / 4] = reinterpret_cast<unsigned long>(table10);
    words[0x14 / 4] = reinterpret_cast<unsigned long>(table14);
    words[0x20 / 4] = reinterpret_cast<unsigned long>(table20);
    words[0x24 / 4] = reinterpret_cast<unsigned long>(table24);
    words[0x44 / 4] = reinterpret_cast<unsigned long>(table44);
    words[0x64 / 4] = reinterpret_cast<unsigned long>(table64);
    words[0x84 / 4] = reinterpret_cast<unsigned long>(table84);
    words[0xa4 / 4] = reinterpret_cast<unsigned long>(tablea4);
    words[0xc4 / 4] = reinterpret_cast<unsigned long>(tablec4);
    return *argument;
}

Receiver::Receiver(const Shared* argument, void* other)
    : Base(), source(initializeTables(argument)),
      owner(other), value174(0), value178(0)
{
    value160 = lookup("Ping");
    Base* initial = attach(*(*argument)->item40);
    initial->bind("Bandwidth Exceeded",
                  static_cast<char*>(other) + 0xc4);

    value15c = lookup("Packet Loss");
    attach(*(*argument)->item3c);
    attach(*(*argument)->item44);
    attach(*(*argument)->item48);

    _ReadWriteBarrier();
    Base* branch = attach(*(*argument)->item1c);
    branch->attach(*(*argument)->item20);
    branch->attach(*(*argument)->item28);

    Base* nested = branch->attach(*(*argument)->item30);
    nested->attach(*(*argument)->item34);
    nested->attach(*(*argument)->item38);

    branch->attach(*(*argument)->item24);
    branch->attach(*(*argument)->item2c);

    value164 = branch->lookup("Instance size (In)");
    value158 = branch->lookup("Waiting Refs");
}

