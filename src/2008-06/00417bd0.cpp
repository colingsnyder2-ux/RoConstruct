// from server: 100% by colin
namespace std {
template<class T> struct char_traits {};
template<class T> struct allocator {};

template<class C, class Traits = char_traits<C>,
         class Alloc = allocator<C> >
struct basic_string {
    char storage[28];
    __declspec(dllimport) ~basic_string();
    __declspec(dllimport) const C* c_str() const;
};
}

struct Lock {
    int value;
    unsigned char flag;
    int count;

    void acquire();
    void release();
};

struct LockGuard {
    Lock* lock;
    bool acquired;

    LockGuard(Lock& value);
    ~LockGuard();
};

inline LockGuard::LockGuard(Lock& value) : lock(&value) {
    lock->acquire();
    acquired = true;
}

inline LockGuard::~LockGuard() {
    if (acquired)
        lock->release();
}

struct Handler {
    void invoke(const char*, int, int, int, int, int);
};

struct S {
    char padding[0x130];
    Lock lock;
    Handler* handler;

    void f(std::basic_string<char> text);
};

void S::f(std::basic_string<char> text) {
    LockGuard guard(lock);
    if (handler)
        handler->invoke(text.c_str(), 0, 0, 0, 0, 0);
}
