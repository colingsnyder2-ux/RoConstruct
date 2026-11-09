// from server: 100% by king_originala
extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Value
{
    char storage[48];
};

struct Element
{
    virtual ~Element();
};

struct Holder
{
    Element* value;
    Holder(const Value&);
    ~Holder();
    void swap(Holder&);
};

struct Container
{
    unsigned int storage[3];
    Holder* first;
    Holder* last;
    Holder* limit;

    Container(unsigned int);
    ~Container();
};

struct Receiver
{
    virtual ~Receiver();
    virtual void assign(const Container&);
};

struct S
{
    Receiver* receiver;
    void f(Value value);
};

inline void Holder::swap(Holder& other)
{
    if (this != &other)
    {
        Element* p = value;
        value = other.value;
        other.value = p;
    }
}

inline Holder::~Holder()
{
    if (value)
        delete value;
}

void S::f(Value value)
{
    Container items(1);

    if (static_cast<unsigned int>(items.last - items.first) <= 0)
        _invalid_parameter_noinfo();

    Holder* first = items.first;
    Holder(value).swap(*first);

    receiver->assign(items);
}
