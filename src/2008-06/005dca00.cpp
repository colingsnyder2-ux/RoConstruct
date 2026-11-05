// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Shared {
    void* object;
    Control* control;

    ~Shared()
    {
        if (control)
            control->release();
    }
};

struct First {
    unsigned int data[3];
};

namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        char allocatorStorage[4];
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;
    public:
        __declspec(dllimport) basic_string(const T*);
        __declspec(dllimport) ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct ArgumentError {
    char storage[40];
    ArgumentError(const String&);
    ~ArgumentError();
};

extern unsigned char instanceType;
extern unsigned char partType;
extern unsigned char exceptionType;

extern "C" void* __cdecl castObject(void*, int, const void*, const void*, int);
extern "C" __declspec(noreturn) void __cdecl throwObject(void*, const void*);

struct S {
    void invoke(First first, Shared part);
    void dispatch(First*, void*);
};

void S::invoke(First first, Shared part)
{
    void* value = castObject(part.object, 0, &instanceType, &partType, 0);
    if (!value) {
        String message("Argument error: A Part is required");
        ArgumentError error(message);
        throwObject(&error, &exceptionType);
    }
    dispatch(&first, value);
}
