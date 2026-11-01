// from server: 100% by colin
struct Flag {
    bool value;
    Flag(const Flag &other) : value(other.value) {}
};

struct Callback {
    virtual void invoke(void *, Flag) = 0;
};

struct S {
    char unused;
    __declspec(noreturn) void f(Flag, Callback *);
};

void S::f(Flag flag, Callback *callback)
{
    volatile char scratch[40];
    try {
        void *object = 0;
        if (this)
            object = reinterpret_cast<char *>(this) - 0x1a0;
        callback->invoke(object, flag);
        __assume(0);
    }
    catch (...) {
        scratch[0] = 0;
    }
}