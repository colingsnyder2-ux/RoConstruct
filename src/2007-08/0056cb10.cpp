// from server: 100% by EspClaude
// roc 2007-08 0056cb10  unit: RBX::Lua::FunctionRef  size: 235 bytes
// RBX::Lua::ThreadRef::~ThreadRef() (reset() body) (rbxgs script/ThreadRef.cpp) with reset/removeFromNode/
// removeRef inlined. 2007 removeFromNode does not clear `node` (no store in the target).
// roc-flags: /O2 /GS- /EHsc /MD
#include <intrin.h>
#include <exception>
struct lua_State;  // Lua is compiled as C++ in the client
void luaL_unref(lua_State* L, int t, int ref);
#define LUA_REGISTRYINDEX (-10000)
#define lua_unref(L,ref) luaL_unref(L, LUA_REGISTRYINDEX, (ref))
namespace boost {
class thread_exception : public std::exception { int m_sys_err; protected: thread_exception(); public: ~thread_exception() throw(); };
class lock_error : public thread_exception { public: lock_error(); ~lock_error() throw(); virtual const char* what() const throw(); };
struct mutex {
    void* m_mutex; bool m_critical_section;
    void do_lock(); void do_unlock();
    struct scoped_lock {
        mutex& m_mutex; bool m_locked;
        explicit scoped_lock(mutex& m, bool initially_locked = true) : m_mutex(m), m_locked(false) { if (initially_locked) lock(); }
        ~scoped_lock() { if (m_locked) unlock(); }
        void lock() { if (m_locked) throw lock_error(); m_mutex.do_lock(); m_locked = true; }
        void unlock() { if (!m_locked) throw lock_error(); m_mutex.do_unlock(); m_locked = false; }
    };
};
namespace detail {
class sp_counted_base {
public:
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
    long use_count_; long weak_count_;
    void release() { if (_InterlockedDecrement(&use_count_) == 0) { dispose(); weak_release(); } }
    void weak_release() { if (_InterlockedDecrement(&weak_count_) == 0) destroy(); }
};
class shared_count {
public:
    sp_counted_base* pi_;
    ~shared_count() { if (pi_ != 0) pi_->release(); }
};
}
template<class T> class shared_ptr {
public:
    T* px; detail::shared_count pn;
    T& operator*() const { return *px; }
};
}
namespace RBX { namespace Lua {
class ThreadRef {
public:
    class Node { friend class ThreadRef; ThreadRef* first; };
private:
    const boost::shared_ptr<boost::mutex> sync;
    Node* node;
    ThreadRef* previous;
    ThreadRef* next;
    lua_State* L;
    int threadId;
    void removeFromNode()
    {
        if (node)
        {
            if (next)
                next->previous = previous;
            if (previous)
                previous->next = next;
            if (node->first == this)
                node->first = next;
            next = 0;
            previous = 0;
        }
    }
protected:
    virtual void removeRef()
    {
        if (L)
        {
            lua_unref(L, threadId);
            threadId = 0;
            L = 0;
        }
    }
public:
    ~ThreadRef();
    void reset()
    {
        boost::mutex::scoped_lock lock(*sync);
        removeFromNode();
        removeRef();
    }
};

ThreadRef::~ThreadRef()
{
    boost::mutex::scoped_lock lock(*sync);
    removeFromNode();
    removeRef();
}
}}
