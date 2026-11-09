// from server: 100% by colin
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;
    template<class T, class Traits, class Alloc>
    class __declspec(dllimport) basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };
    typedef basic_string<char, char_traits<char>, allocator<char> > string;
}





struct Result {
    void* value;
    Result();
};

struct Receiver {
    Result apply(std::string);
};

struct Object {
    char padding[16];
    Receiver receiver;
};

struct Binder {
    Object* lookup(void*);
    void invoke(void*, std::string);
};

void Binder::invoke(void* value, std::string text)
{
    Object* object = lookup(value);
    if (object)
        object->receiver.apply(text);
}
