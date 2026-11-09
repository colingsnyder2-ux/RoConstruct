// from server: 100% by king_originala
struct String;

extern String (__cdecl *concatLeft)(const char*, const String&);
extern String (__cdecl *concatRight)(const String&, const char*);
extern void (__thiscall *copyString)(String*, const String&);
extern void (__thiscall *destroyString)(String*);

struct String
{
    unsigned char data[28];

    String(const String&);
    ~String();
};

inline String::String(const String& other)
{
    copyString(this, other);
}

inline String::~String()
{
    destroyString(this);
}

struct Resource
{
    String name;
    unsigned int value;
};

Resource __cdecl loadResource(const String&);

struct S
{
    void set(unsigned int, const Resource&);
    void f(unsigned int, const String&);
};

void S::f(unsigned int id, const String& name)
{
    Resource resource = loadResource(concatRight(concatLeft("Textures\\", name), ".png"));
    set(id, Resource(resource));
}
