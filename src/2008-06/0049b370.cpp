// from server: 60% by king_originala
#pragma pointers_to_members(full_generality, multiple_inheritance)

namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Alloc>
class basic_string {
    unsigned char storage[28];
public:
    basic_string(const basic_string&);
    ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

struct Object {
    virtual ~Object();
};

struct Guard {
    unsigned char prefix[4];
    Object* object;
    unsigned char storage[12];
    ~Guard();
};

Guard::~Guard()
{
    Object* p = *reinterpret_cast<Object* volatile*>(&object);
    if (p)
        delete p;
}

struct BoundFuncDesc {
    unsigned char padding[56];
    void (Object::*callback)(std::string);
    void invoke(Object*, const std::string&);
};

void BoundFuncDesc::invoke(Object* object, const std::string& value)
{
    Guard guard;
    guard.object = object;
    (object->*callback)(value);
}
