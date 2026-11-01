// from server: 100% by king_originala
struct String
{
    unsigned char storage[28];

    String(const String&);
    ~String();
    String& operator+=(const char*);
    String& operator+=(const String&);
};

typedef void (__thiscall *StringDestructor)(String*);
typedef String& (__thiscall *StringAppendText)(String*, const char*);
typedef String& (__thiscall *StringAppendString)(String*, const String&);

extern StringDestructor destroyString;
extern StringAppendText appendText;
extern StringAppendString appendString;

inline String::~String()
{
    destroyString(this);
}

inline String& String::operator+=(const char* text)
{
    return appendText(this, text);
}

inline String& String::operator+=(const String& text)
{
    return appendString(this, text);
}

String __cdecl stringFromNumber(const int&);

String __cdecl formatPair(const short* values)
{
    String result = stringFromNumber(static_cast<int>(values[0]));
    result += ", ";
    result += stringFromNumber(static_cast<int>(values[1]));
    return result;
}
