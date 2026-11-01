// from server: 100% by king_originala
struct Str_00437ed0 {
    int words[8];
};

extern bool (__thiscall* query)(Str_00437ed0*);
extern void (__thiscall* destroy)(Str_00437ed0*);

struct X_00437ed0 {
    char pad[0xa4];
    Str_00437ed0 value;
    Str_00437ed0* copy(Str_00437ed0* out);
    bool f();
};

bool X_00437ed0::f()
{
    int storage;
    bool result = query(copy(reinterpret_cast<Str_00437ed0*>(&storage)));
    destroy(reinterpret_cast<Str_00437ed0*>(&storage));
    return result;
}
