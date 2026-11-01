// from server: 100% by king_originala
extern "C" void (__cdecl *invalid_parameter_noinfo)();
void * __cdecl operator new(unsigned int);

struct String;
extern "C" void (__thiscall *destroy_string)(String *);

struct String {
    char data[28];
    ~String();
};

inline String::~String()
{
    destroy_string(this);
}

struct Holder {
    virtual ~Holder();
};

struct IntHolder : Holder {
    int value;
    IntHolder(int);
};

struct Owner {
    Holder *pointer;
    Owner(const String &);
    Owner(Holder *);
    ~Owner();
    void swap(Owner &);
};

struct Arguments {
    char prefix[12];
    Owner *first;
    Owner *last;
    Owner *limit;

    Arguments(unsigned int);
    ~Arguments();
};

struct Receiver {
    virtual ~Receiver();
    virtual void invoke(const Arguments &);
};

struct S {
    Receiver *receiver;
    void f(String, int, String);
};

inline IntHolder::IntHolder(int n) : value(n)
{
}

inline Owner::Owner(Holder *p) : pointer(p)
{
}

inline Owner::~Owner()
{
    if (pointer)
        delete pointer;
}

inline void Owner::swap(Owner &other)
{
    if (this != &other) {
        Holder *p = pointer;
        pointer = other.pointer;
        other.pointer = p;
    }
}

void S::f(String a, int b, String c)
{
    Arguments arguments(3);
    void (__cdecl *check)() = invalid_parameter_noinfo;
    {
        if (static_cast<unsigned int>(arguments.last - arguments.first) <= 0)
            check();
        Owner &destination = arguments.first[0];
        Owner(a).swap(destination);
    }
    {
        if (static_cast<unsigned int>(arguments.last - arguments.first) <= 1)
            check();
        Owner &destination = arguments.first[1];
        Owner(new IntHolder(b)).swap(destination);
    }
    {
        if (static_cast<unsigned int>(arguments.last - arguments.first) <= 2)
            check();
        Owner &destination = arguments.first[2];
        Owner(c).swap(destination);
    }
    receiver->invoke(arguments);
}
