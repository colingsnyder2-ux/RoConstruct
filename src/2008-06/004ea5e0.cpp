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
};

struct Shared {
    void* pointer;
    Control* control;
    ~Shared();
};

inline Shared::~Shared()
{
    Control* p = control;
    if (p && _InterlockedDecrement(&p->strong) == 0) {
        p->dispose();
        if (_InterlockedDecrement(&p->weak) == 0)
            p->destroy();
    }
}

extern char instanceType;
extern char decalType;
extern char shapeType;

extern "C" void* __cdecl castObject(
    void*, long, const void*, const void*, int);

struct S;
struct Callback;
struct Function;

struct Signal {
    char storage;
};

struct DecalPadding {
    char padding[20];
};

struct Decal : DecalPadding, Signal {
};

struct Result {
    unsigned int reserved;
    unsigned int first;
    unsigned int second;
    unsigned char flag;
    ~Result();
};

struct Connection {
    char storage[16];
    Connection& operator=(const Result&);
};

struct Manager {
    Result connect(void*, const Function&, int);
};

extern Manager manager;

struct S {
    char padding[168];
    Connection connection;
    char remaining[28];
    Decal* decal;

    void f(Shared);
    void callback();
    void update();
    void refresh();
};

struct Callback {
    void (S::*method)();
    S* object;
};

struct Function {
    char storage[40];
    Function(const Callback&);
    ~Function();
};

void S::f(Shared value)
{
    Decal* object = static_cast<Decal*>(castObject(
        value.pointer, 0, &instanceType, &decalType, 0));

    if (object) {
        decal = object;
        Callback callbackValue = { &S::callback, this };
        {
            Function function(callbackValue);
            connection = manager.connect(static_cast<Signal*>(object), function, 10);
        }
        update();
    }

    if (castObject(value.pointer, 0, &instanceType, &shapeType, 0)) {
        update();
        refresh();
    }
}
