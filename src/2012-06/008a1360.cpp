// from server: 100% by tajop

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct V0 { virtual void a0(); };
struct V1 { virtual void a1(); char pad[0x10]; };
struct V2 { virtual void a2(); };
struct V3 { virtual void a3(); char pad[0x80]; };

struct Base : V0, V1, V2, V3 {
    virtual ~Base();
};

struct CountBase {
    virtual void v0();
    virtual void v1();
    virtual void destroy();
    long useCount;
    long weakCount;
    void weak_release() {
        if (_InterlockedDecrement(&weakCount) == 0)
            destroy();
    }
};

struct WeakCount {
    CountBase* pi;
    ~WeakCount() {
        if (pi != 0)
            pi->weak_release();
    }
};

struct WeakRef {
    void* px;
    WeakCount pn;
};

struct Str {
    char pad[0x1c];
    ~Str();
    void destroy();
};
extern void (Str::*basic_string_dtor)();
inline Str::~Str() { (this->*basic_string_dtor)(); }

struct SignalVoid {
    void* impl;
    ~SignalVoid();
};

struct SignalString {
    void* impl;
    ~SignalString();
};

struct Mouse : Base {
    ~Mouse();
    WeakRef targetFilter;
    Str icon;
    int field_c4;
    SignalVoid moveSignal;
    SignalVoid idleSignal;
    SignalVoid button1DownSignal;
    SignalVoid button2DownSignal;
    SignalVoid button1UpSignal;
    SignalVoid button2UpSignal;
    SignalVoid wheelForwardSignal;
    SignalVoid wheelBackwardSignal;
    SignalString keyDownSignal;
    SignalString keyUpSignal;
};

Mouse::~Mouse() {
}
