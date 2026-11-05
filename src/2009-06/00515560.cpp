// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct String;
typedef void (__thiscall *DestroyStringFunction)(String *);
extern DestroyStringFunction destroyString;

struct String
{
    char storage[28];
    ~String();
};

inline String::~String()
{
    destroyString(this);
}

extern String __cdecl makeString(const char *);
extern void *__cdecl loadTexture(void *, const String &, bool);
extern void *__cdecl loadStrip(void *, const String &);

struct Reference
{
    void *value;
    Reference();
    ~Reference();
    void operator=(void *);
};

inline Reference::Reference() : value(0)
{
}

struct Material
{
    Reference strip;
    Reference surfaces;
    Reference john;
    Reference extra;

    Material(void *);
};

Material::Material(void *context)
{
    surfaces = loadTexture(context, makeString("textures\\surfaces.png"), true);
    strip = loadStrip(context, makeString("textures\\SurfacesStrip.png"));
}
