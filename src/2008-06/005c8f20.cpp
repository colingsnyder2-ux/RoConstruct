// from server: 100% by king_originala
namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        ~basic_string();
        basic_string& operator=(const basic_string&);
    };
}

typedef std::basic_string<char, std::char_traits<char>,
                          std::allocator<char> > String;

extern void (__thiscall *destroyString)(String*);
extern String& (__thiscall *assignString)(String*, const String&);

namespace std {
    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::~basic_string()
    {
        destroyString(this);
    }

    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>&
    basic_string<T, Traits, Allocator>::operator=(const basic_string& other)
    {
        return assignString(this, other);
    }
}

struct S {
    char reserved[0x130];
    double value;
    String text;
};

String __cdecl formatText(const char*, char*);

static __forceinline void setText(S* object, double value,
                                 const String& text)
{
    object->value = value;
    object->text = text;
}

void __cdecl f(S* object, double value, const char* format, ...)
{
    setText(object, value, formatText(format, (char*)(&format + 1)));
}
