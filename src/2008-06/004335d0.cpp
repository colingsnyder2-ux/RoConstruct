// from server: 100% by king_originala
// from server: 93% by colin
#include <string.h>

struct String
{
    typedef const char* (__thiscall *CStr)(const String*);
    static CStr c_str;
};

struct Object
{
    unsigned char unknown[4];
    String name;
};

struct Item
{
    unsigned char unknown[4];
    Object* object;
};

extern int __stdcall G1_impl(const Item*);
extern int __stdcall G1_check(const Item*);

static __declspec(noinline) int G1(const Item* item)
{
    if (G1_check(item))
        return 0;
    return G1_impl(item);
}

int __stdcall func_004335d0(const Item* volatile input, const Item* second, long)
{
    const Item* first=input;
    int a = G1(first);
    int b = G1(second);

    if (a != b)
        return a - b;

    Object* object = second->object;
    const char* secondName = String::c_str(&object->name);
    return strcmp(String::c_str(&first->object->name), secondName);
}