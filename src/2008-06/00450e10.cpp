// from server: 57% by king_originala
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __cdecl sprintf(char*, const char*, ...);

struct Control {
    virtual void reserved();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Value {
    double fraction();
};

struct Result {
    Value* value;
    Control* control;

    Result(const Result&);
    ~Result();
    void clear();
};

inline Result::Result(const Result& other)
{
    value = other.value;
    control = other.control;
    if (control)
        _InterlockedExchangeAdd(&control->strong, 1);
}

inline Result::~Result()
{
    if (control) {
        if (_InterlockedExchangeAdd(&control->strong, -1) == 1) {
            control->dispose();
            if (_InterlockedExchangeAdd(&control->weak, -1) == 1)
                control->destroy();
        }
    }
}

struct Holder {
    Value* value;
    Control* control;

    Holder(Result);
    ~Holder();
};

inline Holder::Holder(Result other)
{
    value = other.value;
    control = other.control;
    if (control)
        _InterlockedExchangeAdd(&control->strong, 1);
}

struct Output {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void setText(const char*);
};

struct S {
    Result* copy(Result*);
    void f(Output*);
};

void S::f(Output* output)
{
    union Storage {
        void* alignment;
        char bytes[8];
    };
    Storage initialStorage;
    Result* initial = reinterpret_cast<Result*>(&initialStorage);
    Holder holder(*copy(initial));
    initial->clear();

    double percentage;
    {
        Storage currentStorage;
        Result* current = reinterpret_cast<Result*>(&currentStorage);
        percentage = copy(current)->value->fraction() * 100.0;
        current->~Result();
    }

    char text[32];
    sprintf(text, "%.3g%%", percentage);
    output->setText(text);
}
