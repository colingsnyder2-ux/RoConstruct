// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor stringConstructor;

__forceinline String::String(const char *text)
{
    stringConstructor(this, text);
}

struct Error {
    unsigned char storage[40];
    Error(const String &);
    Error(const Error &);
    ~Error();
};

struct Stream {
    bool readBits(void *, int, bool);
};

Stream &readDouble(Stream &stream, double &value)
{
    if (!stream.readBits(&value, 64, true)) {
        String message("BitStream >> double failed");
        throw Error(message);
    }
    return stream;
}
