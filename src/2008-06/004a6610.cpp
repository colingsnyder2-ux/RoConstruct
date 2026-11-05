// from server: 100% by king_originala
extern "C" void* __cdecl _alloca(unsigned int);
#pragma intrinsic(_alloca)

struct String;
extern String* (__thiscall* stringConstruct)(String*, const char*);
extern String& (__thiscall* stringAssign)(String*, const char*);

struct String {
    char storage[28];
    String(const char*);
    ~String();
    String& operator=(const char*);
};

inline String::String(const char* text)
{
    stringConstruct(this, text);
}

inline String& String::operator=(const char* text)
{
    return stringAssign(this, text);
}

struct Stream {
    bool readBits(void*, int, bool);
};

struct ReadError {
    char storage[40];
    ReadError(const String&);
    ReadError(const ReadError&);
    ~ReadError();
};

struct Reader {
    void read(char*, unsigned int, Stream*, bool);
};

Reader* __cdecl getReader();

Stream& __cdecl readString(Stream& stream, String& result)
{
    unsigned int length;
    if (!stream.readBits(&length, 32, true))
        throw ReadError(String("BitStream >> std::string: failed to read length"));

    if (length > 200000)
        throw ReadError(String("BitStream >> std::string: Bad string length"));

    unsigned int capacity = length + 1;
    char* buffer = static_cast<char*>(_alloca(capacity));
    getReader()->read(buffer, capacity, &stream, false);
    result = buffer;
    return stream;
}
