// from server: 100% by king_originala
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern "C" __declspec(noreturn) void __stdcall ThrowObject(void*, void*);

namespace std {
    struct bad_cast {
        char storage[12];
        bad_cast(const char*);
    };
}

extern void (__thiscall *badCastConstructor)(std::bad_cast*, const char*);

__forceinline std::bad_cast::bad_cast(const char* message) {
    badCastConstructor(this, message);
}

struct Value {
    virtual ~Value();
    virtual void unused();
    virtual Value* clone();
};

__forceinline Value* cloneValue(Value* value) {
    if (value)
        return value->clone();
    return 0;
}

struct Argument {
    void* value;
    Value* owner;

    Argument(void*, Value*);
    ~Argument();
};

__forceinline Argument::Argument(void* p, Value* q) : value(p) {
    owner = cloneValue(q);
}

__forceinline Argument::~Argument() {
    if (owner)
        delete owner;
}

struct Input {
    virtual void unused();
    virtual void get(int, Argument*);
};

struct S {
    char padding[64];
    void* value;
    Value* owner;

    void invoke(void*, void*, Argument*);
    void f(void*, Input*);
};

void S::f(void* object, Input* input) {
    Argument argument(value, owner);
    input->get(1, &argument);

    void* result = __RTDynamicCast(
        object, 0,
        reinterpret_cast<void*>(0x9291fc),
        reinterpret_cast<void*>(0x92e8a0),
        0);

    if (!result) {
        std::bad_cast error("bad cast");
        ThrowObject(&error, reinterpret_cast<void*>(0x8d362c));
    }

    invoke(result, reinterpret_cast<char*>(input) + 4, &argument);
}
