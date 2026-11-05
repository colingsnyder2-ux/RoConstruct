// from server: 100% by king_originala
struct String;
typedef const char *(__thiscall *StringData)(const String *);
typedef void (__thiscall *StringDestroy)(String *);

extern StringData stringData;
extern StringDestroy stringDestroy;

struct String {
    unsigned char storage[28];
    ~String();
};

inline String::~String()
{
    stringDestroy(this);
}

extern void *__cdecl writeText(void *, const char *);
extern const char text81cb54[];
extern const char text81cbcc[];
extern const char text81cb40[];

bool __stdcall f(void *stream, String text)
{
    writeText(writeText(stream, text81cb54), stringData(&text));
    writeText(stream, text81cbcc);
    writeText(stream, text81cb40);
    writeText(stream, text81cbcc);
    return false;
}
