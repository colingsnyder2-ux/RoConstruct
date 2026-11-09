// from server: 60% by king_originala
#pragma optimize("y", off)

struct String
{
    unsigned char data[28];
    String(const char *);
    ~String();
};

struct Sky
{
    ~Sky();
};

typedef void (__thiscall *StringConstructor)(String *, const char *);
typedef void (__thiscall *StringDestructor)(String *);
typedef String (__cdecl *StringAppend)(const String &, const char *);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;
extern StringAppend stringAppend;

extern String __cdecl construct();
extern Sky __cdecl createSky(int, const String &, const String &,
                            int, double, int);

__forceinline String::String(const char *text)
{
    stringConstructor(this, text);
}

__forceinline String::~String()
{
    stringDestructor(this);
}

Sky __cdecl makeSky()
{
    String texture("null_plainsky512_*.jpg");
    return createSky(0, stringAppend(construct(), "Sky\\"),
                     texture, 1, 1.0, 1);
}

#pragma optimize("y", on)
