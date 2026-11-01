// from server: 100% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Function {
    typedef void (__cdecl *Manager)(const void*, void*, int);
    struct Table {
        Manager manage;
    };

    const Table* table;
    unsigned int reserved;
    unsigned char storage[24];

    Function(const Function&);
    ~Function();
};

inline Function::Function(const Function& other) : table(0) {
    if (other.table) {
        table = other.table;
        other.table->manage(other.storage, storage, 0);
    }
}

inline Function::~Function() {
    if (table) {
        Manager manager = table->manage;
        if (manager)
            manager(storage, storage, 1);
    }
}

struct String {
    unsigned char storage[28];

    String(const char*);
    ~String();
};

extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

inline String::String(const char* text) {
    stringConstruct(this, text);
}

inline String::~String() {
    stringDestroy(this);
}

struct Descriptor;

struct Object {
    virtual void slot0();
    virtual void setName(const String&);
    void bind(Descriptor*);
};

struct Control {
    virtual void slot0();
    virtual void dispose();
    virtual void destroy();

    volatile long strong;
    volatile long weak;

    void release();
};

inline void Control::release() {
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct Result {
    Object* pointer;
    Control* control;

    ~Result();
};

inline Result::~Result() {
    if (control)
        control->release();
}

Result __cdecl makeResult(Function);

struct Shared {
    Object* pointer;
    Control* control;

    Shared(const Result&);
    ~Shared();
};

inline Shared::Shared(const Result& result)
    : pointer(result.pointer), control(result.control) {
    if (control)
        _InterlockedIncrement(&control->strong);
}

inline Shared::~Shared() {
    if (control)
        control->release();
}

struct Descriptor {
    Object* create(const char*, Function);
};

Object* Descriptor::create(const char* name, Function function) {
    Shared object(makeResult(function));
    {
        String text(name);
        object.pointer->setName(text);
    }
    object.pointer->bind(this);
    return object.pointer;
}
