// from server: 100% by king_originala
struct String
{
    unsigned char storage[28];
};

typedef int (__thiscall *StringCompare)(const String *, const String &);
extern StringCompare stringCompare;

struct Name
{
    unsigned int value;
    String text;
    static int isLocal(const Name *);
};

extern const Name & __cdecl getLocalScope();

__forceinline int Name::isLocal(const Name *p)
{
    if (!p || p == &getLocalScope())
        return 1;
    return 0;
}

int __cdecl compareNames(const Name *left, const Name *right)
{
    if (Name::isLocal(left))
        return int(bool((unsigned char)Name::isLocal(right))) - 1;

    if (Name::isLocal(right))
        return int(!bool((unsigned char)Name::isLocal(left)));

    if (left == right)
        return 0;

    return stringCompare(&left->text, right->text);
}
