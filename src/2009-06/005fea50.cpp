// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <deque>
struct Ptr {
    void* px; void* pn;
    Ptr(const Ptr&);
    Ptr& operator=(const Ptr&);
    ~Ptr();
};
struct Item {
    int id;
    Ptr p;
};
template<> void std::deque<Item>::pop_front();
class mutex { public: void* h; };
class scoped_lock {
public:
    explicit scoped_lock(mutex& m);
    ~scoped_lock();
    void* m;
};
template<class T> class SafeQueue {
public:
    std::deque<T> queue;
    mutex m;
    bool pop(T& out)
    {
        scoped_lock lock(m);
        if (!queue.empty())
        {
            out = queue.front();
            queue.pop_front();
            return true;
        }
        return false;
    }
};
template class SafeQueue<Item>;
