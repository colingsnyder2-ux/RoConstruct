// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Value {
    Vector3 get();
};

struct Setter {
    typedef void (__thiscall *SetFunction)(Setter*, void*, const Vector3&);
    SetFunction* table;
};

struct Descriptor {
    char padding[24];
    Setter* setter;

    void write(void* object, Value* value);
};

void Descriptor::write(void* object, Value* value)
{
    Setter* target = setter;
    Setter::SetFunction& set = target->table[3];
    set(target, object, value->get());
}
