// from server: 100% by king_originala
struct Result {
    int value;
    Result(const Result&);
    ~Result();
};

struct ArgumentBase {
    char data[1];
};

struct Argument {
    char padding[20];
    ArgumentBase base;
};

struct GuardState {
    int value;
    int flag;

    GuardState();
    ~GuardState();
};

inline GuardState::GuardState() : value(0), flag(0)
{
}

struct Guard {
    GuardState state;
    int count;

    Guard(int);
    void initialize(int);
    ~Guard();
};

inline Guard::Guard(int source) : count(0)
{
    initialize(source);
}

struct Provider {
    char padding[0x198];
    int source;
};

struct Receiver {
    Result get(ArgumentBase*);
};

struct S {
    char padding[0x128];
    Provider* provider;
    Receiver* receiver;

    Result f(Argument*);
};

Result S::f(Argument* argument)
{
    Guard guard(provider->source);
    return receiver->get(argument ? &argument->base : 0);
}
