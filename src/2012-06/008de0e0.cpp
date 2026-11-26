// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
#include <limits>
void __cdecl callOnce(int* flag, void (*fn)());
extern int g_onceFlag;
void onceFn();
namespace boost {
namespace date_time {
enum special_values { not_a_date_time, neg_infin, pos_infin, min_date_time, max_date_time, not_special, NumSpecialValues };
template<typename int_type_>
class int_adapter {
public:
    typedef int_type_ int_type;
    int_adapter(int_type v) : value_(v) {}
    static const int_adapter pos_infinity() { return (::std::numeric_limits<int_type>::max)(); }
    static const int_adapter neg_infinity() { return (::std::numeric_limits<int_type>::min)(); }
    static const int_adapter not_a_number() { return (::std::numeric_limits<int_type>::max)() - 1; }
    static int_adapter max() { return (::std::numeric_limits<int_type>::max)() - 2; }
    static int_adapter min() { return (::std::numeric_limits<int_type>::min)() + 1; }
    static int_adapter from_special(special_values sv)
    {
        switch (sv) {
        case not_a_date_time: return not_a_number();
        case neg_infin: return neg_infinity();
        case pos_infin: return pos_infinity();
        case max_date_time: return (max)();
        case min_date_time: return (min)();
        default: return not_a_number();
        }
    }
    int_type as_number() const { return value_; }
private:
    int_type value_;
};
}
namespace gregorian {
class date {
public:
    typedef date_time::int_adapter<unsigned int> date_rep_type;
    date(int y, int m, int d);
    explicit date(date_rep_type days) : days_(days.as_number()) {}
    date(date_time::special_values sv) : days_(date_rep_type::from_special(sv).as_number())
    {
        if (sv == date_time::min_date_time) { *this = date(1400, 1, 1); }
        if (sv == date_time::max_date_time) { *this = date(9999, 12, 31); }
    }
    unsigned int days_;
};
}
namespace posix_time {
class time_duration {
public:
    typedef date_time::int_adapter<__int64> impl_type;
    time_duration(int h, int m, int s, int f);
    time_duration(date_time::special_values sv) : ticks_(impl_type::from_special(sv)) {}
    impl_type ticks_;
};
struct counted_time_rep {
    __declspec(noinline) counted_time_rep(const gregorian::date& d, const time_duration& time_of_day) : time_count_(1) { if (d.days_ == 0xffffffffu || time_of_day.ticks_.as_number() > 100) time_count_ = time_of_day.ticks_.as_number() + d.days_; else time_count_ = d.days_ * 86400000000LL + time_of_day.ticks_.as_number(); }
    date_time::int_adapter<__int64> time_count_;
};
struct counted_time_system {
    typedef counted_time_rep time_rep_type;
    static time_rep_type get_time_rep(date_time::special_values sv)
    {
        switch (sv) {
        case date_time::not_a_date_time:
        default:
            return time_rep_type(gregorian::date(date_time::not_a_date_time), time_duration(date_time::not_a_date_time));
        case date_time::pos_infin:
            return time_rep_type(gregorian::date(date_time::pos_infin), time_duration(date_time::pos_infin));
        case date_time::neg_infin:
            return time_rep_type(gregorian::date(date_time::neg_infin), time_duration(date_time::neg_infin));
        case date_time::max_date_time: {
            time_duration td = time_duration(24, 0, 0, 0);
            return time_rep_type(gregorian::date(date_time::max_date_time), td);
        }
        case date_time::min_date_time:
            return time_rep_type(gregorian::date(date_time::min_date_time), time_duration(0, 0, 0, 0));
        }
    }
};
template<class T, class time_system>
class base_time {
public:
    base_time(date_time::special_values sv) : time_(time_system::get_time_rep(sv)) {}
protected:
    typename time_system::time_rep_type time_;
};
class ptime : public base_time<ptime, counted_time_system> {
public:
    ptime(date_time::special_values sv) : base_time<ptime, counted_time_system>(sv) {}
};
}
typedef posix_time::ptime system_time;
namespace detail {
inline system_time get_system_time_sentinel() { return system_time(date_time::pos_infin); }
struct basic_timed_mutex {
    long active_count;
    void* event;
    bool timed_lock(const system_time& wait_until);
    void lock() { timed_lock(get_system_time_sentinel()); }
};
}
class mutex : public detail::basic_timed_mutex {
public:
    mutex() { active_count = 0; event = 0; }
    ~mutex();
};
template<typename Mutex>
class unique_lock {
    Mutex* m;
    bool is_locked;
public:
    explicit unique_lock(Mutex& m_) : m(&m_) { lock(); }
    void lock() { m->lock(); is_locked = true; }
    ~unique_lock();
};
}
template<class T> struct IPtr {
    T* p;
    IPtr() : p(0) {}
    ~IPtr();
    IPtr& operator=(const IPtr& o);
    T* get() const { return p; }
    T* operator->() const { return p; }
    operator bool() const { return p != 0; }
};
struct Signal;
struct Slot { void* vt; int x; void* vt2; IPtr<Slot> next; Signal* sig; };
struct Signal {
    IPtr<Slot> head;
    static boost::mutex& mutex() { callOnce(&g_onceFlag, &onceFn); static boost::mutex m; return m; }
    void disconnectAll();
};
void Signal::disconnectAll()
{
    while (head) {
        IPtr<Slot> s;
        {
            boost::unique_lock<boost::mutex> lock(mutex());
            int n = 10;
            s = head;
            while (Slot* p = s.get()) {
                p->sig = 0;
                if (n-- == 0) break;
                s = p->next;
            }
        }
        head = s;
    }
}



