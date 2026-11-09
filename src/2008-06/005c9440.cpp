// from server: 100% by king_originala
typedef unsigned int size_t;

void* __cdecl operator new(size_t);
extern "C" void (__cdecl* invalid_parameter_noinfo)();
extern "C" void* __cdecl doubleType();
extern "C" void* __cdecl integerType();

struct Holder {
    virtual ~Holder();
};

struct DoubleHolder : Holder {
    double value;
    DoubleHolder(double);
};

struct IntegerHolder : Holder {
    int value;
    IntegerHolder(const int&);
};

inline DoubleHolder::DoubleHolder(double x) : value(x) {}
inline IntegerHolder::IntegerHolder(const int& x) : value(x) {}

struct Owner {
    Holder* pointer;

    explicit Owner(Holder*);
    Owner& operator=(const Owner&);
};

inline Owner::Owner(Holder* p) : pointer(p) {}

inline Owner& Owner::operator=(const Owner& other)
{
    Holder* p = other.pointer;
    if (&other != this) {
        p = pointer;
        pointer = other.pointer;
    }
    if (p)
        delete p;
    return *this;
}

struct Entry {
    void* type;
    Owner value;
};

struct Values {
    unsigned char reserved[12];
    Entry* first;
    Entry* last;
    Entry* limit;

    Values(unsigned int);
    ~Values();
};

struct Sample {
    double first;
    double second;
    int third;
};

struct Source {
    Sample sample(double);
};

struct LaserTool {
    unsigned char reserved[0x158];
    Source* source;

    Values evaluate(double);
};

Values LaserTool::evaluate(volatile double time)
{
    Sample data = source->sample(time);
    Values result(3);
    double value = data.second;
    void (__cdecl* invalid)() = invalid_parameter_noinfo;

    if (static_cast<unsigned int>(result.last - result.first) <= 0)
        invalid();

    Entry* entry = result.first;
    entry->type = doubleType();
    Owner* destination = &entry->value;
    *destination = Owner(new DoubleHolder(value));

    value = data.first;
    if (static_cast<unsigned int>(result.last - result.first) <= 1)
        invalid();

    entry = result.first + 1;
    entry->type = doubleType();
    destination = &entry->value;
    *destination = Owner(new DoubleHolder(value));

    if (static_cast<unsigned int>(result.last - result.first) <= 2)
        invalid();

    entry = result.first + 2;
    entry->type = integerType();
    destination = &entry->value;
    *destination = Owner(new IntegerHolder(data.third));

    return result;
}
