// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_38ecfe3a0952d4a6.cpp

// Candidate translation unit (score above; library headers required).
#include <map>
#include <set>
#include <intrin.h>
#include <boost/shared_ptr.hpp>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
inline bool interlocked_bit_test_and_set(long* x, long bit) { return _interlockedbittestandset(x, bit) != 0; }
struct TimedMutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock() {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, offset);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!interlocked_bit_test_and_set(&active_count, 30)) {
                SetEvent(get_event());
            }
        }
    }
};
struct Lock {
    long recursion_count;
    long locking_thread_id;
    TimedMutex mutex;
    void acquire();
    void release() {
        if (!--recursion_count) {
            _InterlockedExchange(&locking_thread_id, 0);
            mutex.unlock();
        }
    }
};
struct Guard {Lock* lock;bool held;Guard(Lock*p):lock(p),held(false){lock->acquire();held=true;}~Guard(){if(held)lock->release();}};
struct Object{};
struct Selection {void erase(const boost::shared_ptr<Object>*);};
struct Index{void erase(Object*const*);};
struct Parent {virtual void unused();char padding[0x94];Index index;char gap[0xc4-0x99];Lock lock;};
struct Node {char padding[0x1c];std::map<Object*,void*> entries;std::set<void*> collection;char gap[4];Parent*parent;char gap2[8];Selection selection;void update(boost::shared_ptr<Object> value);};
typedef void (__thiscall*Notify)(Parent*,void*);
void Node::update(boost::shared_ptr<Object>value){ {Guard guard(&parent->lock);Object*key=value.get();parent->index.erase(&key);key=value.get();std::map<Object*,void*>::iterator position=entries.find(key);if(position!=entries.end())collection.insert(position->second);selection.erase(&value);}(*reinterpret_cast<Notify**>(parent))[87](parent,this);}
