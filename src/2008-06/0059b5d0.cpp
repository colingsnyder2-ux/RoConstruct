// from server: 100% by king_originala
struct Color {
    float r, g, b;
};

struct Accessor;

struct AccessorTable {
    void* reserved[2];
    Color* (__thiscall *get)(Accessor*, Color*, void*);
};

struct Accessor {
    AccessorTable* table;
};

struct Holder {
    void* value;
    void assign(const Color* color);
};

struct Result {
    void* type;
    Holder holder;
};

extern void* __cdecl getColorType();

struct S {
    unsigned char reserved[24];
    Accessor* accessor;
    void get(void* object, Result* result);
};

void S::get(void* object, Result* result)
{
    Color temporary;
    const Color* color = accessor->table->get(accessor, &temporary, object);
    result->type = getColorType();
    result->holder.assign(color);
}
