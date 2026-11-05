// from server: 100% by colin
typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor stringConstructor;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        unsigned int allocator_storage;
        union {
            T buffer[16];
            T* pointer;
        };
        unsigned int length;
        unsigned int capacity;
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    __forceinline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        stringConstructor(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        const char* message;
        int owns_message;
    public:
        exception();
        exception(const exception&);
        virtual ~exception();
        virtual const char* what() const;
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string&);
        runtime_error(const runtime_error&);
        virtual ~runtime_error();
        virtual const char* what() const;
    };
}

struct Stream {
    bool read(void*, int, bool);
};

Stream& readLong(Stream& stream, long& value)
{
    if (!stream.read(&value, 32, true)) {
        std::string message("BitStream >> size_t failed");
        throw std::runtime_error(message);
    }
    return stream;
}
