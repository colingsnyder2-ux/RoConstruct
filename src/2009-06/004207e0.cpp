// from server: 100% by EspClaude
// from server: 84% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espclaude_1252470ad2442286.cpp

// Candidate translation unit (score above; library headers required).
#include <set>
#include <vector>
#include <algorithm>
#include <intrin.h>
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
namespace detail {
struct basic_timed_mutex {
    long active_count; void* event;
    void* get_event();
    void unlock() {
        long const offset=0x80000000;
        long const old_count=_InterlockedExchangeAdd(&active_count,offset);
        if(!(old_count&0x40000000) && (old_count>offset)) {
            if(!_interlockedbittestandset(&active_count,30)) SetEvent(get_event());
        }
    }
};
struct basic_recursive_mutex {
    long recursion_count; long locking_thread_id; basic_timed_mutex mutex;
    void lock();
    void unlock() { if(!--recursion_count) { _InterlockedExchange(&locking_thread_id,0); mutex.unlock(); } }
};
}
class recursive_mutex : public detail::basic_recursive_mutex {
public:
    struct scoped_lock { recursive_mutex* m; bool is_locked; explicit scoped_lock(recursive_mutex& m_):m(&m_),is_locked(false){ m->lock(); is_locked=true; } ~scoped_lock(){ if(is_locked) m->unlock(); } };
};
}
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void*,unsigned,unsigned,long);
struct Item {char padding[140];long handle;};
struct Vector:std::vector<Item*> {void collect(Item* const&);};
typedef std::set<Item*> Tree;
typedef boost::recursive_mutex Lock;
struct Owner {char padding[32];void* window;char reserved[160];Lock mutex;};
typedef void (Vector::*Callback)(Item* const&);
struct Functor {Callback callback;Vector* object;Functor(Callback c,Vector* p):callback(c),object(p){}void operator()(Item* const& item)const{(object->*callback)(item);}};
struct S {char padding[60];Tree tree;char reserved[4];Owner* owner;void f();};
void S::f(){
 Vector values;
 {Lock::scoped_lock guard(owner->mutex);std::for_each(tree.begin(),tree.end(),Functor(&Vector::collect,&values));tree.clear();}
 for(Vector::iterator i=values.begin();i!=values.end();++i)SendMessageA(owner->window,0x1101,0,(*i)->handle);
}

