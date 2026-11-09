// from server: 93% by king_originala
typedef void (__thiscall *Call1)(void *, unsigned);
typedef void (__thiscall *Call0)(void *);
typedef void (__thiscall *Call3)(void *, unsigned, unsigned, unsigned);

struct Object {
    Call1 *table;
};

struct S {
    Call1 *table;
    unsigned char padding[48];
    Object *object;

    void f(unsigned a, unsigned b, unsigned c, unsigned d,
           unsigned e, unsigned g, bool enabled);
};

void S::f(unsigned a, unsigned b, unsigned c, unsigned d,
          unsigned e, unsigned g, bool enabled)
{
    object->table[23](object, c);
    object->table[24](object, d);
    object->table[26](object, e);
    object->table[27](object, g);

    if (enabled)
        reinterpret_cast<Call0>(object->table[49])(object);

    reinterpret_cast<Call3>(table[224])(this, b, 0, 1);
    object->table[79](object, a);

    if (enabled)
        reinterpret_cast<Call0>(object->table[50])(object);
}
