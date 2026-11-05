// from server: 14% by atomic.potato
typedef void *String;
typedef String (__cdecl *GetString)(void *, void *);

extern "C" void ConstructString(String *, const String *);

struct S
{
    void *a;
    void *b;
    GetString f(void *, String *);
};

GetString S::f(void *x, String *y)
{
    return (GetString)b;
}
