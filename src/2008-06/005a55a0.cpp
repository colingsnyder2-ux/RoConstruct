// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

namespace std {
    template<class T> struct char_traits;
    template<class T> struct allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

namespace std {
    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text) {
        stringConstruct(this, text);
    }

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::~basic_string() {
        stringDestroy(this);
    }
}

struct Owner;

struct Object {
    virtual void slot0() = 0;
    virtual void setName(const String&) = 0;
    void attach(Owner*);
};

struct Control {
    virtual void slot0() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
    void addRef();
    void release();
};

inline void Control::addRef() {
    _InterlockedIncrement(&strong);
}

inline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Temporary {
    Object* object;
    Control* control;
    ~Temporary();
};

struct Shared {
    Object* object;
    Control* control;
    Shared(const Temporary&);
    ~Shared();
};

inline Temporary::~Temporary() {
    if (control)
        control->release();
}

inline Shared::Shared(const Temporary& other)
    : object(other.object), control(other.control) {
    if (control)
        control->addRef();
}

inline Shared::~Shared() {
    if (control)
        control->release();
}

struct Function {
    typedef void (__cdecl *Manager)(void*, void*, int);
    Manager* manager;
    unsigned int reserved;
    unsigned char data[24];
    Function(const Function&);
    ~Function();
};

inline Function::Function(const Function& other) : manager(0) {
    if (other.manager) {
        manager = other.manager;
        (*other.manager)(const_cast<unsigned char*>(other.data), data, 0);
    }
}

inline Function::~Function() {
    if (manager) {
        Manager f = *manager;
        if (f)
            f(data, data, 1);
    }
}

Temporary __cdecl createObject(Function);

struct Owner {
    Object* create(const char*, Function);
};

Object* Owner::create(const char* name, Function function) {
    Shared object(createObject(function));
    {
        String text(name);
        object.object->setName(text);
    }
    object.object->attach(this);
    return object.object;
}
