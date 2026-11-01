// from server: 95% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <list>
#include <queue>
#include <string>
extern "C" long __cdecl _InterlockedExchangeAdd(long volatile*, long);
extern "C" long __cdecl _InterlockedIncrement(long volatile*);
extern "C" unsigned char _interlockedbittestandset(long*, long);
#pragma intrinsic(_InterlockedExchangeAdd, _InterlockedIncrement, _interlockedbittestandset)
extern "C" __declspec(dllimport) int __stdcall SetEvent(void*);
namespace boost {
namespace detail {
struct basic_timed_mutex {
    long active_count;
    void* event;
    void* get_event();
    void unlock()
    {
        long const offset = 0x80000000;
        long const old_count = _InterlockedExchangeAdd(&active_count, 0x80000000);
        if (!(old_count & 0x40000000) && (old_count > offset)) {
            if (!(_interlockedbittestandset(&active_count, 30) != 0)) {
                SetEvent(get_event());
            }
        }
    }
};
}
class mutex : public detail::basic_timed_mutex {};
template<class Mutex> class unique_lock {
    Mutex* m;
    bool is_locked;
public:
    explicit unique_lock(Mutex& m_) : m(&m_), is_locked(false) { lock(); }
    ~unique_lock() { if (owns_lock()) m->unlock(); }
    void lock();
    bool owns_lock() const { return is_locked; }
};
template<> void unique_lock<mutex>::lock();
template<class T> class shared_ptr { T* px; void* pn; public: T* operator->() const { return px; } };
template<class T> struct reference_wrapper { T* t_; };
template<class T> inline reference_wrapper<T> ref(T& t) { reference_wrapper<T> r = { &t }; return r; }
template<class R, class T, class A> struct mf1 { R (T::*f_)(A); };
template<int I> struct arg {};
template<class A1, class A2> struct list2 { A1 a1_; };
template<class R, class F, class L> struct bind_t { F f_; L l_; bind_t& operator=(const bind_t&); template<class A> void operator()(const A& a); };
template<class R, class T, class B1, class A1>
inline bind_t<R, mf1<R, T, B1>, list2<A1, arg<1> > > bind(R (T::*f)(B1), A1 a1, arg<1>)
{
    bind_t<R, mf1<R, T, B1>, list2<A1, arg<1> > > b = { { f }, { a1 } };
    return b;
}
}
static boost::arg<1> _1;
struct ChatMessage { std::string first, second; void* owner; };
struct Report {
    int submitter, abuser;
    std::string comment;
    struct Message { int id; std::string first, second; };
    std::list<Message> messages;
    void add(const ChatMessage&);
};
typedef boost::bind_t<void, boost::mf1<void, Report, const ChatMessage&>, boost::list2<boost::reference_wrapper<Report>, boost::arg<1> > > AddBinder;
namespace std { template<> AddBinder for_each(std::list<ChatMessage>::const_iterator, std::list<ChatMessage>::const_iterator, AddBinder); }
struct Object { std::queue<Report> queue; boost::mutex mutex; };
struct Completion { void finish(); };
struct S {
    boost::shared_ptr<Object> object;
    Completion* completion;
    void f(Report&, const std::list<ChatMessage>&);
};
void S::f(Report& value, const std::list<ChatMessage>& args)
{
    std::for_each(args.begin(), args.end(), boost::bind(&Report::add, boost::ref(value), _1));
    {
        boost::unique_lock<boost::mutex> guard(object->mutex);
        object->queue.push(value);
    }
    completion->finish();
}
