// from server: 100% by king_originala
extern "C" void* __stdcall getDescriptor(const char*, int);

struct Base {
    char data[0x34];

    Base(void*);
    virtual ~Base();
};

struct Value {
    unsigned long type;
    unsigned long data;

    Value();
    ~Value();
};

struct S : Base {
    unsigned long first;
    unsigned long second;
    Value value1;
    Value value2;
    Value value3;

    S(unsigned long, unsigned long, const char*, int, int, int, int);
    virtual ~S();
    void initialize(int, int, int);
};

S::S(unsigned long a, unsigned long b, const char* c,
     int d, int e, int f, int g)
    : Base(getDescriptor(c, g)),
      first(a),
      second(b),
      value1(),
      value2(),
      value3()
{
    initialize(d, e, f);
}
