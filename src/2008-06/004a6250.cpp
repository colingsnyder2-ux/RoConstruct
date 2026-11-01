// from server: 100% by king_originala
struct String;
extern void (__thiscall *string_construct)(String *, const char *);

struct String {
    unsigned char data[28];
    String(const char *text) { string_construct(this, text); }
    ~String();
};

struct RuntimeError {
    unsigned char data[40];
    RuntimeError(const String &message);
    RuntimeError(const RuntimeError &other);
    ~RuntimeError();
};

struct BitStream {
    bool readBits(unsigned char *destination, int count, bool align);
};

BitStream &readInt(BitStream &stream, int &value)
{
    if (!stream.readBits(reinterpret_cast<unsigned char *>(&value), 32, true))
        throw RuntimeError(String("BitStream >> int failed"));
    return stream;
}
