// from server: 100% by king_originala
struct Value {
    unsigned char data[32];
    Value(const Value&);
    ~Value();
};

struct Argument {
    Value value;
    int extra;
};

struct Base {
    unsigned char data[32];
    Base(Argument, int);
    ~Base();
};

struct Pair {
    int first;
    int second;
    Pair(int, int);
};

inline Pair::Pair(int a, int b) : first(a), second(b) {}

struct FlaggedPair {
    int first;
    int second;
    bool flag;
    FlaggedPair(int, int);
};

inline FlaggedPair::FlaggedPair(int a, int b)
    : first(a), second(b), flag(false) {}

struct FlaggedValues {
    int first;
    int second;
    int third;
    int fourth;
    bool flag;
    FlaggedValues(int, int, int, int);
};

inline FlaggedValues::FlaggedValues(int a, int b, int c, int d)
    : first(a), second(b), third(c), fourth(d), flag(false) {}

struct S : Base {
    Pair first;
    FlaggedPair second;
    FlaggedValues third;

    S(int, int, int, int, Argument);
    void finish();
};

S::S(int a, int b, int c, int d, Argument argument)
    : Base(argument, 0),
      first(a, b),
      second(a, b),
      third(a, b, c, d)
{
    finish();
}
