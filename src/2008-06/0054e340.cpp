// from server: 100% by king_originala
typedef void *(__thiscall *StringCopy)(void *, const void *);
extern StringCopy stringCopy;

struct Mesh {
    int value;
    unsigned char text[28];

    Mesh *f(const int *, const void *);
};

#pragma optimize("", off)
Mesh *Mesh::f(const int *source, const void *stringSource)
{
    value = *source;
    stringCopy(text, stringSource);
    return this;
}
#pragma optimize("", on)
