// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { class shared_count { void* pi_; public: ~shared_count(); }; }
template<class T> class shared_ptr {
    T* px;
    detail::shared_count pn;
public:
    shared_ptr(const shared_ptr& r);
    ~shared_ptr();
};
template<class T> class weak_ptr {
    T* px;
    void* pn;
public:
    shared_ptr<T> lock() const;
};
}
namespace RBX {
class Task;
class TaskScheduler {
public:
    static TaskScheduler& singleton();
    void add(boost::shared_ptr<Task> task);
};
class View {
    char pad0[8];
    boost::weak_ptr<Task> task;
    char pad1[0x1d0 - 0x10];
    bool started;
public:
    void start();
};
void View::start()
{
    started = true;
    TaskScheduler::singleton().add(task.lock());
}
}
