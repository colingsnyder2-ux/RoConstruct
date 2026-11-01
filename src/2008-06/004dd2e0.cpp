// from server: 100% by Espeon
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
// from server: 84% by king_originala
struct Base
{
    unsigned int first;
    unsigned int second;

    Base();
    virtual ~Base();
};

inline Base::Base() : first(0), second(0)
{
    _ReadWriteBarrier();
}

struct Pair
{
    unsigned int first;
    unsigned int second;

    Pair();
    ~Pair();
};

inline Pair::Pair() : first(0), second(0)
{
    if (first)
        throw 0;
}

struct S : Base
{
    unsigned int field0c;
    Pair field10;
    unsigned int field18;
    bool field1c;
    int field20;
    unsigned int field24;

    S(unsigned int value);
    virtual ~S();
};

S::S(unsigned int value) : field18(value),field1c(true),field20(-1)
{
    field0c=0;
    field24=0;
}
