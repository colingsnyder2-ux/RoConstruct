// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> struct allocator;

    template<class T, class Traits, class Alloc>
    struct basic_string {
        unsigned int proxy;
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

        basic_string(const T*);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    struct runtime_error {
        char storage[40];

        runtime_error(const string&);
        runtime_error(const runtime_error&);
        ~runtime_error();
    };
}

extern void (__thiscall *stringConstructor)(std::string*, const char*);

namespace std {
    template<>
    __forceinline string::basic_string(const char* text)
    {
        stringConstructor(this, text);
    }
}

struct PropertyDescriptor;
extern PropertyDescriptor maxItemsProperty;

struct DebrisService {
    char padding[0x150];
    int maxItems;

    void setMaxItems(int);
    void notify(const PropertyDescriptor*);
    void update();
};

void DebrisService::setMaxItems(int value)
{
    if (value != maxItems) {
        if (value < 0)
            throw std::runtime_error(
                std::string("DebrisService MaxItems must be greater than 0"));

        maxItems = value;
        notify(&maxItemsProperty);
        update();
    }
}
