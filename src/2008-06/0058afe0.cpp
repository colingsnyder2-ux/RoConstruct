// from server: 60% by king_originala
namespace std {
    template<class T> struct char_traits {};
    template<class T> struct allocator {};

    template<class T, class Traits, class Alloc>
    class basic_string {
        unsigned char storage[28];
    public:
        basic_string(const basic_string&);
        ~basic_string();
    };
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Owned {
    virtual ~Owned();
};

struct Guard {
    volatile unsigned char prefix[4];
    Owned* volatile pointer;
    volatile unsigned char padding[12];
    Guard(Owned*);
    ~Guard();
};

Guard::Guard(Owned* p) : pointer(p)
{
}

Guard::~Guard()
{
    Owned* p = pointer;
    if (p)
        delete p;
}

struct Object;

#pragma pointers_to_members(full_generality, multiple_inheritance)

struct Bound {
    unsigned char padding[56];
    void (Object::*method)(String);
    void invoke(Object*, const String*);
};

struct Object : Owned {
    void accept(String);
};

void Bound::invoke(Object* object, const String* argument)
{
    Guard guard(object);
    (object->*method)(*argument);
}
