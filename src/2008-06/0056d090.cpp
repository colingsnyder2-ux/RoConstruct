// from server: 100% by king_originala
class type_info;
extern bool (__thiscall *type_equal)(const type_info*, const type_info&);

class type_info {
public:
    bool __thiscall operator==(const type_info&) const;
};

__forceinline bool type_info::operator==(const type_info& other) const
{
    return type_equal(this, other);
}

extern const type_info void_type;
extern const type_info objects_type;

namespace std {
    template<class T> struct char_traits {};
    template<class T> class allocator {};

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned char allocator_storage[4];
        union {
            T buffer[16];
            T* pointer;
        } storage;
        unsigned int length;
        unsigned int capacity;

    public:
        basic_string(const T*);
        basic_string(const basic_string&);
        ~basic_string();
    };

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        char* message;
        int owns_message;

    public:
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception {
        string text;

    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

extern void (__thiscall *string_construct)(std::string*, const char*);

template<>
__forceinline std::basic_string<char, std::char_traits<char>, std::allocator<char> >::
basic_string(const char* text)
{
    string_construct(this, text);
}

struct Placeholder {
    virtual ~Placeholder();
    virtual const type_info& type() const;
};

struct Any {
    Placeholder* content;
};

struct S {
    unsigned int prefix;
    Any value;

    void* f();
};

void* S::f()
{
    Any* p = &value;
    if (p) {
        const type_info& t = p->content ? p->content->type() : void_type;
        if (t == objects_type) {
            void* result = reinterpret_cast<char*>(p->content) + 4;
            if (result)
                return result;
        }
    }

    throw std::runtime_error(std::string("Unable to cast value to Objects"));
}
