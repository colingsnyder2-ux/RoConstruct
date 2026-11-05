// from server: 100% by king_originala
struct Control {
    virtual ~Control();
    virtual void reserved() = 0;
    virtual Control* clone() = 0;
};

struct Value {
    unsigned int value;
    Control* control;

    Value(unsigned int, Control*);
    ~Value();
    unsigned char* get();
};

inline Value::Value(unsigned int v, Control* c) : value(v) {
    Control* copy;
    if (c)
        copy = c->clone();
    else
        copy = 0;
    control = copy;
}

inline Value::~Value() {
    if (control)
        delete control;
}

struct Arguments {
    virtual void reserved() = 0;
    virtual void set(int, Value*) = 0;
};

struct BadCast {
    void* table;
    const char* message;
    int owned;
};

extern "C" BadCast* (__thiscall *constructBadCast)(BadCast*, const char*);
extern "C" void* __cdecl runtimeCast(void*, int, const void*, const void*, int);
extern "C" __declspec(noreturn) void __stdcall throwException(void*, const void*);

extern const unsigned char sourceType[];
extern const unsigned char destinationType[];
extern const unsigned char badCastThrowInfo[];

struct Base {
    unsigned char unused;
};

struct Component : virtual Base {
    void set(unsigned int);
};

struct Workspace {
    unsigned char padding[0x134];
    Component component;
};

struct Descriptor {
    typedef void (Component::*Function)(unsigned int);

    unsigned char padding[0x38];
    Function function;
    unsigned int value;
    Control* control;

    void invoke(void*, Arguments*);
};

void Descriptor::invoke(void* object, Arguments* arguments) {
    Value argument(value, control);
    arguments->set(1, &argument);

    Workspace* workspace = static_cast<Workspace*>(
        runtimeCast(object, 0, sourceType, destinationType, 0));

    if (!workspace) {
        BadCast exception;
        constructBadCast(&exception, "bad cast");
        throwException(&exception, badCastThrowInfo);
    }

    (workspace->component.*function)(*argument.get());
}
