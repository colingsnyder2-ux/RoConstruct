// from server: 49% by atomic.potato
typedef int (__cdecl *StringConstructor)(void *, const char *);
extern StringConstructor g_StringConstructor;

struct S
{
    char flag;
    int value1;
    int value2;
    char stringObject[16];

    S();
};

S::S()
{
    g_StringConstructor(stringObject, "Authoring");
}
