// from server: 100% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct String;
extern void (__thiscall *stringCopy)(String*, const String&);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const String&);
    ~String();
};

inline String::String(const String& source)
{
    stringCopy(this, source);
}

inline String::~String()
{
    stringDestroy(this);
}

struct Value {
    String text;
    int tag;
};

struct Argument {
    String text;
    int tag;
    Argument(const Value&);
};

inline Argument::Argument(const Value& source)
    : text(source.text), tag(source.tag)
{
}

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

struct Writer {
    virtual void unused() = 0;
    virtual void write(const String&) = 0;
};

struct S;

struct Object {
    void set(Argument);
    void attach(S*);
};

struct ControlPointer {
    Control* pointer;
    void assign(const ControlPointer&);
};

struct Pair {
    Object* object;
    ControlPointer control;
    ~Pair();
};

inline Pair::~Pair()
{
    if (control.pointer)
        control.pointer->release();
}

struct Manager {
    String lookup(const int*);
};

struct Table {
    Pair* lookup(const int*);
};

extern Pair makePair();
extern void registerType(void (__cdecl*)(), const char*);
extern void registeredFunction();
extern const char registeredName[];
extern Manager* getManager();
extern Value makeValue(const String*);

struct S {
    char padding[0x13c];
    Table table;
    void f(int key, String value);
};

void S::f(int key, String value)
{
    Pair p = makePair();
    Writer* writer = reinterpret_cast<Writer*>(p.object);
    registerType(registeredFunction, registeredName);
    Manager* manager = getManager();
    writer->write(manager->lookup(&key));
    p.object->set(makeValue(&value));
    p.object->attach(this);
    Pair* destination = table.lookup(&key);
    destination->object = p.object;
    destination->control.assign(p.control);
}
