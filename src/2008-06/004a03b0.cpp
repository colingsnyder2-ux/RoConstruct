// from server: 100% by king_originala
typedef unsigned int size_t;

void *__cdecl operator new(size_t);
extern "C" void *__stdcall getSettings(int, int);
extern "C" void *__cdecl getType();

struct Base {
    unsigned char storage[52];
    Base(void *);
    virtual ~Base();
};

struct Value {
    void *type;
    void *data;
    Value();
    ~Value();
};

struct Holder {
    int value;
    Holder(int);
    virtual ~Holder();
};

inline Holder::Holder(int v) : value(v) {}

struct Property {
    void *type;
    Holder *holder;
    Property(int);
    ~Property();
};

inline Property::Property(int v)
    : type(getType()), holder(new Holder(v)) {}

struct S : Base {
    int first;
    int second;
    Value value1;
    Value value2;
    Property property1;
    Property property2;

    S(int, int, int, int, int, int, int, int, int, int);
    virtual ~S();
    void initialize(int, int, int, int);
};

S::S(int a1, int a2, int a3, int a4, int a5,
     int a6, int a7, int a8, int a9, int a10)
    : Base(getSettings(a3, a10)),
      first(a1),
      second(a2),
      property1(a7),
      property2(a9)
{
    initialize(a4, a5, a6, a8);
}
