// from server: 100% by king_originala
struct String {
    char storage[28];
};

extern bool (__cdecl *stringEqual)(const String&, const char*);

struct Primitive {
    void setSizeMultiplier(unsigned int value);
};

struct S {
    char padding[0x228];
    Primitive primitive;

    void setValue(const String&);
    void setName(const String&);
};

void S::setName(const String& name)
{
    setValue(name);
    if (stringEqual(name, "Torso"))
        primitive.setSizeMultiplier(5);
    else
        primitive.setSizeMultiplier(1);
}
