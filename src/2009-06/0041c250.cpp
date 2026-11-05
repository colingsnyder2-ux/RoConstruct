// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <deque>
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Control {
    virtual ~Control();
    virtual void dispose();
    virtual void destroy();
    volatile long use_count;
    volatile long weak_count;
    void release() {
        if (_InterlockedDecrement(&use_count) == 0) {
            dispose();
            weak_release();
        }
    }
    void weak_release() {
        if (_InterlockedDecrement(&weak_count) == 0)
            destroy();
    }
};
template<class T> struct shared_ptr {
    T* px;
    Control* pi;
    ~shared_ptr() {
        if (pi != 0) pi->release();
    }
};
struct Item;
struct Connection {
    void* p;
    Control* pi;
    void disconnect();
    ~Connection();
};
struct ScopedConnection : Connection {
    ~ScopedConnection() { disconnect(); }
};
class CBaseView {
public:
    virtual ~CBaseView();
    char storage[0x374];
};
struct Thing;
class CInstanceExplorer : public CBaseView {
    shared_ptr<Thing> thing;
    int flags;
    std::deque<shared_ptr<Item> > queue;
    int extra[2];
    ScopedConnection conn1;
    ScopedConnection conn2;
public:
    virtual ~CInstanceExplorer();
    void reset(int);
};
CInstanceExplorer::~CInstanceExplorer()
{
    reset(0);
}
