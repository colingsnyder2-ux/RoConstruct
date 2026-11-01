// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringConstructor)(String *, const char *);
extern StringConstructor constructString;

struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    constructString(this, text);
}

struct ReadError {
    unsigned char storage[40];
    ReadError(const String &);
    ReadError(const ReadError &);
    ~ReadError();
};

struct BitStream {
    bool readBits(unsigned char *, int, bool);
};

BitStream &__cdecl readFloat(BitStream &stream, float &value)
{
    if (!stream.readBits(reinterpret_cast<unsigned char *>(&value), 32, true)) {
        String message("BitStream >> float failed");
        throw ReadError(message);
    }
    return stream;
}
