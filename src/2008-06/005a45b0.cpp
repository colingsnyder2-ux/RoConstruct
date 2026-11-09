// from server: 100% by king_originala
struct Control {
    virtual void dispose(int);
    virtual void slot1();
    virtual Control* clone();

    static Control* copy(Control*);
};

inline Control* Control::copy(Control* source) {
    if (source)
        return source->clone();
    return 0;
}

struct Pair {
    void* value;
    Control* control;

    Pair(const Pair&);
    ~Pair();
};

inline Pair::Pair(const Pair& other) {
    Control* source = other.control;
    value = other.value;
    control = Control::copy(source);
}

inline Pair::~Pair() {
    if (control)
        control->dispose(1);
}

struct Receiver {
    virtual void slot0();
    virtual void set(int, const Pair*);
};

struct BadCast {
    unsigned char storage[12];
};

extern char baseType;
extern char workspaceType;
extern char badCastThrowInfo;

extern "C" void* __cdecl runtimeCast(
    void*, long, void*, void*, int);

extern void (__thiscall *constructBadCast)(BadCast*, const char*);

extern "C" __declspec(noreturn) void __stdcall throwException(
    void*, void*);

struct Function {
    unsigned char reserved[68];
    Pair bound;

    void invoke(void*, Receiver*);
    void dispatch(void*, void*, const Pair*);
};

void Function::invoke(void* object, Receiver* receiver) {
    Pair argument(bound);
    receiver->set(1, &argument);

    void* workspace = runtimeCast(
        object, 0, &baseType, &workspaceType, 0);

    if (!workspace) {
        BadCast exception;
        constructBadCast(&exception, "bad cast");
        throwException(&exception, &badCastThrowInfo);
    }

    dispatch(workspace, reinterpret_cast<char*>(receiver) + 4, &argument);
}
