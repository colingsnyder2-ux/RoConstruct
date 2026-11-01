// from server: 100% by king_originala
typedef void (__thiscall *Method)(void *, void *);

struct S {
    void *f(void *result);
};

void *S::f(void *result)
{
    void *object = reinterpret_cast<char *>(this) - 0x288;
    Method *table = *reinterpret_cast<Method **>(object);
    table[21](object, result);
    return result;
}
