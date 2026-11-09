// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void*);

namespace RBX {
struct V0 { virtual ~V0(); int pad[4]; };
struct V1 { virtual void f1(); };
struct V2 { virtual void f2(); int pad; };
struct V3 { virtual void f3(); };
class Instance : public V0, public V1, public V2, public V3 {
public:
    int rest[(0x8c - 0x24) / 4];
    virtual ~Instance();
};
class Service : public Instance {
public:
    virtual ~Service() {}
};

struct CountedBase {
    virtual ~CountedBase();
    virtual void dispose() = 0;
    virtual void destroy();
    long use;
    long weak;
    void release() {
        if (_InterlockedDecrement(&use) == 0) {
            dispose();
            if (_InterlockedDecrement(&weak) == 0)
                destroy();
        }
    }
};
struct SharedCount {
    CountedBase* pi;
    ~SharedCount() { if (pi) pi->release(); }
};
struct SP { void* px; SharedCount pn; };

template<class T> struct ScopedPtr {
    T* px;
    ~ScopedPtr() { delete px; }
};

struct M90 { int d[8]; ~M90(); };
struct Mb0 { int d[10]; ~Mb0(); };
struct Md8 { int d[6]; ~Md8(); };
struct Q { int d; ~Q(); };
struct Tf8 { int a; Q q; };
struct T124 { int d; ~T124(); };
struct Mutex {
    long active;
    void* event;
    ~Mutex() {
        void* old = (void*)_InterlockedExchange((long*)&event, 0);
        if (old) CloseHandle(old);
    }
};
struct M130 { int d; ~M130() throw(); };
struct T138 { int d; ~T138(); };
struct Y { int d[4]; ~Y(); };
struct X : Y { void clear(); ~X() { clear(); } };

class ScriptContext : public Service {
public:
    int pad8c;
    M90 m90;
    Mb0 mb0;
    Md8 md8;
    SP sp0;
    ScopedPtr<Tf8> spf8;
    int padfc;
    SP sp100;
    int pad108[7];
    ScopedPtr<T124> sp124;
    Mutex mutex;
    M130 m130;
    M130 m134;
    ScopedPtr<T138> sp138;
    X x;
    virtual ~ScriptContext();
};
ScriptContext::~ScriptContext() {}
}
