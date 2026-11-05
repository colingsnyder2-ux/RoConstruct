// from server: 100% by EspClaude
// roc 2007-08 005376e0  unit: RBX::Lua::ThreadRef::VNode::V?$shared_ptr::?$TItem  size: 102 bytes
// Locked unlink of an intrusive list node: boost::mutex::scoped_lock on the mutex pointer at +4,
// out-of-line unlink (0056c670), then virtual slot 0. boost 1.34 mutex/scoped_lock declarations.
// roc-flags: /O2 /GS- /EHsc /MD
#include <exception>
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
}
namespace RBX {
class Node {
public:
    virtual void onRemoved() = 0;
    boost::mutex* mutex;
    void unlink();
    void remove();
};

void Node::remove()
{
    boost::mutex::scoped_lock lock(*mutex);
    unlink();
    onRemoved();
}
}
