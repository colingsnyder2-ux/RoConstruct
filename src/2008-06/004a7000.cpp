// from server: 100% by king_originala
typedef void (__thiscall *StringConstructor)(void*, const char*);
extern StringConstructor constructString;

namespace std {
    template<class T> struct char_traits;
    template<class T> class allocator;

    template<class T, class Traits, class Allocator>
    class basic_string {
        char storage[28];
    public:
        basic_string(const T*);
        ~basic_string();
    };

    template<class T, class Traits, class Allocator>
    inline basic_string<T, Traits, Allocator>::basic_string(const T* text)
    {
        constructString(this, text);
    }

    typedef basic_string<char, char_traits<char>, allocator<char> > string;

    class exception {
        char* message;
        bool owned;
    public:
        virtual ~exception();
    };

    class runtime_error : public exception {
        string message;
    public:
        runtime_error(const string&);
        virtual ~runtime_error();
    };
}

struct BitStream {
    bool readBits(unsigned char*, int, bool);
};

struct BrickColor {
    int value;
};

struct Palette {
    char storage[12];
    BrickColor* first;
    BrickColor* last;
    BrickColor* limit;
};

extern const Palette& __cdecl colorPalette();

typedef void (__cdecl *InvalidParameterHandler)();
extern InvalidParameterHandler invalidParameter;

BitStream& __cdecl readBrickColor(BitStream& stream, BrickColor& color)
{
    unsigned int index = 0;
    if (!stream.readBits(reinterpret_cast<unsigned char*>(&index), 5, true))
        throw std::runtime_error(std::string("BitStream >> BrickColor failed"));

    const unsigned int selected = index;
    const Palette& palette = colorPalette();
    if (selected >= static_cast<unsigned int>(palette.last - palette.first))
        invalidParameter();

    color.value = palette.first[selected].value;
    return stream;
}
