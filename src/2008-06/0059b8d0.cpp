// from server: 100% by king_originala
struct Color {
    float r, g, b;
};

struct Value {
    const Color* get(Color* temporary);
};

struct Accessor;

typedef void (__thiscall *Setter)(Accessor*, void*, const Color*);

struct AccessorTable {
    void* reserved[3];
    Setter set;
};

struct Accessor {
    AccessorTable* table;
};

struct S {
    unsigned char reserved[24];
    Accessor* accessor;
    void set(void* object, Value* value);
};

void S::set(void* object, Value* value)
{
    Color temporary;
    Accessor* target = accessor;
    Setter* slot = &target->table->set;
    const Color* color = value->get(&temporary);
    (*slot)(target, object, color);
}
