// from server: 100% by king_originala
extern void (__thiscall *stringConstruct)(void*, const char*);

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Alloc>
    class basic_string {
    public:
        unsigned allocator_data;
        union {
            T buffer[16];
            T* pointer;
        };
        unsigned length;
        unsigned capacity;

        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Alloc>
    __forceinline basic_string<T, Traits, Alloc>::basic_string(const T* text)
    {
        stringConstruct(this, text);
    }
}

typedef std::basic_string<char, std::char_traits<char>, std::allocator<char> > String;

struct Error {
    char storage[40];
    Error(const String&);
    Error(const Error&);
    ~Error();
};

struct Stream {
    void writeBits(const unsigned*, int, bool);
};

struct Encoder {
    void write(const char*, unsigned, Stream*, int);
};

extern Encoder* __cdecl getEncoder();

Stream* __cdecl writeString(Stream* stream, const String& text)
{
    if (text.length > 200000) {
        String message("BitStream string write: String too long");
        throw Error(message);
    }

    unsigned length = text.length;
    stream->writeBits(&length, 32, true);

    unsigned count = text.length;
    const char* data;
    if (text.capacity >= 16)
        data = text.pointer;
    else
        data = text.buffer;

    getEncoder()->write(data, count + 1, stream, 0);
    return stream;
}
