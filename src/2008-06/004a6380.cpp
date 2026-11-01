// from server: 100% by king_originala
namespace std {
template<class T> struct char_traits;
template<class T> class allocator;

template<class T, class Traits, class Alloc>
class basic_string {
    unsigned char storage[28];
public:
    basic_string(const T *);
    ~basic_string();
};

typedef basic_string<char, char_traits<char>, allocator<char> > string;
}

typedef void (__thiscall *StringConstructor)(void *, const char *);
extern StringConstructor importedStringConstructor;

namespace std {
template<class T, class Traits, class Alloc>
__forceinline basic_string<T, Traits, Alloc>::basic_string(const T *text)
{
    importedStringConstructor(this, text);
}
}

struct Error {
    unsigned char storage[40];
    Error(const std::string &);
    Error(const Error &);
    ~Error();
};

struct Stream {
    bool readBits(unsigned char *, int, bool);
};

Stream &readByte(Stream &stream, unsigned char &value)
{
    if (!stream.readBits(&value, 8, true)) {
        std::string message("BitStream >> unsigned char failed");
        throw Error(message);
    }
    return stream;
}
