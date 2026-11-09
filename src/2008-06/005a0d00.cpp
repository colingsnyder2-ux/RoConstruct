// from server: 100% by colin
// roc-cl 21022
// roc-flags /O2 /GS /EHsc /MD

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Shared {
    void* object;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p) {
        if (_InterlockedDecrement(&p->strong) == 0) {
            p->dispose();
            if (_InterlockedDecrement(&p->weak) == 0)
                p->destroy();
        }
    }
}

namespace std {
    template<class _Elem>
    class char_traits {
    };

    template<class _Ty>
    class allocator {
    };

    template<class _Elem, class _Traits, class _Alloc>
    class basic_string {
        char _data[28];
    public:
        __declspec(dllimport) ~basic_string();
    };
}

struct String {
    std::basic_string<char, std::char_traits<char>, std::allocator<char> > data;
    ~String();
};

inline String::~String()
{
}

struct Base {
    char storage[28];
    ~Base();
};

struct S : Base {
    Shared shared;
    char padding[8];
    String text;
    ~S();
};

S::~S()
{
}
