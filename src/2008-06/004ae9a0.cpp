// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_marker_97e43f62bf26f91e.cpp

// Candidate translation unit (score above; library headers required).
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

#include <boost/shared_ptr.hpp>
typedef boost::shared_ptr<void> Shared;

struct Settings {
    char padding[0x131];
    unsigned char logging;
};

struct Endpoint {
    const char* text(int);
};

struct Owner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void sent(int);

    char padding[0x2d50];
    Endpoint endpoint;
};

void __cdecl writeKind(void*, int);
void __cdecl writeMarker(void*, int);
Settings* __cdecl settings();
Shared __cdecl acquireLogger();
void __cdecl logMessage(void*, int, const char*, ...);

struct MarkerItem {
    unsigned int padding;
    Owner* owner;
    int marker;
    void send(void*);
};

void MarkerItem::send(void* stream)
{
    writeKind(stream, 4);
    writeMarker(stream, marker);

    if (settings()->logging) {
        logMessage(acquireLogger().get(), 1, "Replication: Sending marker %d to %s",
                   marker, owner->endpoint.text(1));
    }

    owner->sent(marker);
}