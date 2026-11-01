// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace boost {
namespace detail { class shared_count { void* pi_; public: shared_count(const shared_count&); ~shared_count(); }; }
template<class T> class shared_ptr {
public:
    shared_ptr(const shared_ptr& r);
    ~shared_ptr();
private:
    T* px;
    detail::shared_count pn;
};
}
class Job;
class JobQueue {
public:
    static JobQueue& singleton();
    void add(boost::shared_ptr<Job> job);
};
namespace boost {
template<class T> class enable_shared_from_this {
public:
    shared_ptr<T> shared_from_this();
private:
    T* wp; void* wc;
};
}
struct Head { int a, b; };
class Starter : public Head, public boost::enable_shared_from_this<Job> {
public:
    void start();
private:
    char pad2[0x1dc - 0x10];
    volatile bool started;
};
void Starter::start()
{
    if (!started) {
        started = true;
        JobQueue::singleton().add(shared_from_this());
    }
}
