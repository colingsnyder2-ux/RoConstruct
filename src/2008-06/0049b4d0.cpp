// from server: 100% by king_originala
struct Holder {
    virtual ~Holder();
    virtual void reserved();
    virtual Holder* clone();

    static Holder* copy(Holder*);
};

__forceinline Holder* Holder::copy(Holder* h)
{
    if (h)
        return h->clone();
    return 0;
}

struct Value {
    void* object;
    Holder* holder;

    Value(const Value&);
    ~Value();
};

__forceinline Value::Value(const Value& other)
    : object(other.object), holder(Holder::copy(other.holder))
{
}

__forceinline Value::~Value()
{
    Holder* h = holder;
    if (h)
        delete h;
}

struct Arguments {
    virtual void reserved();
    virtual void get(int index, Value* value);
};

namespace std {
    struct bad_cast {
        char storage[12];
        bad_cast(const char*);
    };
}

typedef void (__thiscall *BadCastConstructor)(std::bad_cast*, const char*);
extern BadCastConstructor constructBadCast;

__forceinline std::bad_cast::bad_cast(const char* message)
{
    constructBadCast(this, message);
}

extern unsigned char sourceType;
extern unsigned char destinationType;
extern unsigned char badCastThrowInfo;

extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

extern "C" __declspec(noreturn) void __stdcall throwException(void*, void*);

struct S {
    char padding[64];
    Value first;
    Value second;

    void invoke(void*, void*, Value*, Value*);
    void f(void*, Arguments*);
};

void S::f(void* instance, Arguments* arguments)
{
    Value a(first);
    arguments->get(1, &a);

    Value b(second);
    arguments->get(2, &b);

    void* converted = __RTDynamicCast(
        instance, 0, &sourceType, &destinationType, 0);

    if (!converted) {
        std::bad_cast error("bad cast");
        throwException(&error, &badCastThrowInfo);
    }

    invoke(converted, reinterpret_cast<char*>(arguments) + 4, &a, &b);
}
