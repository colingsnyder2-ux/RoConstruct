// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

inline void add_ref(volatile long* count)
{
    _InterlockedExchangeAdd(count, 1);
}

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Empty {};

struct Iterator {
    void* owner;
    char* current;
};

struct Result;

struct Helper {
    void* first;
    void* second;
    Control* control;
    void insert(Empty, Result*, char**, int);
};

struct Result {
    void* prefix;
    Helper helper;

    Result(const Result& other);
    ~Result();
};

inline Result::Result(const Result& other)
    : prefix(other.prefix), helper(other.helper)
{
    if (other.helper.control)
        add_ref(&other.helper.control->strong);
}

inline Result::~Result()
{
    if (helper.control) {
        Control* p = helper.control;
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

Result process(Iterator first, Iterator last, Result result)
{
    char* p = first.current;
    char* end = last.current;
    for (; p != end; p += 32) {
        char* current = p;
        result.helper.insert(Empty(), &result, &current, 0);
    }
    return result;
}
